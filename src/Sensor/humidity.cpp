#include "humidity.h"
#include "../Visitor/sensorvisitor.h"

HumiditySensor::HumiditySensor(const string &n, const string &d, const int &min, const int &max) : AbstractSensor::AbstractSensor(n, d, min, max)
{
}

HumiditySensor::~HumiditySensor()
{
}

bool HumiditySensor::simulation()
{
    values.clear();

    const int minValue = getmin(); // 20
    const int maxValue = getmax(); // 80
    const int maxStep = (maxValue - minValue) / 10; // variazione per step in base al divario tra umidità massima e minima

    int lastValue = rand() % (maxValue - minValue + 1) + minValue; // valore iniziale casuale nel range

    for (int i = 0; i < 100; i++)
    {
        if (rand() % 500 == 0)  // 1 valore su 500 sarà difettoso
        {
            if (rand() % 2 == 0)
            {
                DataType<int> temp(i, -1); // valore fuori dal range per indicare errore
                values.push_back(temp);
            }
            else
            {
                DataType<int> temp(i, 1000); // altro valore fuori dal range per indicare errore
                values.push_back(temp);
            }
            return false;
        }

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

    return true;
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
