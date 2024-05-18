#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>

const int UPPER_BOUND = 5;
const int LOWER_BOUND = 1;

class Matrix
{
	public:
		Matrix();
		Matrix(const int&, const int&);
		Matrix(const Matrix&);
		Matrix(Matrix&&);
		~Matrix();

	public:
		Matrix&	operator= (const Matrix&);
		Matrix& operator= (Matrix&&);

		Matrix	operator+ (const Matrix&);
		Matrix&	operator++ ();
		Matrix	operator++ (int);

	public:
		void	display()	const;

	private:
		int**	allocateMatrixRand(const int&, const int&);
		void	deleteMatrix(int**, const int&);

	private:
		int	_rows;
		int	_cols;
		int**	_matrix;
};

#endif // __MATRIX_HPP__
