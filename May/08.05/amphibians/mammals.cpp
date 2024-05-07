#include "mammals.hpp"

Mammals::Mammals(const float& weight, const float& fcr, const float& sda, const bool& runningLevel)	:
	Animal(weight, fcr, sda),
	_runningLevel(runningLevel) {}

Mammals::~Mammals() {}

void Mammals::run(const int& distance, const int& time)
{
	if(_runningLevel)
	{
		_weight -= distance / time * _sda;
	}
}

void Mammals::setRuningMode(const bool& mode) {_runningLevel = mode;}

bool Mammals::getRuningMode() {return _runningLevel;}
