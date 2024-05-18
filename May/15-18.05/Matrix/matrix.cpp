#include "matrix.hpp"

Matrix::Matrix() : _rows(1), _cols(1)
{
	_matrix = allocateMatrixRand(_rows, _cols);
}

Matrix::Matrix(const int& rows, const int& cols) : _rows(rows), _cols(cols)
{
	_matrix = allocateMatrixRand(_rows, _cols);
}

Matrix::Matrix(const Matrix& matrix)
{
	_rows = matrix._rows;
	_cols = matrix._cols;
	_matrix = new int*[_rows];
	for (int i = 0; i < _rows; ++i)
	{
		_matrix[i] = new int[_cols];
		for (int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] = matrix._matrix[i][j];
		}
	}
}

Matrix& Matrix::operator= (const Matrix& matrix)
{
	if (this == &matrix)
		return *this;

	deleteMatrix(_matrix, _rows);
	_matrix = nullptr;

	_rows = matrix._rows;
	_cols = matrix._cols;
	_matrix = new int*[_rows];
	for (int i = 0; i < _rows; ++i)
	{
		_matrix[i] = new int[_cols];
		for (int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] = matrix._matrix[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+ (const Matrix& matrix)
{
	if ((_rows != matrix._rows) || (_cols != matrix._cols))
		return Matrix(0, 0);
	Matrix tmpMatrix(_rows, _cols);
	for(int i = 0; i < tmpMatrix._rows; ++i)
	{
		for (int j = 0; j < tmpMatrix._cols; ++j)
		{
			tmpMatrix._matrix[i][j] = _matrix[i][j] + matrix._matrix[i][j];
		}
	}
	return tmpMatrix;
}

Matrix::~Matrix()
{
	deleteMatrix(_matrix, _rows);
	_matrix = nullptr;
}

void Matrix::display() const
{
	for(int i = 0; i < _rows; ++i){
		for(int j = 0; j < _cols; ++j)
		{
			std::cout << _matrix[i][j];
			if (j < (_cols - 1))
				std::cout << ", ";
		}
		std::cout << std::endl;
	}
}

int**	Matrix::allocateMatrixRand(const int& rows, const int& cols)
{
	int** matrix = new int*[rows];
	for(int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[cols];
		for(int j = 0; j < cols; ++j)
		{
			matrix[i][j] = rand() % (UPPER_BOUND - LOWER_BOUND) + LOWER_BOUND;
		}
	}
	return matrix;
}

void	Matrix::deleteMatrix(int** matrix, const int& rows)
{
	for(int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


Matrix& Matrix::operator++ ()
{
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] += 3;
		}
	}
	return *this;
}

Matrix Matrix::operator++ (int)
{
	Matrix tmp(*this);
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] += 3;
		}
	}
	return tmp;
}

Matrix::Matrix(Matrix&& matrix) : _rows(matrix._rows), _cols(matrix._cols), _matrix(matrix._matrix)
{
	std::cout << "move ctor called" << std::endl;
	matrix._rows = 0;
	matrix._cols = 0;
	matrix._matrix = nullptr;
}


Matrix& Matrix::operator= (Matrix&& matrix)
{
	std::cout << "move operator called" << std::endl;
	if(this != &matrix)
	{
		deleteMatrix(_matrix, _rows);

		_rows = matrix._rows;
        _cols = matrix._cols;
        _matrix = matrix._matrix;

        matrix._rows = 0;
        matrix._cols = 0;
        matrix._matrix = nullptr;
	}
	return *this;
}
