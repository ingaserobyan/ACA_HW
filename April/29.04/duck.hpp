#ifndef __DUCK_HPP__
#define __DUCK_HPP__

#include "animal.hpp"

class Duck : public Animal
{
	public:
		Duck();
		virtual ~Duck();

	public:
		void voice() override;

};

# endif // __DUCK_HPP__