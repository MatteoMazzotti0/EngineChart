#include "speed.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

VehicleSpeed::VehicleSpeed(const string &n, const string &d) : AbstractSensor(n, d, 0, 220)
{
}

void VehicleSpeed::simulation()
{
    values.clear();

    const int minValue = getmin(); // 0
    const int maxValue = getmax(); // 220

    int currentValue = minValue; // parto da 0
    values.push_back(currentValue);

    for (int i = 0; i < 70; i++)
    {
        int decision = rand() % 2; // il valore aumenta o resta costante

        if (decision == 1) // velocità aumenta
        {
            int increase = rand() % 10 + 1; // aumento casuale tra 1 e 10

            int newValue = currentValue + increase;

            // check valore nel range
            if (newValue > maxValue)
                newValue = maxValue;

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }
        else // velocità costante
        {
            DataType<int> temp(i, currentValue);
            values.push_back(temp);
        }
    }
}

void VehicleSpeed::accept(SensorVisitor *visitor) const
{
    return visitor->visit(this);
}

void VehicleSpeed::setButton(SensorVisitor *visitor) const
{
    return visitor->setButtonFor(this);
}

void VehicleSpeed::setUnitMeasure(SensorVisitor *visitor) const
{
    return visitor->setUnitMeasure(this);
}
