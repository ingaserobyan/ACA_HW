#ifndef __BEE_HPP__
#define __BEE_HPP__

#include "animal.hpp"

class Bee : public Animal
{
	public:
		Bee(const int&, const double&);
		Bee(Bee&&);
		virtual ~Bee();

	public:
		Bee&	operator= (Bee&&);
		double	getHoneyProduction() const;

	public:
		void	voice() override;
		void	info() override;

	private:
		double	_honeyProduction;
};

# endif // __BEE_HPP__
