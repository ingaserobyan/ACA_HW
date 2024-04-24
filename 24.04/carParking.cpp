#include <iostream>
#include <string>

class Person
{
	public:
		Person(const std::string& name, const std::string& surname, bool license) :	_name(name),
												_surname(surname),
												_driverLicense(license) {};

		Person(const Person& p)
		{
			_name = p._name;
			_surname = p._surname;
			_driverLicense = p._driverLicense;
		}

	public:
		bool	license() const{return _driverLicense;}
		void	display() const { std::cout << _name << " " << _surname;}

	private:
		std::string	_name;
		std::string	_surname;
		bool		_driverLicense;

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
		void display() const
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
		void info() const
		{
			_machine.display();
			std::cout << std::endl;
			std::cout << "Car plate: " << _plate << std::endl;
			std::cout << "The driver: ";
			_driver.display();
			std::cout << std::endl;
		}

		bool driverLicense() const {return _driver.license();}
		void driverInfo() const {_driver.display();}
		std::string	plate() const {return _plate;}

	private:
		Machine		_machine;
		Person		_driver;
		std::string	_plate;

};

class Parking
{
	public:
		Parking(const int& capacity) :	_capacity(capacity),
						_occupied(0)
		{
			_parkingLot = new Car*[_capacity];
			_payStatus = new bool[_capacity];
			for (int i = 0; i < _capacity; ++i)
			{
				_parkingLot[i] = nullptr;
				_payStatus[i] = false;
			}
		}

		Parking(const Parking& p) :	_capacity(p._capacity),
						_occupied(p._occupied)
		{
			_parkingLot = new Car*[_capacity];
			_payStatus = new bool[_capacity];
			for(int i = 0; i < _capacity; ++i)
			{
				_parkingLot[i] = new Car(*(p._parkingLot[i]));
				_payStatus[i] = p._payStatus[i];
			}
		}

		Parking& operator= (const Parking& p)
		{
			if (this != &p)
			{
				if (_capacity != p._capacity)
				{
					for (int i = 0; i <_capacity; ++i)
					{
						delete _parkingLot[i];
						_parkingLot[i] = nullptr;
					}
					delete[] _parkingLot;
					_capacity = p._capacity;
					_parkingLot = new Car*[_capacity];
					_payStatus = new bool[_capacity];
				}
				else
				{
					for (int i = 0; i < _capacity; ++i)
					{
						delete _parkingLot[i];
						_parkingLot[i] = nullptr;
					}
				}
				_occupied = p._occupied;
				for(int i = 0; i < _capacity; ++i)
				{
					_parkingLot[i] = new Car(*(p._parkingLot[i]));
					_payStatus[i] = p._payStatus[i];
				}
			}
			return *this;
		}

		~Parking()
		{
			for (int i = 0; i < _capacity; ++i)
			{
				delete _parkingLot[i];
				_parkingLot[i] = nullptr;
			}
			delete[] _parkingLot;
			delete[] _payStatus;
		}

	public:
		int	parkCar(const Car& newCar)
		{
			if (searchCar(newCar.plate())!= -1)
			{
				std::cout << "Tha car is already parked" << std::endl;
				return _capacity;
			}
			if (_occupied < _capacity)
			{
				if (newCar.driverLicense())
				{
					for (int i = 0; i < _capacity; ++i)
					{
						if (_parkingLot[i] == nullptr)
						{
							_parkingLot[i] = new Car(newCar);
							_occupied++;
							newCar.driverInfo();
							std::cout << ", you parked your car at place " << (i + 1) << std::endl;
							return i;
						}
					}
				}
				else
				{
					newCar.driverInfo();
					std::cout << " is not allowed to enter to Parking without license!" << std::endl;
				}
			}
			else
			{
				newCar.driverInfo();
				std::cout << ", there is no available place, sorry" << std::endl;
			}
			return _capacity;
		}

		bool	pay(const int& place)
		{
			bool result = false;
			if (place < _capacity)
			{
				char answer;
				std::cout << "Transfering money for ";
				_parkingLot[place]->driverInfo();
				std::cout << "'s car parking." << std::endl;
				_payStatus[place] = true;
				result = true;
			}
			else
				std::cout << "There is no parked car in " << (place + 1) << std::endl;
			return result;
		}

		bool	leaveParking(const int& place)
		{
			bool result = false;
			if (place < _capacity)
			{
				if ((_payStatus[place]))
				{
					_parkingLot[place]->driverInfo();
					std::cout << " Thanks and bye!" << std::endl;
					_payStatus[place] = false;
					delete _parkingLot[place];
					_parkingLot[place] = nullptr;
					_occupied--;
					result = true;
				}
				else
				{
					_parkingLot[place]->driverInfo();
					std::cout << ", you did not pay for parking, you cannot leave" << std::endl;
				}
			}
			else
				std::cout << "There is no parked car in " << (place + 1) << " place" << std::endl;
			return result;
		}

		void info() const
		{
			std::cout << "_____________________" << std::endl;
			std::cout << "____PARKING___LOT____" << std::endl << std::endl;
			for (int i = 0; i < _capacity; ++i)
			{
				if (_parkingLot[i])
				{
					std::cout << (i + 1) << " PLACE:" << std::endl;
					_parkingLot[i]->info();
					std::cout << std::endl;
				}
			}
			std::cout << "_____________________" << std::endl;
			std::cout << "Available: " << (_capacity - _occupied) << std::endl;
		}

		int	searchCar(const std::string& plate) const
		{
			for (int i = 0; i < _capacity; ++i)
			{
				if (_parkingLot[i])
				{
					if(_parkingLot[i]->plate() ==  plate)
						return i;
				}
			}
			return -1;
		}

	private:
		Car**	_parkingLot = nullptr;
		bool*	_payStatus;
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
	int car1Place = parking.parkCar(car1);
	int car2Place = parking.parkCar(car2);

	int car3place = parking.parkCar(car1);
	int car6place = parking.parkCar(car2);

	parking.info();

	if (!parking.leaveParking(car1Place))
	{
		parking.pay(car1Place);
		parking.leaveParking(car1Place);
	}

	parking.info();

	return 0;
}
