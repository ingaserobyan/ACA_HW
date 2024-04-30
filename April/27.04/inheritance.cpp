#include <iostream>
#include <string>

class Engine
{
public:
	Engine(const int& hp, const int& wheels, const std::string& fuelType)
		:	_hp(hp),
			_wheels(wheels),
			_fuelType(fuelType) {}

public:
	int getHorsepower() const { return _hp; }
    int getWheels() const { return _wheels; }
    std::string getFuelType() const { return _fuelType; }

	void info() const
	{
		std::cout << "Wheels: " << _wheels << std::endl;
		std::cout << "HP: " << _hp << std::endl;
		std::cout << "Fuel type: " << _fuelType << std::endl;
	}

private:
	int	_hp;
	int _wheels;
	std::string	_fuelType;
};

class Car : public Engine
{
public:
	Car(const int& hp, const int& wheels, const std::string& fuelType, const int& seats, const std::string& color, const std::string& model)
		:	Engine(hp, wheels, fuelType),
			_seats(seats),
			_color(color),
			_model(model) {}
public:
	int getSeats() const { return _seats; }
    std::string getColor() const { return _color; }
    std::string getModel() const { return _model; }

	void info() const
	{
		std::cout << _color << " " << _model << " with " << _seats << " seats" << std::endl;
		Engine::info();
	}

private:
	int	_seats;
	std::string	_color;
	std::string	_model;
};

///// Car child classes ////
class SportCar : public Car
{
public:
	SportCar (const int& hp, const int& wheels, const std::string& fuelType, const int& seats, const std::string& color, const std::string& model, const int& topSpeed)
		:	Car(hp, wheels, fuelType, seats, color, model),
			_topSpeed(topSpeed){}
public:
	int getTopSpeed() const { return _topSpeed; }

	void info() const
	{
		Car::info();
		std::cout << "Top spead: " << _topSpeed << std::endl;
	}

private:
	int	_topSpeed;
};

class FamilyCar : public Car
{
public:
	FamilyCar (const int& hp, const int& wheels, const std::string& fuelType, const int& seats, const std::string& color, const std::string& model, const bool& babySeat)
		:	Car(hp, wheels, fuelType, seats, color, model),
			_babySeat(babySeat) {}
public:
	bool checkBabySear() const { return _babySeat; }

	void info() const
	{
		Car::info();
		std::cout << "Baby seat: ";
		if (_babySeat)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

private:
	bool	_babySeat;
};

class LuxeCar : public Car
{
public:
	LuxeCar (const int& hp, const int& wheels, const std::string& fuelType, const int& seats, const std::string& color, const std::string& model, const bool& miniBar)
		:	Car(hp, wheels, fuelType, seats, color, model),
			_miniBar(miniBar) {}
public:
	bool checkMiniBar() const { return _miniBar; }

	void info() const
	{
		Car::info();
		std::cout << "Mini Bar: ";
		if (_miniBar)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

private:
	bool	_miniBar;
};

///////////////////////////


class Motorcycle : public Engine
{
public:
	Motorcycle (const int& hp, const int& wheels, const std::string& fuelType, const int& maxSpeed, const int& weight, const std::string& model)
	:	Engine(hp, wheels, fuelType),
		_maxSpeed(maxSpeed),
		_weight(weight),
		_model(model) {};

public:
	int getMaxSpeed() const { return _maxSpeed; }
    int getWeight() const { return _weight; }
	std::string	getModel() {return _model; }


	void info() const
	{
		std::cout << _model << " with max speed " << _maxSpeed  << " and weight " << _weight << std::endl;
		Engine::info();
	}

private:
	int	_maxSpeed;
	int	_weight;
	std::string	_model;
};

//// Motorcycle child classes /////
class SportBike : public Motorcycle
{
public:
    SportBike(const int& hp, const int& wheels, const std::string& fuelType, const int& maxSpeed, const int& weight, const std::string& model, const bool& raceMode)
	: Motorcycle(hp, wheels, fuelType, maxSpeed, weight, model), _raceMode(raceMode) {}

public:
    bool RaceMode() const { return _raceMode; }

	void info() const
	{
		Motorcycle::info();
		std::cout << "Race mode: ";
		if (_raceMode)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

private:
    bool _raceMode;
};

class Scooter : public Motorcycle
{
public:
    Scooter(const int& hp, const int& wheels, const std::string& fuelType, const int& maxSpeed, const int& weight, const std::string& model, const bool&	storage)
    	:	Motorcycle(hp, wheels, fuelType, maxSpeed, weight, model),
			_storage(storage) {}

public:
    bool hasStorage() const { return _storage; }

	void info() const
	{
		Motorcycle::info();
		std::cout << "Storage: ";
		if (_storage)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

private:
    bool _storage;
};

class ElectricBike : public Motorcycle
{
public:
    ElectricBike (const int& hp, const int& wheels, const int& maxSpeed, const int& weight, const std::string& model, const int& batteryCapacity)
    	:	Motorcycle(hp, wheels, "Electric", maxSpeed, weight, model),
			_batteryCapacity(batteryCapacity) {}
public:
    int getBatteryCapacity() const { return _batteryCapacity; }

	void info() const
	{
		Motorcycle::info();
		std::cout << "Battery capacity: " << _batteryCapacity  << std::endl;
	}


private:
    int _batteryCapacity;
};

//////////////////////////////////

class Airplane : public Engine
{
public:
	Airplane (const int& hp, const int& wheels, const std::string& fuelType, const int& wingSpan, const int& range, const std::string& model)
		:	Engine(hp, wheels, fuelType),
			_wingSpan(wingSpan),
			_range (range),
			_model(model) {};

public:
	int getWingSpan() const { return _wingSpan; }
	int getRange() const { return _range; }
	std::string getModel() const {return _model; }

	void info() const
	{
		std::cout << _model << " with " << _wingSpan << " wingspan and " << _range << " range" << std::endl;
		Engine::info();
	}

private:
	int _wingSpan;
	int _range;
	std::string	_model;
};

////// Airplane child classes //////

class CommercialJet : public Airplane
{
public:
    CommercialJet (const int& hp, const int& wheels, const std::string& fuelType, const int& wingSpan, const int& range, const std::string& model, const int& passengerCapacity)
    	:	Airplane(hp, wheels, fuelType, wingSpan, range, model),
			_passengerCapacity(passengerCapacity) {}

public:
    int getPassengerCapacity() const { return _passengerCapacity; }

	void info() const
	{
		Airplane::info();
		std::cout << "Passenger capacity: " << _passengerCapacity << std::endl;
	}

private:
    int _passengerCapacity;
};

class CargoPlane : public Airplane
{
public:
    CargoPlane(const int& hp, const int& wheels, const std::string& fuelType, const int& wingSpan, const int& range, const std::string& model, const int& cargoCapacity)
    	:	Airplane(hp, wheels, fuelType, wingSpan, range, model),
			_cargoCapacity(cargoCapacity) {}

public:
    int getCargoCapacity() const { return _cargoCapacity; }

	void info() const
	{
		Airplane::info();
		std::cout << "Cargo capacity: " << _cargoCapacity << std::endl;
	}

private:
    int _cargoCapacity;
};

class PrivateJet : public Airplane
{
public:
    PrivateJet(const int& hp, const int& wheels, const std::string& fuelType, const int& wingSpan, const int& range, const std::string& model, const std::string& owner)
    	:	Airplane(hp, wheels, fuelType, wingSpan, range, model),
			_owner(owner) {}

public:
    std::string getOwner() const { return _owner; }

	void info() const
	{
		Airplane::info();
		std::cout << "Owner: " << _owner << std::endl;
	}

private:
    std::string _owner;
};

///////////////////////////////////

int main()
{
    SportCar sportCar(500, 4, "Petrol", 2, "Red", "Ferrari", 300);
    FamilyCar familyCar(200, 4, "Gasoline", 5, "Blue", "Toyota", true);
    LuxeCar luxeCar(600, 4, "Petrol", 4, "Black", "Rolls Royce", true);
    SportBike sportBike(200, 2, "Petrol", 250, 200, "Yamaha R1", true);
    ElectricBike electricBike(150, 2, 200, 180, "Harley Davidson Livewire", 100);
    Scooter scooter(50, 2, "Petrol", 80, 100, "Honda Activa", true);
    CommercialJet commercialJet(50000, 18, "Aviation Fuel", 40, 10000, "Boeing 737", 200);
    CargoPlane cargoPlane(80000, 18, "Aviation Fuel", 50, 8000, "Airbus A330", 50000);
    PrivateJet privateJet(60000, 16, "Aviation Fuel", 45, 5000, "Cessna Citation", "John");

    sportCar.info();
    std::cout << std::endl;

    familyCar.info();
    std::cout << std::endl;

    luxeCar.info();
    std::cout << std::endl;

    sportBike.info();
    std::cout << std::endl;

    electricBike.info();
    std::cout << std::endl;

    scooter.info();
    std::cout << std::endl;

    commercialJet.info();
    std::cout << std::endl;

    cargoPlane.info();
    std::cout << std::endl;

    privateJet.info();

    return 0;
}
