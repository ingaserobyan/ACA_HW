#include "animal.hpp"

Animal::Animal(const float& weight, const float& fcr, const float& sda)	:
	_weight(weight),
	_fcr(fcr),
	_sda(sda) {}

Animal::~Animal() {}

void Animal::eat(const float& feedWeight)
{
	_weight +=  feedWeight * _fcr;
}

float Animal::getWeight() const {return _weight;};
