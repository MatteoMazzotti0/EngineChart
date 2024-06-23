#ifndef CONCRETEVISITOR_H
#define CONCRETEVISITOR_H

#include "sensorvisitor.h"

class ConcreteVisitor : public SensorVisitor
{
  private:
    QPushButton *button;
    string type;

  public:
    ConcreteVisitor();
    virtual void visit(const HumiditySensor *sensor) override;
    virtual void visit(const TempSensor *sensor) override;
    virtual void visit(const OilPressure *sensor) override;
    virtual void visit(const FuelLevel *sensor) override;
    virtual void visit(const VehicleSpeed *sensor) override;

    virtual void setButtonFor(const TempSensor *sensor) override;
    virtual void setButtonFor(const HumiditySensor *sensor) override;
    virtual void setButtonFor(const OilPressure *sensor) override;
    virtual void setButtonFor(const FuelLevel *sensor) override;
    virtual void setButtonFor(const VehicleSpeed *sensor) override;

    virtual QPushButton *getButton() const override;
    virtual string getType() const override;
};

#endif // CONCRETEVISITOR_H
