#include "matrix.hpp"
#include <iostream>


int main()
{
	std::cout << "------------myMatrix--------------" << std::endl;
	Matrix myMatrix(3, 5);
	myMatrix.display();

	std::cout << "------------++myMatrix--------------" << std::endl;
	++myMatrix;
	myMatrix.display();

	std::cout << "------------tmp = myMatrix++--------------" << std::endl;
	const Matrix& tmp = myMatrix++;
	tmp.display();

	std::cout << "- - - myMatrix - - -" << std::endl;
	myMatrix.display();

	std::cout << "------------Matrix temp = myMatrix + tmp--------------" << std::endl;
	Matrix temp = myMatrix + tmp;
	temp.display();

	std::cout << "------------temp = myMatrix++ --------------" << std::endl;
	temp = myMatrix++;
	temp.display();

	return 0;
}
