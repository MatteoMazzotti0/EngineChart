#include "temperature.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

TempSensor::TempSensor(const string &n, const string &d, const int &min, const int &max) : AbstractSensor::AbstractSensor(n, d, min, max)
{
}

bool TempSensor::simulation()
{
    values.clear();

    const int minTemperature = getmin(); // -10
    const int maxTemperature = getmax(); // 120

    int currentValue = minTemperature + rand() % 10; // parte da temperature ambiente varie

    bool reachedSpot = false;       // check per quando il motore raggiunge la temperatura ideale
    const int spotTemperature = maxTemperature * 0.75; // temperatura da raggiungere ~75% del massimo

    DataType<int> temp(0, currentValue);
    values.push_back(temp);


    //  Simulazione sensore non funzionante
    // -------------------------------------

    if (rand() % 10 == 0)   // in 1 simulazione ogni 10 la temperatura aumenta e basta
    {
        for(int i = 1; i < 70; i++)
        {
            int increase = rand() % 7 + 10;
            int newValue = currentValue + increase;

            DataType<int> temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;

            if(currentValue > maxTemperature)
            {
                return false;
            }
        }
    }

    //    Simulazione sensore normale
    // ---------------------------------

    for (int i = 1; i < 69; i++)
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

    return true;
}

void TempSensor::checkValues()
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
