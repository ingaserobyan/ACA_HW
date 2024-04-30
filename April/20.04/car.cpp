#include <string>
#include <iostream>

class Car
{
	public:
		Car()
		{
			_brand = "Undefined";
			_color = "Undefined";
			_model = "Undefined";
			_year = 0;
			_engine = "Undefined";
			_fuel = "Undefined";
		}
		Car(const std::string& brand, const std::string& model, const std::string& color, const int& year, const std::string& engine, const std::string& fuel)
		{
			_brand = brand;
			_model = model;
			_color = color;
			_year = year;
			_engine = engine;
			_fuel = fuel;
		}

	public:
		void info() const
		{
			std::cout << "Brand: " << _brand << std::endl;
			std::cout << "Model: " << _model << std::endl;
			std::cout << "Color: " << _color << std::endl;
			std::cout << "Year: " << _year << std::endl;
			std::cout << "Engine: " << _engine << std::endl;
			std::cout << "Fuel: " << _fuel << std::endl;
		}

	private:
		std::string	_brand;
		std::string	_model;
		std::string	_color;
		int			_year;
		std::string	_engine;
		std::string	_fuel;
};

int main()
{
	Car newCar1;
	newCar1.info();

	std::cout << std::endl;

	Car newCar2("Ford Mustang", "Shelby GT500", "Silver",  2020, "5.2-liter supercharged V-8", "Premium unleaded gasoline");
	newCar2.info();

	return 0;
}
