#include "array.hpp"

#include <iostream>

int main()
{
	Array myArr(5);

	std::cout << myArr[0] << std::endl;
	myArr[0] = 5;
	std::cout << myArr[0] << std::endl;

	return 0;
}
