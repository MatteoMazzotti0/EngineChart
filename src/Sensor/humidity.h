#ifndef HUMIDITY_H
#define HUMIDITY_H
#include "../DataType/datatype.h"
#include "abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class HumiditySensor : public AbstractSensor
{
public:
  HumiditySensor(const string & = "", const string & = "", const int & = 20, const int & = 80);
  virtual ~HumiditySensor();
  virtual void simulation() override;
  virtual void accept(SensorVisitor *visitor) const override;
  virtual void setButton(SensorVisitor *visitor) const override;
  virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};
#endif
