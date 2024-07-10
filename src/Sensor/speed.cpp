#include "speed.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

VehicleSpeed::VehicleSpeed(const string &n, const string &d, const int &min, const int &max) : AbstractSensor::AbstractSensor(n, d, min, max)
{
};

bool VehicleSpeed::simulation()
{
    values.clear();

    const int minValue = getmin(); // 0
    const int maxValue = getmax(); // 220

    int currentValue = minValue; // parto da 0
    values.push_back(currentValue);

    bool testFailed = false;

    for (int i = 0; i < 70; i++)
    {


        if (rand() % 500 == 0) // simulazione valore difettoso con una probabilità bassa (1 su 500)
        {
            DataType<int> temp(i, -1);  // velocità occasionalmente non registrata
            values.push_back(temp);
            testFailed = true;
        }

        int decision = rand() % 2; // il valore aumenta o resta costante

        if (decision == 1) // velocità aumenta
        {
            int increase = rand() % (maxValue / 20 - maxValue / 100 + 1) + maxValue / 100;  // calcolo che aumenta la velocità dall'1% al 5% della velocità max.

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

    return !testFailed;
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
