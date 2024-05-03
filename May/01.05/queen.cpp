#include "queen.hpp"

Queen::Queen() : Piece(d_white, 'D', 1) {}

Queen::Queen(bool color, char col, int row) : Piece(color, col, row) {}

Queen::~Queen() {};

bool Queen::validateMove(int row, int col) const
{
	return(row == _row || col == _col || std::abs(row - _row) == std::abs(col - _col));
}

void Queen::display() const
{
	if (getColor())
		std::cout << "White";
	else
		std::cout << "Black";

	std::cout <<" Queen ";
}
