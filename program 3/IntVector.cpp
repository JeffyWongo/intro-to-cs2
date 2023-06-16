#include "IntVector.h"
#include "stdexcept"
#include <iostream>

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

void IntVector::expand()
{
    if(_capacity == 0)
    {
        int* tempdata = new int[1];
        delete[] _data;
        _data = tempdata;
        _capacity = 1;
        return;
    }
    _capacity *= 2;
    int* tempdata = new int[_capacity];
    for(unsigned int i = 0; i < _size; i++)
    {
        tempdata[i] = _data[i];
    }
    delete[] _data;
    _data = tempdata;
}

void IntVector::expand(unsigned amount) 
{
    _capacity += amount;
    int* tempdata = new int[_capacity];
    for(unsigned int i = 0; i < _size; i++)
    {
        tempdata[i] = _data[i];
    }
    delete[] _data;
    _data = tempdata;
}

int& IntVector::at(unsigned index)
{
    if(index >= _size || _size == 0)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int& IntVector::front()
{
    return _data[0];
}
int& IntVector::back()
{
    return _data[_size-1];
}

void IntVector::push_back(int value)
{
    if(_size == _capacity)
    {
        expand();
    }
    _size++;
    _data[_size-1] = value;
}

void IntVector::pop_back()
{
    _size--;
}

void IntVector::clear()
{
    _size = 0;
}

void IntVector::insert(unsigned index, int value)
{
    if(index > _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    if(_size == _capacity)
    {
        expand();
    }
    _size++;
    for (unsigned int i = _size-1; i > index; i--)
    {
        _data[i] = _data[i-1];
    }
    _data[index] = value;
}

void IntVector::erase(unsigned index)
{
    if(index >= _size || _size == 0)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    for(unsigned int i = index; i < _size-1; i++)
    {
        _data[i] = _data[i+1];
    } // test vector size 0, size 1, out of range bounds, erase 1 at beginning and at end
    _size--;
}

void IntVector::resize(unsigned size, int value) // parameter
{
    if(size < _size)
    {
        _size = size;
    }
    else if(size > _size && size < _capacity)
    {
        unsigned tempint = _size;
        _size = size;
        for(unsigned int i = tempint; i < size; i++)
        {
            _data[i] = value;
        }
    }
    else if(size >= _capacity)
    {
        if(_capacity == 0)
        {
            expand(size);
        }
        else if(size > (_capacity*2))
        {
            expand(size - _capacity);
        }
        else
        {
            expand();
        }
        unsigned tempint = _size;
        _size = size;
        for(unsigned int i = tempint; i < size; i++)
        {
            _data[i] = value;
        }
    }
}

void IntVector::reserve(unsigned n)
{
    if(n < _size)
    {
        return;
    }
    if(n > _capacity)
    {
        expand(n);
        _capacity = n;
    }
}

void IntVector::assign(unsigned n, int value) // (parameter)
{
    clear();
    if(_capacity == 0)
    {
        expand(n);
    }
    else if(n > _capacity)
    {
        if(n < (_capacity*2))
        {
            expand();
        }
        else
        {
            expand(n - _capacity);
        }
    }
    _size = n; 
    for(unsigned int i = 0; i < n; i++)
    {
        _data[i] = value;
    }
}

