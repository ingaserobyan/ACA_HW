#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "duck.hpp"
#include "pig.hpp"
#include "bee.hpp"

#include "zoo.hpp"

int main()
{
	Zoo& zoo = Zoo::getZoo();

	zoo.addAnimal(new Dog);
	zoo.addAnimal(new Cat);
	zoo.addAnimal(new Duck);
	zoo.addAnimal(new Pig);
	zoo.addAnimal(new Bee);

	for(int i = 0; i < Animal::count; ++i)
	{
		zoo[i]->voice();
	}

	for(int i = 0; i < Animal::count; ++i)
	{
		delete zoo[i];
	}

	return 0;
}
