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
			std::cout << std::endl;
			std::cout << "Car plate: " << _plate << std::endl;
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
	public:
		Parking(const int& capacity) : _capacity(capacity)
		{
			_parkingLot = new Car*[_capacity];
		}

		Parking(const Parking& p)
		{
			_capacity = p._capacity;
			_occupied = p._occupied;
			_parkingLot = new Car*[_capacity];
			for (int i = 0; i < _occupied; ++i)
			{
				_parkingLot[i] = new Car(*(p._parkingLot[i]));
			}
		}

		~Parking()
		{
			for (int i = 0; i < _occupied; ++i)
			{
				delete _parkingLot[i];
				_parkingLot[i] = nullptr;
			}
			delete[] _parkingLot;
		}

	public:
		bool parkCar(const Car& newCar)
		{
			bool result = false;
			if (_occupied < _capacity)
			{
				_parkingLot[_occupied] = new Car(newCar);
				_occupied++;
				result = true;
			}
			return result;
		}

	void info()
	{
		std::cout << "__________________" << std::endl;
		std::cout << "____PARK___LOT____" << std::endl << std::endl;
		for (int i = 0; i < _occupied; ++i)
		{
			std::cout << (i + 1) << " place:" << std::endl;
			_parkingLot[i]->info();
			std::cout << std::endl;
		}
		std::cout << "__________________" << std::endl;
		std::cout << "Available: " << (_capacity - _occupied) << std::endl;

	}



	private:
		Car**	_parkingLot = nullptr;
		int	_capacity = 0;
		int	_occupied = 0;
};

int main()
{
	Person driver1("Petros", "Petrosyan", true);
	Machine machine1("BMW", "Blue");
	Car car1(machine1, driver1, "34AU785");

	Person driver2("Martiros", "Martirosyan", true);
	Machine machine2("Mercedes", "Black");
	Car car2(machine2, driver2, "10AB234");


	Parking parking(5);
	parking.parkCar(car1);
	// parking.info();

	parking.parkCar(car2);
	parking.info();


	return 0;
}
