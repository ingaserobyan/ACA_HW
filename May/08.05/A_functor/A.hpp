#ifndef __A_HPP__
#define __A_HPP__

#include <cmath>

//A() will calculate Area of circle
class A
{
	public:
		A(const int&);

	public:
		float operator() () const;
		float operator() (const int&) const;

	private:
		int _radius;
};

#endif // __A_HPP__
