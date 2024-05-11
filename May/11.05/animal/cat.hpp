#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();

	public:
		void voice() override;

};

# endif // __CAT_HPP__