#ifndef FUELLEVEL_H
#define FUELLEVEL_H
#include "../DataType/datatype.h"
#include "../Sensor/abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class FuelLevel : public AbstractSensor
{
  private:
    vector<DataType<unsigned int>> values;

  public:
    FuelLevel(const string & = "", const string & = "");
    virtual int countValues() const override;
    virtual DataType<unsigned int> getValueAt(const int &) const override;
    virtual bool insertNewVal(const double &, const double &) override;
    virtual void deleteVal(const unsigned int &, const unsigned int &) override;
    virtual void deleteAllValues() override;
    virtual ~FuelLevel();
    virtual void simulation() override;
    virtual void accept(SensorVisitor *visitor) const override;
    virtual void setButton(SensorVisitor *visitor) const override;
    virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};

#endif
