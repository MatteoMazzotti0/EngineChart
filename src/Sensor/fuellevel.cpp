#include "fuellevel.h"
#include "../Visitor/sensorvisitor.h"

int FuelLevel::countValues() const
{
    int counter = 0;
    for (auto it = values.begin(); it != values.end(); it++)
    {
        counter++;
    }
    return counter;
}

bool FuelLevel::insertNewVal(const double &time, const double &val)
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

void FuelLevel::deleteVal(const unsigned int &time, const unsigned int &val)
{
    if (values.size() == 1)
    {
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

void FuelLevel::deleteAllValues()
{
    values.clear();
}

DataType<unsigned int> FuelLevel::getValueAt(const int &pos) const
{
    return values[pos];
}

FuelLevel::FuelLevel(const string &n, const string &d)
    : AbstractSensor::AbstractSensor(n, d, 0, 90){

      };

FuelLevel::~FuelLevel()
{
}

void FuelLevel::simulation()
{
    values.clear();

    const unsigned int minValue = getmin(); // 0;
    const unsigned int maxValue = getmax(); // 90; litri serbatoio

  unsigned int lastValue = rand() % (maxValue - 80 + 1) + 80; // parte con serbatoio più o meno pieno

    for (unsigned int i = 0; i < 100; i++)
    {
        unsigned int variation = rand() % 2; // Variazione casuale tra 0 e +1

        int tempValue = static_cast<int>(lastValue) - variation; // devo fare un check sull cast perchè sia safe

        // check che il valore sia nel range
        unsigned int newValue = tempValue < static_cast<int>(minValue) ? minValue :
                                    tempValue > static_cast<int>(maxValue) ? maxValue :
                                    static_cast<unsigned int>(tempValue);

        DataType temp(i, newValue);
        values.push_back(temp);

        lastValue = newValue;
    }
}

void FuelLevel::accept(SensorVisitor *visitor) const
{
    return visitor->visit(this);
}

void FuelLevel::setButton(SensorVisitor *visitor) const
{
    return visitor->setButtonFor(this);
}
