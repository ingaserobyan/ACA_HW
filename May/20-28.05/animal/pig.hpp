#ifndef __PIG_HPP__
#define __PIG_HPP__

#include "animal.hpp"

class Pig : public Animal
{
	public:
		Pig(const int&, const bool&);
		Pig(Pig&&);
		virtual	~Pig();

	public:
		Pig&	operator= (Pig&&);

	public:
		void	voice() override;
		void	info() override;

	private:
		bool _likesMud;

};

# endif // __PIG_HPP__
