#include "duck.hpp"

Duck::Duck(const int& age, const bool& dd) : Animal(age), _isDonaldDuck(dd) {}
Duck::Duck(Duck&& d) : Animal(d.getAge()), _isDonaldDuck(d._isDonaldDuck)
{
	d._isDonaldDuck = false;
	d.setAge(0);
}

Duck::~Duck() {}

Duck& Duck::operator=(Duck&& d)
{
	if(this != &d)
	{
		this->setAge(d.getAge());
		d.setAge(0);
		_isDonaldDuck = d._isDonaldDuck;
		d._isDonaldDuck = false;
	}
	return *this;
}

void Duck::voice()
{
	std::cout << "Quak quack!" << std::endl;
}

void Duck::info()
{
	std::cout << "Hi! I am " << getAge() << " years old Duck.";
}
