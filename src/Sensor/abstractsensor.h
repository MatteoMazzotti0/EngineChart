#ifndef SENSOR_H
#define SENSOR_H
#include "../Container/container.h"
#include "../DataType/datatype.h"
#include <QWidget>
#include <string>
#include <vector>
using std::string;
using std::vector;

class SensorVisitor;

class AbstractSensor
{
private:
  string name;
  string description;
  int min;
  int max;

protected:
  vector<DataType<int>> values;

public:
  AbstractSensor(const string & = "", const string & = "", const int & = 0, const int & = 100);
  virtual ~AbstractSensor() = 0;
  virtual bool simulation() = 0;
  int countValues() const;
  // Modifica valori
  bool insertNewVal(const int &, const int &);
  void deleteVal(const int &, const int &);
  void deleteAllValues();
  // Setters
  void setname(const string &);
  void setdesc(const string &);
  void setmax(const int &);
  void setmin(const int &);
  // Getters
  virtual DataType<int> getValueAt(const int &) const;
  string getname() const;
  string getdesc() const;
  int getmin() const;
  int getmax() const;
  // Visitor
  virtual void accept(SensorVisitor *visitor) const = 0;
  virtual void setButton(SensorVisitor *visitor) const = 0;
  virtual void setUnitMeasure(SensorVisitor *visitor) const = 0;
};

bool order(const DataType<int> &a, const DataType<int> &b);

#endif
