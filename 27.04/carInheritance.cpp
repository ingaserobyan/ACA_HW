#include <iostream>

class Car
{
public:
	Car(const int& wheels, const int& seats, const std::string& engine) :	_wheels(wheels),
														_seats(seats),
														_engine(engine) {}
private:
	int	_wheels;
	int _seats;
	std::string	_engine;
};

/*
                 ________________Car______________________
                /                 |                       \
               /                  |                        \
              /                   |                         \
    Passengers                  Cargo                        working
 _____|_______                ____|_____                _________|___________
/     |       \              /    |     \              /         |           \
bus   family    common    Light  Middle  Heavy  Agrigulture  Construction   Fisrt Aid

*/


int main()
{

	return 0;
}
