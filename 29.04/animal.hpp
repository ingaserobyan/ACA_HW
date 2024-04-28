#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	public:
		Animal(int legs = 0);

		virtual ~Animal();

	public:
		virtual void voice();

	private:
		int _legs;
};

# endif //__ANIMAL_HPP__