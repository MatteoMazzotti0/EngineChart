#ifndef OILPRESSURE_H
#define OILPRESSURE_H
#include "../DataType/datatype.h"
#include "abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class OilPressure : public AbstractSensor
{
private:
  vector<DataType<int>> values;

public:
  OilPressure(const string & = "", const string & = "");
  virtual ~OilPressure() = default;
  virtual void simulation() override;
  virtual void accept(SensorVisitor *visitor) const override;
  virtual void setButton(SensorVisitor *visitor) const override;
  virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};
#endif
