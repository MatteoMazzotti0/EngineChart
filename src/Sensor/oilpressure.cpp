#include "oilpressure.h"
#include "../Visitor/sensorvisitor.h"

OilPressure::OilPressure(const string &n, const string &d, const int &min, const int &max) : AbstractSensor::AbstractSensor(n, d, min, max)
{
}

bool OilPressure::simulation()
{
    values.clear();

    const int minValue = getmin(); // 10
    const int maxValue = getmax(); // 90

    int currentValue = maxValue;

    bool reachedSpot = false;    // check per quando l'olio raggiunge una certa pressione
    const int spotPressure = 50; // pressione da raggiungere

    if(rand() % 10 == 0) // simulazione difettata 1 volta su 10
    {
        for (int i = 0; i < 70; i++)
        {
            int increase = rand() % 5 + 2;
            int newValue = currentValue - increase;

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;

            if(currentValue <= 0)
            {
                return false;
            }
        }
    }

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

            int tempValue = static_cast<int>(currentValue) - variation;

            // check che il valore sia nel range
            int newValue = tempValue < static_cast<int>(minValue) ? minValue : tempValue > static_cast<int>(maxValue) ? maxValue
                                                                                                                      : static_cast<int>(tempValue);

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }
    }

    return true;
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
