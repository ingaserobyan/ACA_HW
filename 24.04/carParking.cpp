#include <iostream>
#include <string>

class Person
{
	public:
		Person(const std::string& name, const std::string& surname, bool lisance) : _name(name), _surname(surname), _driverLisance(lisance) {}

		Person(const Person& p)
		{
			// std::cout << "CarPlate -> copy constructor called" << std::endl;
			_name = p._name;
			_surname = p._surname;
			_driverLisance = p._driverLisance;
		}

	public:
		bool	lisance() {return _driverLisance;}
		void	display() { std::cout << _name << " " << _surname;}

	private:
		std::string	_name;
		std::string	_surname;
		bool	_driverLisance;

};

class CarPlate
{
	public:
		CarPlate(const int& regionCode, const std::string& letters, const int& lastDigitis)
		{
			if (regionCode >= 100 || letters.length() > 2 || lastDigitis >= 1000)
				throw ;
			_regionCode = regionCode;
			_letters = letters;
			_lastDigits = lastDigitis;
		}

		CarPlate(const CarPlate& cp)
		{
			// std::cout << "CarPlate -> copy constructor called" << std::endl;
			_regionCode = cp._regionCode;
			_letters = cp._letters;
			_lastDigits = cp._lastDigits;
		}

	void display()
	{
		std::cout << _regionCode << _letters << _lastDigits;
	}

	private:
		int	_regionCode;
		std::string _letters;
		int _lastDigits;
};

class Car
{
	public:
		Car(const std::string& model, const std::string& color, const Person& driver, const CarPlate&  plate) : _model(model),
																												_color(color),
																												_driver(driver),
																												_plate(plate) {};


	public:
		void display()
		{
			std::cout << _color << " " << _model << " with car plate ";
			_plate.display();
			std::cout << std::endl;
			std::cout << "The driver: ";
			_driver.display();
			std::cout << std::endl;
		}


	private:
		std::string	_model;
		std::string	_color;
		Person	_driver;
		CarPlate	_plate;

};


int main()
{
	Person driver("Petros", "Petrosyan", true);
	CarPlate plate(34, "OU", 456);
	Car car("BMW", "Blue", driver, plate);
	car.display();

	return 0;
}