#include <iostream>

const int UPPER_BOUND = 5;
const int LOWER_BOUND = 1;

class Matrix
{
	public:
		Matrix() : _rows(1), _cols(1)
		{
			std::cout << "Defualt ctor called" << std::endl;
			_matrix = allocateMatrixRand(_rows, _cols);
		}

		Matrix(const int& rows, const int& cols) : _rows(rows), _cols(cols)
		{
			std::cout << "Paramed ctor called" << std::endl;
			_matrix = allocateMatrixRand(_rows, _cols);
		}

		Matrix(const Matrix& matrix)
		{
			std::cout << "Copy constructor called" << std::endl;
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

		Matrix& operator= (const Matrix& matrix)
		{
			std::cout << " OPERATOR= called" << std::endl;
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

		Matrix operator+ (const Matrix& matrix)
		{
			std::cout << " OPERATOR+ ctor called" << std::endl;
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

		~Matrix()
		{
			std::cout << "Dtor called" << std::endl;
			deleteMatrix(_matrix, _rows);
			_matrix = nullptr;
		}


	public:
		void display()
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

	private:
		int**	allocateMatrixRand(const int& rows, const int& cols)
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

		void	deleteMatrix(int** matrix, const int& rows)
		{
			for(int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}

	private:
		int	_rows;
		int	_cols;
		int**	_matrix;

};



int main()
{
	Matrix defMatrix;
	defMatrix.display();

	std::cout << "----------------" << std::endl;

	Matrix paramMatrix(3, 5);
	paramMatrix.display();

	std::cout << "----------------" << std::endl;

	Matrix copyMatrix = defMatrix;
	copyMatrix.display();

	std::cout << "----------------" << std::endl;
	copyMatrix = paramMatrix;
	copyMatrix.display();

	std::cout << "----------------" << std::endl;

	defMatrix = paramMatrix + copyMatrix;
	defMatrix.display();

	std::cout << "----------------" << std::endl;
	Matrix testMatrix1 = defMatrix + Matrix(1, 2);
	testMatrix1.display();

	std::cout << "----------------" << std::endl;
	Matrix testMatrix2 = defMatrix + Matrix(paramMatrix);
	testMatrix2.display();

	std::cout << "------END-------" << std::endl;
	return 0;
}
