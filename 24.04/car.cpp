#include <iostream>
#include <string>

class CarPlate
{
	public:
		CarPlate(const int& regionCode, const std::string& letters, const int& lastDigitis)
		{
			if (regionCode >= 100 || letters.length() > 2 || lastDigitis >= 1000)
				return ;
			_regionCode = regionCode;
			_letters = letters;
			_lastDigits = lastDigitis;
		}

	private:
		int	_regionCode;
		std::string _letters;
		int _lastDigits;
};

class Person
{
	public:
		Person(const std::string& name, const std::string& surname, bool lisance) : _name(name), _surname(surname), _driverLisance(lisance) {}

	public:
		bool	lisance() {return _driverLisance;}
		void	introduce() { std::cout << "I am " << _name << " " << _surname << std::endl;}

	private:
		std::string	_name;
		std::string	_surname;
		bool	_driverLisance;

};

class Car
{
	public:


	private:
		std::string	_model;
		std::string	_color;
		CarPlate	_plateNum;


};


class Parking
{


	private:
		int	_capacity;
		int	_size;
		// will be a pointer to matrix holding owner and car
		// Driver _owner;
		// Car	_car;
};

int main()
{

}