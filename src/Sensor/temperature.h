
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "../DataType/datatype.h"
#include "abstractsensor.h"

class SensorVisitor;

class TempSensor : public AbstractSensor
{
  private:
    vector<DataType<int>> values; // °C

  public:
    TempSensor(const string & = "", const string & = "");
    virtual int countValues() const override;
    virtual DataType<int> getValueAt(const int &) const override;
    virtual bool insertNewVal(const int &, const int &) override;
    virtual void deleteVal(const int &, const int &) override;
    virtual void deleteAllValues() override;
    virtual ~TempSensor() = default;
    void simulation() override;
    virtual void accept(SensorVisitor *visitor) const override;
    virtual void setButton(SensorVisitor *visitor) const override;
    virtual void setUnitMeasure(SensorVisitor *visitor) const override;
};
#endif
