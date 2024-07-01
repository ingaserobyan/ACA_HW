#include "car.hpp"

Car::Car(std::string model, int year) : _model(model), _year(year) {}

std::string Car::get_model() const {return _model;}
int			Car::get_year() const {return _year;}

bool Car::operator==(const Car& other) const
{
	return (_model == other._model && _year == other._year);
}
