
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "../DataType/datatype.h"
#include "abstractsensor.h"

class SensorVisitor;

class TempSensor : public AbstractSensor
{
public:
  TempSensor(const string & = "", const string & = "");
  virtual ~TempSensor() = default;
  void simulation() override;
  virtual void accept(SensorVisitor *visitor) const override;
  virtual void setButton(SensorVisitor *visitor) const override;
  virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};
#endif
