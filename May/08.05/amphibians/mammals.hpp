#ifndef __MAMMALS_HPP__
#define __MAMMALS_HPP__

#include "animal.hpp"

#define FAST true
#define SLOW false

class Mammals : virtual public Animal
{
	public:
		Mammals(const float&, const float&, const float&, const bool&);
		~Mammals();

	public:
		void run(const int&, const int&); // distance, time
		void setRuningMode(const bool&);
		bool getRuningMode();

	private:
		bool _runningLevel;
};

#endif // __MAMMALS_HPP__
