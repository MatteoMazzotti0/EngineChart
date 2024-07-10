#ifndef FUELLEVEL_H
#define FUELLEVEL_H
#include "../DataType/datatype.h"
#include "../Sensor/abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class FuelLevel : public AbstractSensor
{

public:
  FuelLevel(const string & = "", const string & = "", const int & = 0, const int & = 90);
  virtual ~FuelLevel();
  virtual void simulation() override;
  virtual void accept(SensorVisitor *visitor) const override;
  virtual void setButton(SensorVisitor *visitor) const override;
  virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};

#endif
