#include "datatype.h"

template <typename T> DataType<T>::DataType(int t, T v) : val(v)
{
    timestamp = t;
}

template <typename T> int DataType<T>::time() const
{
    return timestamp;
}

template <typename T> T DataType<T>::value() const
{
    return val;
}

template class DataType<int>;
