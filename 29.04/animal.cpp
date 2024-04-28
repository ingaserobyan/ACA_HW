#include "animal.hpp"

Animal::Animal(int legs) : _legs(legs) {}

Animal::~Animal()
{
	std::cout << "Animal dtor called" << std::endl;
}

void Animal::voice()
{
	std::cout << "Oops! I do not have sound" << std::endl;
}
