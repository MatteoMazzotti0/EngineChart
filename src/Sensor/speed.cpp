#include "speed.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

VehicleSpeed::VehicleSpeed(const string &n, const string &d, const int &m, const int &ma) : AbstractSensor(n, d, m, ma)
{
}

int VehicleSpeed::countValues() const
{
    int counter = 0;
    for (auto it = values.begin(); it != values.end(); it++)
    {
        counter++;
    }
    return counter;
}

DataType<unsigned int> VehicleSpeed::getValueAt(const int &pos) const
{
    return values[pos];
}

void VehicleSpeed::deleteVal(const unsigned int &time, const unsigned int &val)
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

void VehicleSpeed::deleteAllValues()
{
    values.clear();
}

bool VehicleSpeed::insertNewVal(const double &time, const double &val)
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

void VehicleSpeed::simulation()
{
    values.clear(); // Pulisce il vettore dei valori esistenti

    const unsigned int minValue = 0;  // Velocità minima
    const unsigned int maxValue = 100; // Velocità massima

    unsigned int currentValue = minValue; // Valore iniziale della velocità

    for (unsigned int i = 0; i < 25; i++)
    {
        // Decisione casuale: 0 significa mantenere costante, 1 significa aumentare
        int decision = rand() % 2;

        if (decision == 1)
        {
            // Aumento casuale della velocità
            unsigned int increase = rand() % 10 + 1; // Aumento casuale tra 1 e 10

            unsigned int newValue = currentValue + increase;

            // Assicurati che il nuovo valore sia nel range [minValue, maxValue]
            if (newValue > maxValue)
                newValue = maxValue;

            DataType temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue; // Aggiorna il valore corrente
        }
        else
        {
            // Mantieni la velocità costante
            DataType temp(i, currentValue);
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
