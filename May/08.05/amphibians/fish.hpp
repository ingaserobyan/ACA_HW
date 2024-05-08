#ifndef __FISH_HPP__
#define __FISH_HPP__

#include "animal.hpp"

class Fish : virtual public Animal
{
	public:
		Fish(const float&, const float&, const float&, const float&); // Animal(_weight, _fcr), _swimSpeed
		~Fish() override;

	public:
		void swim(const int&); // time
	private:
		float	_swimSpeed;
};

#endif // __FISH_HPP__
