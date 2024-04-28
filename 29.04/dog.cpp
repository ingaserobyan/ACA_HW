#include "dog.hpp"

Dog::Dog() {};
Dog::~Dog()
{
	std::cout << "Dog dtor called" << std::endl;
}

void Dog::voice()
{
	std::cout << "Woof woof!" << std::endl;
}