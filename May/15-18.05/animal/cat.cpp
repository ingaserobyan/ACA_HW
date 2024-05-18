#include "cat.hpp"

Cat::Cat(const int& currentLives) : _livesRemaining(currentLives) {}
Cat::Cat(Cat&& cat) : _livesRemaining(cat._livesRemaining)
{
	_livesRemaining = 0;
}

Cat::~Cat() {}

Cat& Cat::operator=(Cat&& c)
{
	if(this != &c)
	{
		_livesRemaining = c._livesRemaining;
		c._livesRemaining = 0;
	}
	return *this;
}

void Cat::voice()
{
	std::cout << "Meow meow!" << std::endl;
}
