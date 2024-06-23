#include "datatype.h"

template <typename T> DataType<T>::DataType(unsigned int t, T v) : val(v)
{
    timestamp = t;
}

template <typename T> unsigned int DataType<T>::time() const
{
    return timestamp;
}

template <typename T> T DataType<T>::value() const
{
    return val;
}


template class DataType<unsigned int>;
template class DataType<int>;
