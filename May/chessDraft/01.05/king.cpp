#include "king.hpp"

King::King() : Piece(d_white, 'E', 1) {}

King::King(bool color, char col, int row) : Piece(color, col, row) {}

King::~King() {};

bool King::validateMove(int row, int col) const
{
	return(std::abs(row - _row) <= 1 && std::abs(col - _col) <= 1);
}

void King::display() const
{
	if (getColor())
		std::cout << "White";
	else
		std::cout << "Black";

	std::cout <<" King ";
}
