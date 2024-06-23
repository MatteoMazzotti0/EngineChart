#ifndef DATATYPE_H
#define DATATYPE_H

template <typename T> class DataType
{
  private:
    unsigned int timestamp;
    T val;

  public:
    DataType(unsigned int = 0, T = 0);
    unsigned int time() const;
    T value() const;
};

#endif
