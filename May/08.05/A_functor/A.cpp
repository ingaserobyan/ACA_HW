#include "A.hpp"

A::A(const int& radius) : _radius(radius) {}

float A::operator() () const
{
	return (M_PI * _radius * _radius);
}

float A::operator() (const int& radius) const
{
	return (M_PI * radius * radius);
}
