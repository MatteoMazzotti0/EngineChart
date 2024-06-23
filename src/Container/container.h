#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
using std::string;
using std::vector;
class AbstractSensor;
class SearchAddWidget;
class Container
{

  private:
    static vector<AbstractSensor *> sensors;

  public:
    static const vector<AbstractSensor*>& getSensors();
    static void setSensors(const vector<AbstractSensor*>& newSensors);
    static void deleteAll();
    bool add(AbstractSensor *);
    bool check(const string&, const string&) const;
    static void remove(AbstractSensor *);
    AbstractSensor* search(const string&) const;
    void modify(AbstractSensor *, const string&, const string&, const int&, const int&);
};

#endif
