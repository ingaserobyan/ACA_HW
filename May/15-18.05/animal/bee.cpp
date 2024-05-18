#include "bee.hpp"

Bee::Bee(const double& honeyProduct) : _honeyProduction(honeyProduct) {};

Bee::Bee(Bee&& b)
{
	_honeyProduction = b._honeyProduction;
	b._honeyProduction = 0;
};

Bee::~Bee() {}

Bee& Bee::operator= (Bee&& b)
{
	if(this != &b)
	{
		_honeyProduction = b._honeyProduction;
		_honeyProduction = 0;
	}
	return *this;
}

double	Bee::getHoneyProduction() const {return _honeyProduction;}

void Bee::voice()
{
	std::cout << "Buzz Buzz!" << std::endl;
}
