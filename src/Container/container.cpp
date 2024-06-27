#include "container.h"
#include <QErrorMessage>
#include "../Sensor/abstractsensor.h"

vector<AbstractSensor *> Container::sensors;

const std::vector<AbstractSensor *> &Container::getSensors()
{
    return sensors;
}

void Container::setSensors(const std::vector<AbstractSensor *> &newSensors)
{
    deleteAll();
    sensors = newSensors;
}

void Container::deleteAll()
{
    for (auto it = Container::sensors.begin(); it != Container::sensors.end(); it++)
    {
        delete *it;
    }
    Container::sensors.clear();
}

bool Container::add(AbstractSensor *NewSensor)
{
    bool found = false;
    for (auto it = Container::sensors.begin(); it != Container::sensors.end(); it++)
    {
        if ((*it)->getname() == NewSensor->getname())
        {
            found = true;
        }
    }

    if (found == false)
    {
        Container::sensors.push_back(NewSensor);
    }
    return !found;
}

bool Container::check(const string &newSensorName, const string &oldSensorName) const
{
    for (const auto &sensor : Container::sensors)
    {
        if (sensor->getname() == newSensorName && sensor->getname() != oldSensorName)
        {
            return false;
        }
    }
    return true;
}

void Container::remove(AbstractSensor *Target)
{
    for (auto it = sensors.begin(); it != sensors.end() && found == false; it++)
    {
        if (Target->getname() == (*it)->getname())
        {
            sensors.erase(it);
        }
    }
}

void Container::modify(AbstractSensor *Target, const string &newname, const string &newdescription, const int &newmin, const int &newmax)
{
    for (auto it = sensors.begin(); it != sensors.end(); it++)
    {
        if (Target->getname() == (*it)->getname())
        {
            (*it)->setname(newname);
            (*it)->setdesc(newdescription);
            (*it)->setmax(newmax);
            (*it)->setmin(newmin);
        }
    }
}

AbstractSensor *Container::search(const string &name) const
{
    for (auto it = sensors.begin(); it != sensors.end(); it++)
    {
        if (name == (*it)->getname())
        {
            return *it;
        }
    }
    return nullptr;
}
