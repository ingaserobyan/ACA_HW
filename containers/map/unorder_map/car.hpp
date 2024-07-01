#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <string>

class Car {
	public:
		Car(std::string model, int year);

		std::string get_model() const;
		int			get_year() const;

		bool operator==(const Car& other) const;

	private:
		std::string	_model;
		int			_year;
};

// Specialize std::hash for the Car class


#endif // __CAR_H__
