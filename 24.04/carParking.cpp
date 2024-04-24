#include <iostream>
#include <string>

class Person
{
	public:
		Person(const std::string& name, const std::string& surname, bool lisance) :	_name(name),
												_surname(surname),
												_driverLisance(lisance) {};

		Person(const Person& p)
		{
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
		bool		_driverLisance;

};

class Machine
{
	public:
		Machine(const std::string& model, const std::string& color) :	_model(model),
										_color(color) {};

		Machine(const Machine& m)
		{
			_model = m._model;
			_color = m._color;
		}

	public:
		void display()
		{
			std::cout << _color << " " << _model;
		}

	private:
		std::string	_model;
		std::string	_color;
};

class Car
{
	public:
		Car(const Machine& machine, const Person& driver, const std::string&  plate) :	_machine(machine),
												_driver(driver),
												_plate(plate) {};


	public:
		void info()
		{
			_machine.display();
			std::cout << " with car plate " << _plate << std::endl;
			std::cout << "The driver: ";
			_driver.display();
			std::cout << std::endl;
		}


	private:
		Machine		_machine;
		Person		_driver;
		std::string	_plate;

};

class Parking
{
	Parking(const int& capacity, const int& occupied = 0) : _capacity(capacity),
								_occupied(occupied)
	{

	}

	private:
		Car**	_parkingLot = nullptr;
		int	_capacity = 0;
		int	_occupied = 0;
};

int main()
{
	Person driver("Petros", "Petrosyan", true);
	Machine machine("BMW", "Blue");
	Car car(machine, driver, "34AU785");
	car.info();

	return 0;
}
