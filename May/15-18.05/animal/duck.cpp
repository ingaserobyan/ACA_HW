#include "duck.hpp"

Duck::Duck(const bool& dd) : _isDonaldDuck(dd) {}
Duck::Duck(Duck&& d) : _isDonaldDuck(d._isDonaldDuck)
{
	d._isDonaldDuck = false;
}

Duck::~Duck() {}

Duck& Duck::operator=(Duck&& d)
{
	if(this != &d)
	{
		_isDonaldDuck = d._isDonaldDuck;
		d._isDonaldDuck = false;
	}
	return *this;
}

void Duck::voice()
{
	std::cout << "Quak quack!" << std::endl;
}
