#include "fuellevel.h"
#include "../Visitor/sensorvisitor.h"



FuelLevel::FuelLevel(const string &n, const string &d)
    : AbstractSensor::AbstractSensor(n, d, 0, 90){

      };

FuelLevel::~FuelLevel()
{
}

void FuelLevel::simulation()
{
    values.clear();

    const int minValue = getmin(); // 0;
    const int maxValue = getmax(); // 90; litri serbatoio

  int lastValue = rand() % (maxValue - 80 + 1) + 80; // parte con serbatoio più o meno pieno

    for (int i = 0; i < 100; i++)
    {
        int variation = rand() % 2; // Variazione casuale tra 0 e +1

        int tempValue = static_cast<int>(lastValue) - variation; // devo fare un check sull cast perchè sia safe

        // check che il valore sia nel range
        int newValue = tempValue < static_cast<int>(minValue) ? minValue :
                                    tempValue > static_cast<int>(maxValue) ? maxValue :
                                    static_cast<int>(tempValue);

        DataType<int> temp(i, newValue);
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

void FuelLevel::setUnitMeasure(SensorVisitor *visitor) const
{
    return visitor->setUnitMeasure(this);
}

