#include "bee.hpp"

Bee::Bee(const int& age, const double& honeyProduct) : Animal(age), _honeyProduction(honeyProduct) {};

Bee::Bee(Bee&& b) : Animal(b.getAge())
{
	_honeyProduction = b._honeyProduction;
	b._honeyProduction = 0;

	b.setAge(0);
};

Bee::~Bee() {}

Bee& Bee::operator= (Bee&& b)
{
	if(this != &b)
	{
		_honeyProduction = b._honeyProduction;
		_honeyProduction = 0;

		this->setAge(b.getAge());
		b.setAge(0);
	}
	return *this;
}

double	Bee::getHoneyProduction() const {return _honeyProduction;}

void Bee::info()
{
	std::cout << "Hi! I am " << getAge() << " years old Bee.";
}

void Bee::voice()
{
	std::cout << "Buzz Buzz!" << std::endl;
}

