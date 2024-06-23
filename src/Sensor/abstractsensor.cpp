#include "abstractsensor.h"
#include "../Container/container.h"
#include "src/Sensor/fuellevel.h"
#include "src/Sensor/humidity.h"
#include "src/Sensor/oilpressure.h"
#include "src/Sensor/temperature.h"
#include "src/Sensor/speed.h"
#include <QErrorMessage>

AbstractSensor::AbstractSensor(const string &n, const string &d, const int &m, const int &ma)
    : name(n), description(d), min(m), max(ma){};

AbstractSensor::~AbstractSensor()
{
}

void AbstractSensor::setname(const string &newName)
{
    this->name = newName;
}

void AbstractSensor::setdesc(const string &newDesc)
{
    this->description = newDesc;
}

void AbstractSensor::setmax(const unsigned int &newMax)
{
    this->max = newMax;
}

void AbstractSensor::setmin(const unsigned int &newMin)
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

bool order(const DataType<unsigned int> &a, const DataType<unsigned int> &b)
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
