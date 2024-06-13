#include "vector.hpp"

#include <iostream>

int main()
{
	int size = 5;
	my::vector<int> v(size);
	for(int i = 0; i < 3; ++i)
	{
		v.push_back(i);
	}

	for(int i = 0; i < size; ++i)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}
