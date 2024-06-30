#include <map>
#include <string>
#include <iostream>

std::map<int, std::string>	getNumMap()
{
	std::map<int, std::string> map;
	map.insert(std::pair<int, std::string>(0, "Zero"));
	map.insert(std::pair<int, std::string>(1, "One"));
	map.insert(std::pair<int, std::string>(2, "Two"));
	map.insert(std::pair<int, std::string>(3, "Three"));
	map.insert(std::pair<int, std::string>(4, "Four"));
	map.insert(std::pair<int, std::string>(5, "Five"));
	map.insert(std::pair<int, std::string>(6, "Six"));
	map.insert(std::pair<int, std::string>(7, "Seven"));
	map.insert(std::pair<int, std::string>(8, "Eight"));
	map.insert(std::pair<int, std::string>(9, "Nine"));
	map.insert(std::pair<int, std::string>(10, "Ten"));
	return (map);
}

std::string	getNumStr(const int& num)
{
	std::map<int, std::string> map = getNumMap();
	return map[num];
}

int main()
{
	std::string number;
	for (int i = 0; i <= 10; ++i)
 	{
		number = getNumStr(i);
		std::cout  << number << std::endl;
	}
	return 0;
}
