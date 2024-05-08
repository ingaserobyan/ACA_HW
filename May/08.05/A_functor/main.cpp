#include <iostream>
#include <time.h>

#include "A.hpp"

int main()
{
	srand(time(0));

	A circle1(5);
	std::cout << "Circle 1 Area : " << circle1() << std::endl;

	int randomRadius = rand() % 20;
	std::cout << "Cirle Aea with ranodm radius " << randomRadius << " : " << circle1(randomRadius) << std::endl;

	return 0;
}
