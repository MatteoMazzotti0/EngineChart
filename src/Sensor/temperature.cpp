#include "temperature.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

TempSensor::TempSensor(const string &n, const string &d) : AbstractSensor(n, d, 0, 100)
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

DataType<unsigned int> TempSensor::getValueAt(const int &pos) const
{
    return values[pos];
}

void TempSensor::deleteVal(const unsigned int &time, const unsigned int &val)
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

bool TempSensor::insertNewVal(const double &time, const double &val)
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

void TempSensor::simulation()
{
    values.clear();

    const unsigned int minTemperature = 0;
    const unsigned int maxTemperature = 120;

    unsigned int currentValue = minTemperature;

    bool reachedSpot = false; // check per quando il motore raggiunge la temperatura ideale
    const unsigned int spotTemperature = 90; // temperatura da raggiungere

    for (unsigned int i = 0; i < 70; i++)
    {
        if (!reachedSpot) // aumento progressivamente i valori fino a raggiugnere lo spot
        {
            unsigned int increase = rand() % 7 + 2; // studi scientifici hanno approvato questi valori per una salita iniziale estetica
            unsigned int newValue = currentValue + increase;

            if (newValue >= spotTemperature)
            {
                reachedSpot = true;
                newValue = spotTemperature;
            }

            DataType temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }

        else // una volta raggiunto lo spot riduco la variazione al minimo
        {

            unsigned int variation = rand() % 3 - 1; // Variazione casuale tra -1 e +1

            int tempValue = static_cast<int>(currentValue) + variation; // devo fare un check sull cast perchè sia safe

            // check che il valore sia nel range
            unsigned int newValue = tempValue < static_cast<int>(minTemperature) ? minTemperature :
                                    tempValue > static_cast<int>(maxTemperature) ? maxTemperature :
                                                static_cast<unsigned int>(tempValue);

            DataType temp(i, newValue);
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
