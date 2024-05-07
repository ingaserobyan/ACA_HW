#include "amphibian.hpp"

int main()
{
	Amphibian* frog = new Amphibian(10, 0.1, 0.2, 2, FAST, WATER);
	std::cout << "Intitial weight: " << frog->getWeight() << std::endl;
	frog->eat(5);
	std::cout << "After eating: " << frog->getWeight() << std::endl;
	for(int i = 0; i < 3; ++i)
	{
		if(frog->getLocation())
		{
			frog->swim(5);
			frog->goTo(LAND);
			std::cout << " after swiming: " << frog->getWeight() << std::endl;
		}
		else
		{
			frog->run(10, 2);
			std::cout << " after running ";
			if(frog->getRuningMode())
				std::cout << "fast : ";
			else
				std::cout << "slow : ";
			std::cout << frog->getWeight() << std::endl;
			frog->setRuningMode(SLOW);
		}
	}

	delete frog;
	return 0;
}
