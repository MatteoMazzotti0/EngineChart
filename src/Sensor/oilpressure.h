#ifndef OILPRESSURE_H
#define OILPRESSURE_H
#include "../DataType/datatype.h"
#include "abstractsensor.h"
#include <algorithm>

class SensorVisitor;

class OilPressure : public AbstractSensor
{
  private:
    vector<DataType<unsigned int>> values;

  public:
    OilPressure(const string & = "", const string & = "", const int & = 0, const int & = 10);
    virtual int countValues() const override;
    virtual DataType<unsigned int> getValueAt(const int &) const override;
    virtual bool insertNewVal(const double &, const double &) override;
    virtual void deleteVal(const unsigned int &, const unsigned int &) override;
    virtual void deleteAllValues() override;
    virtual ~OilPressure() = default;
    void simulation() override;
    virtual void accept(SensorVisitor *visitor) const override;
    virtual void setButton(SensorVisitor *visitor) const override;
};
#endif
