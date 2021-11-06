#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <algorithm>

template <class Type>
class Array
{
private:
    Type* _ptr;
    std::size_t _length;
public:
    Array(const Type* ptr = nullptr, const std::size_t& length = 0);
    Array(std::initializer_list<Type> list);
    Array(const Array& array);
    Array(Array&& array);
    ~Array();

    Array& operator=(const Array& array);
    Array& operator=(Array&& array);

    Type& operator[](const std::size_t& index);

    void resize(const std::size_t& length);
    void swap(Array& array);

    Type* getPtr() const { return _ptr; }
    const std::size_t& size() const { return _length; }
    void printInfo(int i = 0) const;
};

template <class Type>
Array<Type>::Array(const Type* ptr, const std::size_t& length) : _length{ length }
{
    if (_length)
    {
        _ptr = new Type[_length];
        for (auto i = 0; i < length; ++i)
        {
            _ptr[i] = ptr[i];
        }
    }
}

template <class Type>
Array<Type>::Array(std::initializer_list<Type> list) : _length{list.size()}
{
    if (_length)
    {
        _ptr = new Type[_length];
        int i = 0;
        for (auto value : list)
        {
            _ptr[i] = value;
            ++i;
        }
    }
}

template <class Type>
Array<Type>::Array(const Array& array) : Array(array._ptr, array._length) {}

template <class Type>
Array<Type>::Array(Array&& array) : Array(array._ptr, array._length)
{
    array._ptr = nullptr;
    array._length = 0;
}

template <class Type>
Array<Type>::~Array()
{
    _ptr = nullptr;
    _length = 0;
}

template <class Type>
Array<Type>& Array<Type>::operator=(const Array<Type>& array)
{
    if (_ptr == array._ptr)
    {
        if (_length > array._length)
        {
            Type* ptr = new Type[array._length];
            for (auto i = 0; i < _length; ++i)
            {
                ptr[i] = _ptr[i];
            }
            delete[] _ptr;
            _ptr = ptr;
        }
        _length = array._length;
        return *this;
    }

    delete[] _ptr;

    _length = array._length;
    _ptr = new Type[_length];

    for (auto i = 0; i < _length; ++i)
    {
        _ptr[i] = array._ptr[i];
    }
    return *this;
}

template <class Type>
Array<Type>& Array<Type>::operator=(Array<Type>&& array)
{
    _ptr = array._ptr;
    _length = array._length;

    array._length = 0;
    return *this;
}

template <class Type>
Type& Array<Type>::operator[](const std::size_t& index)
{
    return (this->_ptr)[index];
}

template <class Type>
void Array<Type>::resize(const std::size_t& length)
{
    Type* ptr = new Type[length];
    if (length > _length)
    {
        for (auto i = 0; i < _length; ++i)
        {
            ptr[i] = _ptr[i];
        }
        for (auto i = _length; i < length; ++i)
        {
            ptr[i] = Type{};
        }
    }
    else
    {
        for (auto i = 0; i < length; ++i)
        {
            ptr[i] = _ptr[i];
        }
    }
    delete[] _ptr;
    _ptr = ptr;
    _length = length;
}

template <class Type>
void Array<Type>::swap(Array<Type>& array)
{
    std::swap(_ptr, array._ptr);
    std::swap(_length, array._length);
}

template <class Type>
void Array<Type>::printInfo(int i) const
{
    std::string result{ "[" };
    std::string comma;
    for (auto i = 0; i < _length; ++i)
    {
        result += comma + std::to_string(_ptr[i]);
        comma = ", ";
    }
    result += "]";
    std::cout << "arr" << i << " = " << result << "  |  location = " << _ptr << "  |  length = " << _length << "\n";
}

template <>
void Array<std::string>::printInfo(int i) const
{
    std::string result{ "[" };
    std::string comma;
    for (auto i = 0; i < _length; ++i)
    {
        result += comma + _ptr[i];
        comma = " ";
    }
    result += "]";
    std::cout << "arr" << i << " = " << result << "  |  location = " << _ptr << "  |  length = " << _length << "\n";
}