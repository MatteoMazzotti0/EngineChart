#include "temperature.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

TempSensor::TempSensor(const string &n, const string &d, const int &min, const int &max) : AbstractSensor::AbstractSensor(n, d, min, max)
{
}

void TempSensor::simulation()
{
    values.clear();

    const int minTemperature = getmin(); // -10
    const int maxTemperature = getmax(); // 120

    int currentValue = rand() % 20 - 10; // parte da temperature ambiente varie

    bool reachedSpot = false;       // check per quando il motore raggiunge la temperatura ideale
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

            int tempValue = static_cast<int>(currentValue) + variation;

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
