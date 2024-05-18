#ifndef __PIG_HPP__
#define __PIG_HPP__

#include "animal.hpp"

class Pig : public Animal
{
	public:
		Pig(const bool&);
		Pig(Pig&&);
		virtual ~Pig();

	public:
		Pig& operator= (Pig&&);
		void voice() override;

	private:
		bool _likesMud;

};

# endif // __PIG_HPP__
