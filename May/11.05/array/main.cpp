#include "array.hpp"

#include <iostream>

std::ostream& operator<< (std::ostream& os, const Array& arr)
{
	for (int i = 0; i < arr._size; ++i)
	{
		os << arr[i];
		if (i < (arr._size - 1))
			os << ", ";
	}
	return os;
}

int main()
{
	Array myArr(5);
	int size = myArr.size();

	for(int i = 0; i < size; ++i)
	{
		myArr[i] = i;
	}

	Array copyArr(myArr);

	std::cout << myArr << std::endl;
	std::cout << copyArr << std::endl;

	return 0;
}
