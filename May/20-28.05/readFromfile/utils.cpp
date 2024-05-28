#include "utils.hpp"

bool	isInteger(const std::string& line)
{
	if (line.empty()) return false;

	if (line.length() > 11) return false;

	bool	hasDigits = false;
	char	c;
	for (size_t i = 0; i < line.length(); ++i)
	{
		c = line[i];
		if (i == 0 && (c == '+' || c == '-'))
			continue;
		if (!std::isdigit(c))
			return false;
		else
			hasDigits = true;
	}
	return hasDigits;
}

bool	isFloat(const std::string& line)
{
	if (line.empty()) return false;

	int	pointCount = 0;
	bool	hasDigits = false;

	for (size_t i = 0; i < line.length(); ++i)
	{
		char c = line[i];
		if (i == 0 && (c == '+' || c == '-'))
			continue;
		if (c == '.')
			pointCount++;
		else if (std::isdigit(c))
			hasDigits = true;
		else
			return false;
		if (pointCount > 1) return false;
	}

	return hasDigits && (pointCount == 1);
}
