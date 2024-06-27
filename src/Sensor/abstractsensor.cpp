#include "abstractsensor.h"
#include "../Container/container.h"
#include "src/Sensor/AbstractSensor.h"
#include "src/Sensor/humidity.h"
#include "src/Sensor/oilpressure.h"
#include "src/Sensor/temperature.h"
#include "src/Sensor/speed.h"

AbstractSensor::AbstractSensor(const string &n, const string &d, const int &m, const int &ma)
    : name(n), description(d), min(m), max(ma){};

AbstractSensor::~AbstractSensor()
{
}

int AbstractSensor::countValues() const
{
    int counter = 0;
    for (auto it = values.begin(); it != values.end(); it++)
    {
        counter++;
    }
    return counter;
}

bool AbstractSensor::insertNewVal(const int &time, const int &val)
{
    for (auto it = values.begin(); it != values.end(); it++)
    {
        if (it->time() == time)
        {
            return false;
        }
    }

    values.push_back(DataType<int>(time, val));
    sort(values.begin(), values.end(), order);

    return true;
}

void AbstractSensor::deleteVal(const int &time, const int &val)
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
                return;
            }
        }
    }
}

void AbstractSensor::deleteAllValues()
{
    values.clear();
}

DataType<int> AbstractSensor::getValueAt(const int &pos) const
{
    return values[pos];
}

void AbstractSensor::setname(const string &newName)
{
    this->name = newName;
}

void AbstractSensor::setdesc(const string &newDesc)
{
    this->description = newDesc;
}

void AbstractSensor::setmax(const int &newMax)
{
    this->max = newMax;
}

void AbstractSensor::setmin(const int &newMin)
{
    this->min = newMin;
}

string AbstractSensor::getdesc() const
{
    return description;
}

string AbstractSensor::getname() const
{
    return name;
}

int AbstractSensor::getmax() const
{
    return max;
}

int AbstractSensor::getmin() const
{
    return min;
}

bool order(const DataType<int> &a, const DataType<int> &b)
{
    if (a.time() < b.time())
    {
        return true;
    }
    else
    {
        return false;
    }
}
