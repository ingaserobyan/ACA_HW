#include "vector.hpp"

#include <stdexcept>
#include <iostream>

namespace	my
{
	template<>
	vector<int>::vector(const unsigned int& size) :
		_size(size),
		_capacity(2 * size),
		_vector(new int[_capacity]) {}

	template<>
	vector<int>::vector(const vector& v) :
		_size(v._size),
		_capacity(v._capacity),
		_vector(new int[v._capacity])
	{
		for (int i = 0; i < _size; ++i)
		{
			_vector[i] = v._vector[i];
		}
	}

	template<>
	vector<int>::vector(vector&& v) :
		_size(v._size),
		_capacity(v._capacity),
		_vector(v._vector)
	{
		v._size = 0;
		v._capacity = 0;
		v._vector = nullptr;
	}

	template<>
	vector<int>::~vector()
	{
		delete[] _vector;
	}

	template<>
	vector<int>& vector<int>::operator=(const vector& v)
	{
		if(this != &v)
		{
			delete[] _vector;
			_size = v._size;
			_capacity = v._capacity;
			_vector = new int[_capacity];
			for(int i = 0; i < _size; ++i)
			{
				_vector[i] = v._vector[i];
			}
		}
		return *this;
	}

	template<>
	vector<int>& vector<int>::operator=(vector&& v)
	{
		if(this != &v)
		{
			delete[] _vector;
			_size = v._size;
			_capacity = v._capacity;
			_vector = v._vector;

			v._size = 0;
			v._capacity = 0;
			v._vector = nullptr;
		}
		return *this;
	}

	template<>
	void	vector<int>::push_back(const int& i)
	{
		if(_capacity == 0)
		{
			_vector = new int[1];
			_capacity++;
		}
		if(_size == _capacity)
		{
			int* tmp = new int[_capacity * 2];
			for(int i = 0; i < _size; ++i)
			{
				tmp[i] = _vector[i];
			}
			delete[] _vector;
			_vector = tmp;
			_capacity *= 2;
		}
		_vector[_size] = i;
		_size++;
	}

	template<>
	int&	vector<int>::operator[](const int& index)
	{
		if(index < 0 || index >= _size)
			throw std::invalid_argument("Not valid index");
		return _vector[index];
	}
}
