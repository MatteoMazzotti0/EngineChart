#ifndef SENSORVISITOR_H
#define SENSORVISITOR_H

#include "src/Sensor/fuellevel.h"
#include "src/Sensor/humidity.h"
#include "src/Sensor/oilpressure.h"
#include "src/Sensor/speed.h"
#include "src/Sensor/temperature.h"
#include <QPushButton>
#include <QWidget>

class SensorVisitor
{

  public:
    SensorVisitor();
    virtual ~SensorVisitor();

    virtual void visit(const HumiditySensor *sensor) = 0;
    virtual void visit(const TempSensor *sensor) = 0;
    virtual void visit(const OilPressure *sensor) = 0;
    virtual void visit(const FuelLevel *sensor) = 0;
    virtual void visit(const VehicleSpeed *sensor) = 0;

    virtual void setButtonFor(const HumiditySensor *sensor) = 0;
    virtual void setButtonFor(const TempSensor *sensor) = 0;
    virtual void setButtonFor(const OilPressure *sensor) = 0;
    virtual void setButtonFor(const FuelLevel *sensor) = 0;
    virtual void setButtonFor(const VehicleSpeed *sensor) = 0;

    virtual void setUnitMeasure(const HumiditySensor *sensor) = 0;
    virtual void setUnitMeasure(const TempSensor *sensor) = 0;
    virtual void setUnitMeasure(const OilPressure *sensor) = 0;
    virtual void setUnitMeasure(const FuelLevel *sensor) = 0;
    virtual void setUnitMeasure(const VehicleSpeed *sensor) = 0;

    virtual QPushButton *getButton() const = 0;
    virtual string getType() const = 0;
    virtual string getUnitOfMeasure() const = 0;
};

#endif // SENSORVISITOR_H
