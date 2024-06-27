#ifndef DATATYPE_H
#define DATATYPE_H

template <typename T> class DataType
{
  private:
    int timestamp;
    T val;

  public:
    DataType(int = 0, T = 0);
    int time() const;
    T value() const;
};

#endif
