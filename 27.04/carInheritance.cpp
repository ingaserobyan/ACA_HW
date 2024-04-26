#include <iostream>
#include <string>

class Engine
{
public:
	Engine(const int& hp, const int& wheels, const std::string& fuelType) : _hp(hp),
									_wheels(wheels),
									_fuelType(fuelType) {};

private:
	int	_hp;
	int _wheels;
	std::string	_fuelType;
};

class Car : public Engine
{
public:
	Car(const int& hp, const int& wheels, const std::string& fuelType, const int& seats, const std::string& model) : Engine(hp, wheels, fuelType),
												_seats(seats),
												_model(model) {};
private:
	int	_seats;
	std::string	_model;
};

class Motorcycle : public Engine
{
public:
	Motorcycle (const int& hp, const int& wheels, const std::string& fuelType, const int& maxSpeed, const int& weight) : Engine(hp, wheels, fuelType),
																		_maxSpeed(maxSpeed),
																		_weight(weight) {};

private:
	int _maxSpeed;
	int _weight;
};

class Airplane : public Engine
{
public:
	Airplane (const int& hp, const int& wheels, const std::string& fuelType, const int& wingSpan, const int& range) : Engine(hp, wheels, fuelType),
																		_wingSpan(wingSpan),
																		_range (range) {};

private:
	int _wingSpan;
	int _range;
};

class SportCar : public Car
{
public:
	SportCar ()

};

class Mercedes : public Car
{

};

class Toyota : public Car
{

};

int main()
{

	return 0;
}
