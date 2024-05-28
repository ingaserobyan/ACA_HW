#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <string>

const int UPPER_BOUND = 5;
const int LOWER_BOUND = 1;

template <typename T>
class Matrix
{
	public:
		Matrix(const int&); // for square
		Matrix(const int&, const int&);
		Matrix(const std::string&); // for creating Matrix from file
		Matrix(const Matrix&);
		Matrix(const Matrix&&);
 		~Matrix();

	public:
		Matrix& operator= (const Matrix&);
		Matrix& operator= (Matrix&&);
		Matrix	operator+ (const Matrix&);
		Matrix&	operator++ ();
		Matrix	operator++ (int);
		Matrix	operator* (const Matrix&);

	public:
		void	display() const;
		void	fillMatrixRand();
		void	fillFromFile(const std::string&);
		void	writeIntoFile(const std::string&) const;

	private:
		void	deleteMatrix();

	private:
		T**	_matrix;
		int	_rows;
		int	_cols;
};

#endif // __MATRIX_HPP__
