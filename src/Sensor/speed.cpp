#include "speed.h"
#include "../Visitor/sensorvisitor.h"
#include <cstdlib>

VehicleSpeed::VehicleSpeed(const string &n, const string &d) : AbstractSensor(n, d, 0, 220)
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
    values.clear();

    const unsigned int minValue = getmin(); // 0
    const unsigned int maxValue = getmax(); // 220

    unsigned int currentValue = minValue;   // parto da 0
    values.push_back(currentValue);

    for (unsigned int i = 0; i < 70; i++)
    {
        int decision = rand() % 2; // il valore aumenta o resta costante

        if (decision == 1) // velocità aumenta
        {
            unsigned int increase = rand() % 10 + 1; // aumento casuale tra 1 e 10

            unsigned int newValue = currentValue + increase;

            // check valore nel range
            if (newValue > maxValue)
                newValue = maxValue;

            DataType temp(i, newValue);
            values.push_back(temp);

            currentValue = newValue;
        }
        else // velocità costante
        {
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

void VehicleSpeed::setUnitMeasure(SensorVisitor *visitor) const
{
    return visitor->setUnitMeasure(this);
}
