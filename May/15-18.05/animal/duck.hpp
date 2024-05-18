#ifndef __DUCK_HPP__
#define __DUCK_HPP__

#include "animal.hpp"

class Duck : public Animal
{
	public:
		Duck(const bool&);
		Duck(Duck&&);
		virtual ~Duck();

	public:
		Duck& operator= (Duck&&);
		void voice() override;

	private:
		bool _isDonaldDuck;

};

# endif // __DUCK_HPP__
