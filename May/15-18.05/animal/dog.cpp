#include "dog.hpp"

Dog::Dog(const int& loyalty) : _loyaltyLevel(loyalty) {}
Dog::Dog(Dog&& d) : _loyaltyLevel(d._loyaltyLevel)
{
	d._loyaltyLevel = 0;
}

Dog::~Dog() {}

Dog& Dog::operator= (Dog&& d)
{
	if(this != &d)
	{
		_loyaltyLevel = d._loyaltyLevel;
		d._loyaltyLevel = 0;
	}
	return *this;
}

void Dog::voice()
{
	std::cout << "Woof woof!" << std::endl;
}
