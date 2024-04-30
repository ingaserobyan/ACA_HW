#include <iostream>
#include <cstdlib>

const int UPPER_BOUND = 10;
const int LOWER_BOUND = 1;

class Matrix
{
	public:
		Matrix(const int& rows, const int& cols)
		{
			_rows = rows;
			_cols = cols;
			_matrix = allocateMatrixWithRand(_rows, _cols);
		}

		~Matrix()
		{
			deleteMatrix(_matrix, _rows);
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

		void transpose()
		{
			int** temp = _matrix;
			_matrix = matrixTranspose(_matrix, _cols, _rows);
			deleteMatrix(temp, _cols);
			std::swap(_rows, _cols);
		}


	private:
		int** allocateMatrixWithRand(const int& rows, const int& cols)
		{
			int** matrix = (int**) malloc(rows * sizeof(int*));
			if(!matrix)
				return nullptr;
			for (int i = 0; i < rows; ++i){
				matrix[i] = (int*) malloc(cols * sizeof(int));
				if (!matrix[i]){
					deleteMatrix(matrix, i);
					return nullptr;
				}
				for (int j = 0; j < cols; ++j){
					matrix[i][j] = rand() % (UPPER_BOUND - LOWER_BOUND) + LOWER_BOUND;
				}
			}
			return matrix;
		}

		void deleteMatrix(int** matrix, const int& rows)
		{
			for(int i = 0; i < rows; ++i){
				free((void*)matrix[i]);
				matrix[i] = nullptr;
			}
			free((void*)matrix);
		}

		int** matrixTranspose(int** matrix, int rows, int cols)
			{
				int** new_matrix = allocateMatrixWithRand(rows, cols);
				{
					if(!new_matrix)
					{
						return matrix;
					}
					for(int i = 0; i < rows; ++i)
					{
						for(int j = 0; j < cols; ++j)
						{
							new_matrix[i][j] = matrix[j][i];
						}
					}
				}
				return new_matrix;
			}


	private:
		int**	_matrix;
		int		_rows;
		int		_cols;
};


int main()
{
	Matrix myMatrix(3, 5);
	myMatrix.display();
	myMatrix.transpose();
	std::cout << "-------------------" << std::endl;
	myMatrix.display();

	return 0;
}
