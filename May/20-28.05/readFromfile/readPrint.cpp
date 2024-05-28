#include "readPrint.hpp"

ReadPrint::ReadPrint(std::ifstream& file) : _file(file) {}

void	ReadPrint::print () const
{
	for (size_t i = 0; i < _lines.size(); ++i)
	{
		const data& line = _lines[i];
		switch (line.type)
		{
			case data::INTEGER:
				std::cout << line.u_i << std::endl;
				break;
			case data::FLOAT:
				std::cout << line.u_f << std::endl;
				break;
			case data::STRING:
				std::cout << *(line.u_s) << std::endl;
				break;
		}
	}
}

void	ReadPrint::read()
{
	std::string line;
	while (std::getline(_file, line))
		organiseLine(line);
}

void	ReadPrint::organiseLine(const std::string& line)
{
	if(isInteger(line))
	{
		int i = std::stoi(line);
		_lines.emplace_back(i);
	}
	else if(isFloat(line))
	{
		float f = std::stof(line);
		_lines.emplace_back(f);
	}
	else
		_lines.emplace_back(line);
}
