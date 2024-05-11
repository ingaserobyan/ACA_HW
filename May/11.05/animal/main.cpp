#include <vector>

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "duck.hpp"
#include "pig.hpp"
#include "bee.hpp"

#define vector std::vector

int fillZoo(vector<Animal*>& zoo)
{
	int count = 0;

	zoo.push_back(new Dog);
	++count;

	zoo.push_back(new Cat);
	++count;

	zoo.push_back(new Duck);
	++count;

	zoo.push_back(new Pig);
	++count;

	zoo.push_back(new Bee);
	++count;

	return count;
}

int main()
{
	vector<Animal*> zoo;
	int count = fillZoo(zoo);

	for (int i = 0; i < count; ++i)
	{
		zoo[i]->voice();
	}
	std::cout << std::endl;

	std::cout << "There are " << Animal::count << " animals in zoo" << std::endl;

	for (int i = 0; i < count; ++i)
	{
		delete zoo[i];
	}
	return 0;
}
