#include "pig.hpp"

Pig::Pig(const int& age, const bool& likesMud) : Animal(age),  _likesMud(likesMud) {}
Pig::Pig(Pig&& p) : Animal(p.getAge()),  _likesMud(p._likesMud)
{
	p.setAge(0);
	p._likesMud = false;
}

Pig::~Pig() {}

Pig& Pig::operator= (Pig&& p)
{
	if(this != &p)
	{
		this->setAge(p.getAge());
		p.setAge(0);
		_likesMud = p._likesMud;
		p._likesMud = false;
	}
	return *this;
}

void Pig::voice()
{
	std::cout << "Oink oink!" << std::endl;
}

void Pig::info()
{
	std::cout << "Hi! I am " << getAge() << " years old Pig.";
}


