#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	public:
		Animal();

		virtual ~Animal();

	public:
		virtual void voice() = 0;
};

# endif //__ANIMAL_HPP__