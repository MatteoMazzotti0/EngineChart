#include "humidity.h"
#include "../Visitor/sensorvisitor.h"

HumiditySensor::HumiditySensor(const string &n, const string &d) : AbstractSensor::AbstractSensor(n, d, 20, 80)
{
}

HumiditySensor::~HumiditySensor()
{
}

void HumiditySensor::simulation()
{
    values.clear();

    const int minValue = getmin(); // 20
    const int maxValue = getmax(); // 80
    const int maxStep = 2;         // variazione per step

    int lastValue = rand() % (maxValue - minValue + 1) + minValue; // valore iniziale casuale nel range

    for (int i = 0; i < 100; i++)
    {
        // variazione creata con un range tra un rand e l'altro
        int change = (rand() % (2 * maxStep + 1)) - maxStep;
        int tempValue = static_cast<int>(lastValue) + change;

        // check che il valore nuovo sia nel range
        int newValue = tempValue < static_cast<int>(minValue) ? minValue : tempValue > static_cast<int>(maxValue) ? maxValue
                                                                                                                  : static_cast<int>(tempValue);

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

void HumiditySensor::setUnitMeasure(SensorVisitor *visitor) const
{
    return visitor->setUnitMeasure(this);
}
