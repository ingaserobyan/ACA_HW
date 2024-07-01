#include "car.hpp"
#include <unordered_map>

namespace std {
    template<>
    struct hash<Car>
	{
        std::size_t operator()(const Car& car) const
		{
            return hash<std::string>()(car.get_model()) ^ hash<int>()(car.get_year());
        }
    };
}

int main()
{
	std::unordered_map<Car, int>	carShop;

	Car	car1("BMW", 2020);
	Car	car2("Mersedes", 2018);
	Car	car3("Toyota", 2015);
	Car	car4("Honda", 2010);

	carShop[car1] = 40000;
    carShop[car2] = 35000;
    carShop[car3] = 20000;
    carShop[car4] = 15000;

	std::cout << car1.get_model() << ": $" << carShop[car1] << std::endl;
    std::cout << car2.get_model() << ": $" << carShop[car2] << std::endl;
    std::cout << car3.get_model() << ": $" << carShop[car3] << std::endl;
    std::cout << car4.get_model() << ": $" << carShop[car4] << std::endl;

	return 0;
}
