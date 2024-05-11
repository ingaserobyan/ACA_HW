#include "array.hpp"

Array::Array(const int size) : _size(size)
{
	_array = new int[_size];
}

Array::Array(const Array& array) : _size(array._size)
{
	_array = new int[_size];
	for(int i = 0; i < _size; ++i)
	{
		_array[i] = array._array[i];
	}
}

Array::~Array()
{
	delete[] _array;
}

Array& Array::operator= (const Array& array)
{
	if(this == &array)
		return *this;
	if(_size == array._size)
	{
		for(int i = 0; i < _size; ++i)
		{
			_array[i] = array._array[i];
		}
	}
	else
	{
		_size = array._size;
		delete[] _array;
		_array = new int[_size];
		for(int i = 0; i < _size; ++i)
		{
			_array[i] = array._array[i];
		}
	}
	return *this;
}

int& Array::operator[] (int index) const
{
	

}
