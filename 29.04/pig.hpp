#ifndef __PIG_HPP__
#define __PIG_HPP__

#include "animal.hpp"

class Pig : public Animal
{
	public:
		Pig();
		virtual ~Pig();

	public:
		void voice() override;

};

# endif // __PIG_HPP__