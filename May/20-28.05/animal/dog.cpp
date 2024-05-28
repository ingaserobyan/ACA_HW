#include "dog.hpp"

Dog::Dog(const int& age, const int& loyalty) : Animal(age), _loyaltyLevel(loyalty) {}
Dog::Dog(Dog&& d) : Animal(d.getAge()), _loyaltyLevel(d._loyaltyLevel)
{
	d._loyaltyLevel = 0;
	d.setAge(0);
}

Dog::~Dog() {}

Dog& Dog::operator= (Dog&& d)
{
	if(this != &d)
	{
		this->setAge(d.getAge());
		d.setAge(0);
		_loyaltyLevel = d._loyaltyLevel;
		d._loyaltyLevel = 0;
	}
	return *this;
}

void Dog::voice()
{
	std::cout << "Woof woof!" << std::endl;
}

void Dog::info()
{
	std::cout << "Hi! I am " << getAge() << " years old Dog.";
}

