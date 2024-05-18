#include "animal.hpp"

int Animal::count = 0;

Animal::Animal()
{
	++Animal::count;
}

Animal::~Animal()
{
	--Animal::count;
}

Animal::Animal(const Animal&)
{

	++Animal::count;
}

Animal::Animal(Animal&&)
{
	++count;
}

void Animal::voice()
{
	std::cout << "Oops! I do not have sound" << std::endl;
}
