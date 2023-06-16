#include "IntVector.h"
#include "stdexcept"

IntVector::IntVector()
{
    _capacity = 0;
    _size = 0;
    _data = new int[0];
}

IntVector::IntVector(unsigned capacity)
{
    _capacity = capacity;
    _size = capacity;
    if(capacity != 0)
    {
        _data = new int[capacity];
        for(unsigned int i = 0; i < capacity; i++)
        {
            _data[i] = 0;
        }
    }
}

IntVector::IntVector(unsigned capacity, int value)
{
    _capacity = capacity;
    _size = capacity;
    if(capacity != 0)
    {
        _data = new int[capacity];
        for(unsigned int i = 0; i < capacity; i++)
        {
            _data[i] = value;
        }
    }
}

IntVector::~IntVector()
{
    delete[] _data;
}

unsigned IntVector::size() const
{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const
{
    if(_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int& IntVector::at(unsigned index) const
{
    if(index >= _size || _size == 0)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

const int& IntVector::front() const
{
    return _data[0];
}

const int& IntVector::back() const
{
    return _data[_size-1];
}