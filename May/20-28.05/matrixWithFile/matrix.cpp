#include "matrix.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

static bool	isValidLine(const std::string& line)
{
	if (line.empty()) return false;

	bool	hasDigits = false;
	char	c;
	for (size_t i = 0; i < line.length(); ++i)
	{
		c = line[i];
		if (i == 0 && (c == '+' || c == '-'))
			continue;
		if (c == ' ')
			continue;
		if (!std::isdigit(c))
			return false;
		else
			hasDigits = true;
	}
	return hasDigits;
}


template<>
void	Matrix<int>::deleteMatrix();

template<>
void	Matrix<int>::fillFromFile(const std::string&);

// __C-TORS___AND__D-TOR__
template <>
Matrix<int>::Matrix(const int& size) :
	_rows(size),
	_cols(size)
{
	_matrix = new int*[_rows];
	for(int i = 0; i < _rows; ++i)
	{
		_matrix[i] = new int[_cols]{0};
	}
};

template <>
Matrix<int>::Matrix(const int& rows, const int& cols) :
	_rows(rows),
	_cols(cols)
{
	_matrix = new int*[_rows];
	for(int i = 0; i < _rows; ++i)
	{
		_matrix[i] = new int[_cols]{0};
	}
};

template<>
Matrix<int>::Matrix(const std::string& path) : _matrix(nullptr)
{
	this->fillFromFile(path);
}

template <>
Matrix<int>::Matrix(const Matrix& m) :
	_rows(m._rows),
	_cols(m._cols)
{
	_matrix = new int*[_rows];
	for(int i = 0; i < _rows; ++i)
	{
		_matrix[i] = new int[_cols];
		for(int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] = m._matrix[i][j];
		}
	}
};

template <>
Matrix<int>::Matrix(const Matrix&& m) :
	_rows(m._rows),
	_cols(m._cols),
	_matrix(m._matrix)
{
	_rows = 0;
	_cols = 0;
	_matrix = nullptr;
}

template <>
Matrix<int>::~Matrix()
{
	for(int i = 0; i < _rows; ++i)
	{
		delete[] _matrix[i];
	}
	delete[] _matrix;
}


//__OPERATOR__OVERLOADING__
template <>
Matrix<int>& Matrix<int>::operator= (const Matrix<int>& m)
{
	if(this != &m)
	{
		if(_rows == m._rows )
		{
			if(_cols != m._cols)
			{
				_cols = m._cols;
				for(int i = 0; i < _rows; i = 0)
				{
					delete[] _matrix[i];
					_matrix[i] = new int[_cols]{0};
					for(int j = 0; j < _cols; ++j)
					{
						_matrix[i][j] = m._matrix[i][j];
					}
				}
			}
			else
			{
				for (int i = 0; i < _rows; ++i)
				{
					for(int j = 0; j < _cols; ++j)
					{
						_matrix[i][j] = m._matrix[i][j];
					}
				}
			}
		}
		else
		{
			this->deleteMatrix();
			_rows = m._rows;
			_cols = m._cols;
			_matrix = new int*[_rows];
			for(int i = 0; i < _rows; i = 0)
			{
				delete[] _matrix[i];
				_matrix[i] = new int[_cols]{0};
				for(int j = 0; j < _cols; ++j)
				{
					_matrix[i][j] = m._matrix[i][j];
				}
			}
		}
	}
	return *this;
}

template<>
Matrix<int>& Matrix<int>::operator= (Matrix<int>&& m)
{
	this->deleteMatrix();
	_rows = m._rows;
	m._rows = 0;

	_cols = m._cols;
	m._cols = 0;

	_matrix = m._matrix;
	m._matrix = nullptr;
}


//__PRIVATE__FUNCTIONS__
template<>
void Matrix<int>::deleteMatrix()
{
	for(int i = 0; i < _rows; ++i)
	{
		delete[] _matrix[i];
		_matrix[i] = nullptr;
	}
	delete[] _matrix;
	_matrix = nullptr;
}

template<>
void Matrix<int>::display() const
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

template<>
void	Matrix<int>::fillMatrixRand()
{
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] = rand() % (UPPER_BOUND - LOWER_BOUND) + LOWER_BOUND;
		}
	}
}

template<>
Matrix<int> Matrix<int>::operator+ (const Matrix& matrix)
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

template<>
Matrix<int>& Matrix<int>::operator++ ()
{
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] += 1;
		}
	}
	return *this;
}

template<>
Matrix<int> Matrix<int>::operator++ (int)
{
	Matrix tmp(*this);
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < _cols; ++j)
		{
			_matrix[i][j] += 1;
		}
	}
	return tmp;
}

template<>
Matrix<int> Matrix<int>::operator* (const Matrix<int>& matrix)
{
    if (_cols != matrix._rows)
	{
        throw std::invalid_argument("Wrong Matrix Dimensions");
    }
    Matrix<int> result(_rows, matrix._cols);
    for (int i = 0; i < _rows; ++i)
	{
        for (int j = 0; j < matrix._cols; ++j)
		{
            result._matrix[i][j] = 0;
            for (int k = 0; k < _cols; ++k)
			{
                result._matrix[i][j] += _matrix[i][k] * matrix._matrix[k][j];
            }
        }
    }
    return result;
}

template<>
void Matrix<int>::fillFromFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        throw std::invalid_argument("Cannot open file");
    }

    std::vector<std::vector<int>> tmpMatrix;
    std::string line;

    while (std::getline(file, line))
    {
		if(!isValidLine(line))
		{
			throw std::invalid_argument("Wrong data in file");
		}
        std::vector<int> row;
        std::istringstream lineParsing(line);
        int num;
        while (lineParsing >> num)
        {
            row.push_back(num);
        }
        tmpMatrix.push_back(row);
    }

	if (this->_matrix != nullptr)
		this->deleteMatrix();
    int rows = tmpMatrix.size();
    int cols = (rows > 0) ? tmpMatrix[0].size() : 0;

    _rows = rows;
    _cols = cols;
    _matrix = new int*[_rows];
    for (int i = 0; i < _rows; ++i)
    {
        _matrix[i] = new int[_cols];
        for (int j = 0; j < _cols; ++j)
        {
            _matrix[i][j] = tmpMatrix[i][j];
        }
    }

    file.close();
}

template<>
void	Matrix<int>::writeIntoFile(const std::string& path) const
{
	std::ofstream file(path);
	if(!file)
	{
		throw std::invalid_argument("Wrong path");
	}

	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < _cols; ++j)
		{
			file << _matrix[i][j] << " " << std::flush;
		}
		file << std::endl;
	}

	file.close();
}
