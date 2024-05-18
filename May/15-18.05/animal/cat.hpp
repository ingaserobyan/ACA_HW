#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "animal.hpp"

class Cat : public Animal
{
	public:
		Cat(const int&);
		Cat(Cat&&);
		virtual ~Cat();

	public:
		Cat& operator= (Cat&&);
		void voice() override;

	private:
		int _livesRemaining;

};

# endif // __CAT_HPP__
