#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal&);

		virtual ~Animal();

	public:
		virtual void voice() = 0;

	static int count;
};

# endif //__ANIMAL_HPP__
