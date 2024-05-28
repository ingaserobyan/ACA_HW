#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

template <typename T>
class Matrix
{
	public:
		Matrix(const int&); // for square
		Matrix(const int&, const int&);
		Matrix(const Matrix&);
 		~Matrix();

	public:
		Matrix& operator= (const Matrix&);

	private:
		void	deleteMatrix();

	private:
		T**	_matrix;
		int	_rows;
		int	_cols;
};

#include "matrix.cpp"

#endif // __MATRIX_HPP__
