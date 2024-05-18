#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "animal.hpp"

class Dog : public Animal
{
	public:
		Dog(const int&);
		Dog(Dog&&);
		virtual ~Dog();

	public:
		Dog& operator= (Dog&&);
		void voice() override;

	private:
		int _loyaltyLevel;
};

# endif // __DOG_HPP__
