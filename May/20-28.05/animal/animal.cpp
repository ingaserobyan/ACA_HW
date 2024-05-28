#include "animal.hpp"

int Animal::count = 0;

Animal::Animal(const int& age) : _age(age)
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

int	Animal::getAge() const
{
	return _age;
}

void Animal::setAge(const int& age)
{
	if(age >= 0)
	{
		_age = age;
	}
}


bool Animal::operator< (const Animal& b) const
{
	return (_age < b._age);
}

bool Animal::operator> (const Animal& b) const
{
	return (_age > b._age);
}

bool Animal::operator== (const Animal& b) const
{
	return (_age == b._age);
}

bool Animal::operator>= (const Animal& b) const
{
	return (_age >= b._age);
}
