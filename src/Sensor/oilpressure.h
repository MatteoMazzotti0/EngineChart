#ifndef OILPRESSURE_H
#define OILPRESSURE_H
#include "../DataType/datatype.h"
#include "abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class OilPressure : public AbstractSensor
{
public:
  OilPressure(const string & = "", const string & = "", const int & = 10, const int & = 90);
  virtual ~OilPressure() = default;
  virtual bool simulation() override;
  virtual void accept(SensorVisitor *visitor) const override;
  virtual void setButton(SensorVisitor *visitor) const override;
  virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};
#endif
