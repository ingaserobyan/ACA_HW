#include <iostream>
#include <fstream>

#include "readPrint.hpp"

int main()
{
	std::ifstream inputFile("TXT.txt");

    if (!inputFile.is_open())
	{
		std::cerr << "Error: Cannot open file." << std::endl;
    	return 1;
    }

	ReadPrint filePrinter(inputFile);
	filePrinter.read();

	filePrinter.print();

	inputFile.close();

	return 0;
}
