#include "oilpressure.h"
#include "../Visitor/sensorvisitor.h"

int OilPressure::countValues() const
{
    int counter = 0;
    for (auto it = values.begin(); it != values.end(); it++)
    {
        counter++;
    }
    return counter;
}

DataType<int> OilPressure::getValueAt(const int &pos) const
{
    return values[pos];
}

void OilPressure::deleteVal(const int &time, const int &val)
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

void OilPressure::deleteAllValues()
{
    values.clear();
}

bool OilPressure::insertNewVal(const int &time, const int &val)
{
    for (auto it = values.begin(); it != values.end(); it++)
    {
        if (it->time() == time)
        {
            return false;
        }
    }

    values.push_back(DataType<int>(time, val));
    sort(values.begin(), values.end(), order);

    return true;
}

OilPressure::OilPressure(const string &n, const string &d)
    : AbstractSensor::AbstractSensor(n, d, 10, 90)
{
}

void OilPressure::simulation()
{
    values.clear();

    const int minValue = getmin(); // 10
    const int maxValue = getmax(); // 90

    int currentValue = maxValue;

    bool reachedSpot = false; // check per quando l'olio raggiunge una certa pressione
    const int spotPressure = 50; // pressione da raggiungere

    for (int i = 0; i < 70; i++)
    {
        if (!reachedSpot) // diminuisco progressivamente i valori fino allo spot
        {
            int increase = rand() % 5 + 2;
            int newValue = currentValue - increase;

            if (newValue <= spotPressure)
            {
                reachedSpot = true;
                newValue = spotPressure;
            }

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }

        else // una volta raggiunto lo spot riduco la variazione al minimo
        {

            int variation = rand() % 2; // Variazione casuale tra 0 e 1

            int tempValue = static_cast<int>(currentValue) - variation; // devo fare un check sull cast perchè sia safe

            // check che il valore sia nel range
            int newValue = tempValue < static_cast<int>(minValue) ? minValue :
                                        tempValue > static_cast<int>(maxValue) ? maxValue :
                                        static_cast<int>(tempValue);

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }
    }
}


void OilPressure::accept(SensorVisitor *visitor) const
{
    return visitor->visit(this);
}

void OilPressure::setButton(SensorVisitor *visitor) const
{
    return visitor->setButtonFor(this);
}

void OilPressure::setUnitMeasure(SensorVisitor *visitor) const
{
    return visitor->setUnitMeasure(this);
}
