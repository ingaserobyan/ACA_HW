#include "amphibian.hpp"

Amphibian::Amphibian(const float& weight, const float& fcr, const float& sda, const float& swimSpeed, const bool& mode, const bool& location)	:
	Animal(weight, fcr, sda),
	Fish(weight, fcr, sda, swimSpeed),
	Mammals(weight, fcr, sda, mode),
	_currentLocation(location) {}

Amphibian::~Amphibian() {}

bool Amphibian::getLocation() const {return _currentLocation;}

void Amphibian::goTo(const bool& location)
{
	_currentLocation = location;
}


void Amphibian::currentLocation() const
{
	if(_currentLocation)
		std::cout << "In water" << std::endl;
	else
		std::cout << "In land" << std::endl;
}
