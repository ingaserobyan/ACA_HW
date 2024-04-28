#include "duck.hpp"

Duck::Duck() {};
Duck::~Duck()
{
	std::cout << "Duck dtor called" << std::endl;
}

void Duck::voice()
{
	std::cout << "Quak quack!" << std::endl;
}