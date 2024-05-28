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

	zoo.addAnimal(new Dog(8, 7));
	zoo.addAnimal(new Cat(9, 9));
	zoo.addAnimal(new Duck(4,true));
	zoo.addAnimal(new Pig(7, true));
	zoo.addAnimal(new Bee(2, 2.46));

	for(int i = 0; i < Animal::count; ++i)
	{
		zoo[i]->voice();
	}

	zoo.display3max();

	for(int i = 0; i < Animal::count; ++i)
	{
		delete zoo[i];
	}

	return 0;
}
