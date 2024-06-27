#include "temperature.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

TempSensor::TempSensor(const string &n, const string &d) : AbstractSensor(n, d, -10, 120)
{
}

int TempSensor::countValues() const
{
    int counter = 0;
    for (auto it = values.begin(); it != values.end(); it++)
    {
        counter++;
    }
    return counter;
}

DataType<int> TempSensor::getValueAt(const int &pos) const
{
    return values[pos];
}

void TempSensor::deleteVal(const int &time, const int &val)
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

void TempSensor::deleteAllValues()
{
    values.clear();
}

bool TempSensor::insertNewVal(const int &time, const int &val)
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

void TempSensor::simulation()
{
    values.clear();

    const int minTemperature = getmin(); // -10
    const int maxTemperature = getmax(); // 120

    int currentValue = rand() % 20 -10 ; // parte da temperature ambiente varie

    bool reachedSpot = false;                // check per quando il motore raggiunge la temperatura ideale
    const int spotTemperature = 90; // temperatura da raggiungere

    for (int i = 0; i < 70; i++)
    {
        if (!reachedSpot) // aumento progressivamente i valori fino a raggiugnere lo spot
        {
            int increase = rand() % 7 + 10;
            int newValue = currentValue + increase;

            if (newValue >= spotTemperature)
            {
                reachedSpot = true;
                newValue = spotTemperature;
            }

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }

        else // una volta raggiunto lo spot riduco la variazione al minimo
        {

            int variation = rand() % 3 - 1; // Variazione casuale tra -1 e +1

            int tempValue = static_cast<int>(currentValue) + variation; // devo fare un check sull cast perchè sia safe

            // check che il valore sia nel range
            int newValue = tempValue < static_cast<int>(minTemperature) ? minTemperature
                                    : tempValue > static_cast<int>(maxTemperature)
                                        ? maxTemperature
                                        : static_cast<int>(tempValue);

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }
    }
}

void TempSensor::accept(SensorVisitor *visitor) const
{
    return visitor->visit(this);
}

void TempSensor::setButton(SensorVisitor *visitor) const
{
    return visitor->setButtonFor(this);
}

void TempSensor::setUnitMeasure(SensorVisitor *visitor) const
{
    return visitor->setUnitMeasure(this);
}
