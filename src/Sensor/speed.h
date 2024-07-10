#ifndef VEHICLESPEED_H
#define VEHICLESPEED_H

#include "../DataType/datatype.h"
#include "abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class VehicleSpeed : public AbstractSensor
{
public:
  VehicleSpeed(const string & = "", const string & = "", const int & = 0, const int & = 220);
  virtual ~VehicleSpeed() = default;
  virtual bool simulation() override;
  virtual void accept(SensorVisitor *visitor) const override;
  virtual void setButton(SensorVisitor *visitor) const override;
  virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};
#endif
