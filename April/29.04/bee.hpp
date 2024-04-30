#ifndef __BEE_HPP__
#define __BEE_HPP__

#include "animal.hpp"

class Bee : public Animal
{
	public:
		Bee();
		virtual ~Bee();

	public:
		void voice() override;

};

# endif // __BEE_HPP__