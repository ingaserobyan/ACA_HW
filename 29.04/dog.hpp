#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();

	public:
		void voice() override;

};

# endif // __DOG_HPP__