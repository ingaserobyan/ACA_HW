#ifndef __MATRIX_CPP__
#define __MATRIX_CPP__

#include "matrix.hpp"

// __C-TORS___AND__D-TORS__
template <typename T>
Matrix<T>::Matrix(const int& size) :
	_rows(size),
	_cols(size)
{
	_matrix = new T*[_rows];
	for(int i = 0; i < _rows; ++i)
	{
		_matrix[i] = nullptr;
	}
};

template <typename T>
Matrix<T>::Matrix(const int& rows, const int& cols) :
	_rows(rows),
	_cols(cols)
{
	_matrix = new T*[_rows];
	for(int i = 0; i < _rows; ++i)
	{
		_matrix[i] = nullptr;
	}
};

template <typename T>
Matrix<T>::Matrix(const Matrix& m) :
	_rows(m._rows),
	_cols(m._cols)
{
	_matrix = new T*[_rows];
	for(int i = 0; i < _rows; ++i)
	{
		_matrix[i] = nullptr;
	}
};

template <typename T>
Matrix<T>::~Matrix()
{
	for(int i = 0; i < _rows; ++i)
	{
		delete _matrix[i];
	}
	delete[] _matrix;
}


//__OPERATOR__OVERLOADING__
template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& m)
{
	if(_rows == m._rows)
	{
		for(int i = 0; i < _rows; i = 0)
		{
			delete _matrix[i]; //maybe memory leak
			_matrix[i] = nullptr;
		}
	}
	else
	{
		this->deleteMatrix();
	}
}


//__PRIVATE__FUNCTIONS__
template <typename T>
void Matrix<T>::deleteMatrix()
{
	for(int i = 0; i < _rows; ++i)
	{
		delete _matrix[i];
		_matrix[i] = nullptr;
	}
	delete[] _matrix;
	_matrix = nullptr;
}

#endif // _MATRIX_CPP__
