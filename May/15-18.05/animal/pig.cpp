#include "pig.hpp"

Pig::Pig(const bool& likesMud) : _likesMud(likesMud) {}
Pig::Pig(Pig&& p) : _likesMud(p._likesMud)
{
	p._likesMud = false;
}

Pig::~Pig() {}

Pig& Pig::operator= (Pig&& p)
{
	if(this != &p)
	{
		_likesMud = p._likesMud;
		p._likesMud = false;
	}
	return *this;
}

void Pig::voice()
{
	std::cout << "Oink oink!" << std::endl;
}
