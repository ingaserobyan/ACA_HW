#include "bee.hpp"

Bee::Bee() {};
Bee::~Bee()
{
	std::cout << "Bee dtor called" << std::endl;
}

void Bee::voice()
{
	std::cout << "Buzz Buzz!" << std::endl;
}