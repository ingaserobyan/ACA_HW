#include "cat.hpp"

Cat::Cat() {};
Cat::~Cat()
{
	std::cout << "Cat dtor called" << std::endl;
}

void Cat::voice()
{
	std::cout << "Meow meow!" << std::endl;
}