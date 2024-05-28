#include "cat.hpp"

Cat::Cat(const int& age, const int& currentLives) : Animal(age), _livesRemaining(currentLives) {}
Cat::Cat(Cat&& cat) :
	Animal(cat.getAge()),
	_livesRemaining(cat._livesRemaining)
{
	_livesRemaining = 0;
	cat.setAge(0);
}

Cat::~Cat() {}

Cat& Cat::operator=(Cat&& c)
{
	if(this != &c)
	{
		_livesRemaining = c._livesRemaining;
		c._livesRemaining = 0;

		this->setAge(c.getAge());
		c.setAge(0);
	}
	return *this;
}

void Cat::voice()
{
	std::cout << "Meow meow!" << std::endl;
}

void Cat::info()
{
	std::cout << "Hi! I am " << getAge() << " years old Cat.";
}
