#include "pig.hpp"

Pig::Pig() {};
Pig::~Pig()
{
	std::cout << "Pig dtor called" << std::endl;
}

void Pig::voice()
{
	std::cout << "Oink oink!" << std::endl;
}