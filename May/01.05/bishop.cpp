#include "bishop.hpp"

Bishop::Bishop() : Piece(d_white, 'C', 1) {}

Bishop::Bishop(bool color, char col, int row) : Piece(color, col, row) {}

Bishop::~Bishop() {};

bool Bishop::validateMove(int row, int col) const
{
	return (std::abs(row - _row) == std::abs(col - _col));
}

void Bishop::display() const
{
	if (getColor())
		std::cout << "White";
	else
		std::cout << "Black";

	std::cout <<" Bishop ";
}
