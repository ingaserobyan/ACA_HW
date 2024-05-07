#include "fish.hpp"

Fish::Fish(const float& weight, const float& fcr, const float& sda, const float& swimSpeed)	:
	Animal(weight, fcr, sda),
	_swimSpeed(swimSpeed) {}

Fish::~Fish() {}

void Fish::swim(const int& time)
{
	_weight -= time * _swimSpeed * _sda;
}
