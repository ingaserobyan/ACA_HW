#include <iostream>

#include "matrix.hpp"

int main()
{
	Matrix<int> matrix1("matrix_1.txt");

	Matrix<int> matrix2("matrix_2.txt");

	Matrix<int> result(matrix1 * matrix2);

	result.writeIntoFile("matrix_result.txt");

	return 0;
}
