#include "humidity.h"
#include "../Visitor/sensorvisitor.h"

HumiditySensor::HumiditySensor(const string &n, const string &d) : AbstractSensor::AbstractSensor(n, d, 0, 100)
{
}

HumiditySensor::~HumiditySensor()
{
}

DataType<unsigned int> HumiditySensor::getValueAt(const int &pos) const
{
    return values[pos];
}

void HumiditySensor::deleteAllValues()
{
    values.clear();
}

void HumiditySensor::deleteVal(const unsigned int &time, const unsigned int &val)
{
    if (values.size() == 1)
    {
        values.pop_back();
        values.clear();
    }
    else
    {
        for (auto it = values.begin(); it != values.end(); it++)
        {
            if ((*it).time() == time && (*it).value() == val)
            {
                values.erase(it);
                values.shrink_to_fit();
                return;
            }
        }
    }
}

bool HumiditySensor::insertNewVal(const double &time, const double &val)
{
    for (auto it = values.begin(); it != values.end(); it++)
    {
        if (it->time() == time)
        {
            return false;
        }
    }

    values.push_back(DataType<unsigned int>(time, val));
    sort(values.begin(), values.end(), order);

    return true;
}

int HumiditySensor::countValues() const
{
    return values.size();
}

void HumiditySensor::simulation()
{
    values.clear();

    const unsigned int minValue = 20;
    const unsigned int maxValue = 80;
    const unsigned int maxStep = 2;  // variazione per step (ho tolto quegli spikes causali orrendi)

    unsigned int lastValue = rand() % (maxValue - minValue + 1) + minValue; // valore iniziale casuale nel range

    for (unsigned int i = 0; i < 100; i++)
    {
        // variazione creata con un range tra un rand e l'altro
        int change = (rand() % (2 * maxStep + 1)) - maxStep;
        int tempValue = static_cast<int>(lastValue) + change;

        //check che il valore nuovo sia nel range
        unsigned int newValue = tempValue < static_cast<int>(minValue) ? minValue :
                                tempValue > static_cast<int>(maxValue) ? maxValue :
                                            static_cast<unsigned int>(tempValue);
        // i cast sono stati fatti in sicurezza seguendo le buone pratiche del programmatore
        // e riducendo i possibili rischi al minimo grazie ai molteplici check in modo che Ranzato non ci linci👍

        DataType temp(i, newValue);
        values.push_back(temp);

        lastValue = newValue;
    }
}

void HumiditySensor::accept(SensorVisitor *visitor) const
{
    return visitor->visit(this);
}

void HumiditySensor::setButton(SensorVisitor *visitor) const
{
    return visitor->setButtonFor(this);
}
