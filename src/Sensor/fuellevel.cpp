#include "fuellevel.h"
#include "../Visitor/sensorvisitor.h"



FuelLevel::FuelLevel(const string &n, const string &d, const int &min, const int &max) : AbstractSensor::AbstractSensor(n, d, min, max)
{
};

FuelLevel::~FuelLevel()
{
}

bool FuelLevel::simulation()
{
    values.clear();

    const int minValue = getmin(); // 0;
    const int maxValue = getmax(); // 90; litri serbatoio

    const int minStartValue = 0.8 * maxValue; // 80% di maxValue come inizio
    int lastValue = rand() % (maxValue - minStartValue + 1) + minStartValue; // parte tra l'80% e il 100% del serbatoio

    const int fraction = 50;
    const int maxVariation = maxValue / fraction;   // variazione in funzione del massimo

    for (int i = 0; i < 100; i++)
    {
        int variation = rand() % (maxVariation + 1); // variazione casuale tra 0 e maxVariation


        if (rand() % 700 == 0) // simulazione valore difettoso con una probabilità molto bassa (1 su 1000)
        {
            DataType<int> temp(i, -1);
            values.push_back(temp);
            return false;
        }


        int tempValue = lastValue - variation;

        // check che il valore sia nel range
        int newValue = tempValue < static_cast<int>(minValue) ? minValue :
                           tempValue > static_cast<int>(maxValue) ? maxValue :
                           static_cast<int>(tempValue);

        DataType<int> temp(i, newValue);
        values.push_back(temp);

        if(newValue == minValue)
        {
            return true;
        }

        lastValue = newValue;
    }
    return true;
}

void FuelLevel::checkValues()
{

    for (auto it = values.begin(); it != values.end(); it++)
    {
        if(it->value() > getmax() || it->value() < getmin())
        {
            setcorrectvalues(false); // trovato valore difettoso
            return;
        }
    }
    setcorrectvalues(true);

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

