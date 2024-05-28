#ifndef __READ_PRINT_H__
#define __READ_PRINT_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "utils.hpp"
#include "data.hpp"

class	ReadPrint
{
public:
	ReadPrint(std::ifstream&);
	~ReadPrint() = default;

	void	print() const;
	void	read();

private:
	void	organiseLine(const std::string &line);

private:
	std::vector<data>	_lines;
	std::ifstream&	_file;
};

#endif // __READ_PRINT_H__
