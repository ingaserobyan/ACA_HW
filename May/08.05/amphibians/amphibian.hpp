#ifndef __AMPHIBIAN_HPP__
#define __AMPHIBIAN_HPP__

#include <iostream>

#include "fish.hpp"
#include "mammals.hpp"

#define WATER true
#define LAND false

class Amphibian : public Fish, public Mammals
{
	public:
		Amphibian(const float&, const float&, const float&, const float&, const bool&, const bool&);
		~Amphibian() override;

	public:
		bool getLocation() const;
		void goTo(const bool&);
		void currentLocation() const;

	private:
		bool _currentLocation;

};


#endif // __AMPHIBIAN_HPP__
