#ifndef __ZOO_HPP__
#define __ZOO_HPP__

#include <vector>

#include "animal.hpp"

#ifndef vector
# define vector std::vector
#endif

class Zoo
{
	private:
		Zoo();
		Zoo(const Zoo&) = delete;
		~Zoo();

	public:
		static Zoo& getZoo();
		void addAnimal(Animal*);

	public:
		Animal* operator[] (int) const;
		void	display3max();

	private:
		vector<Animal*> _zoo;
};

#endif // __ZOO_HPP__
