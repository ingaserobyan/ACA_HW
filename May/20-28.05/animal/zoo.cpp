#include "zoo.hpp"

Zoo::Zoo() {}

Zoo::~Zoo() {}

Zoo& Zoo::getZoo()
{
	static Zoo zoo;
	return zoo;
}

void Zoo::addAnimal(Animal* animal)
{
	_zoo.push_back(animal);
}

Animal* Zoo::operator[] (int index) const
{
	return _zoo[index];
}

void	Zoo::display3max()
{
	int indecies[3] = {0, 1, 2};

	for(int i = 0; i < 3; ++i)
	{
		for (int j = i + 1; j < 3; ++j) {
			if (*_zoo[indecies[j]] >= *_zoo[indecies[i]]) {
				std::swap(indecies[i], indecies[j]);
			}
		}
	}

	for(std::size_t i = 3; i < _zoo.size(); ++i)
	{
		if(*_zoo[i] >= *_zoo[indecies[0]])
		{
			indecies[2] = indecies[1];
			indecies[1] = indecies[0];
			indecies[0] = i;
		}
		else if(*_zoo[i] >= *_zoo[indecies[1]])
		{
			indecies[2] = indecies[1];
			indecies[1] = i;
		}
		else if(*_zoo[i] >= *_zoo[indecies[2]])
		{
			indecies[2] = i;
		}
	}

	for(int i = 0; i < 3; ++i)
	{
		_zoo[indecies[i]]->info();
		std::cout << std::endl;
	}

}
