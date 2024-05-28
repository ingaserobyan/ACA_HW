#ifndef __DUCK_HPP__
#define __DUCK_HPP__

#include "animal.hpp"

class Duck : public Animal
{
	public:
		Duck(const int&, const bool&);
		Duck(Duck&&);
		virtual	~Duck();

	public:
		Duck&	operator= (Duck&&);

	public:
		void	voice() override;
		void	info() override;

	private:
		bool	_isDonaldDuck;

};

# endif // __DUCK_HPP__
