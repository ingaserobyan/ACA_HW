#include "zoo.hpp"

Zoo::Zoo() {}

Zoo::~Zoo() {}

Zoo& Zoo::getZoo()
{
	static Zoo zoo;
	return zoo;
}

void Zoo::addAnimal(Animal* animal)
{
	_zoo.push_back(animal);
}

Animal* Zoo::operator[] (int index) const
{
	return _zoo[index];
}