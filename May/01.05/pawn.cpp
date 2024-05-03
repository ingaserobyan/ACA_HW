#include "pawn.hpp"

Pawn::Pawn() : Piece(d_white, 'A', 2) {}

Pawn::Pawn(bool color, char col, int row) : Piece(color, col, row) {}

Pawn::~Pawn() {};

bool Pawn::validateMove(int row, int col) const
{

	if (_col != col)
        return false;
	if (getColor())
		return ((row - _row) == 1);
	else
		return ((_row - row) == 1);
}

void Pawn::display() const
{
	if (getColor())
		std::cout << "White";
	else
		std::cout << "Black";

	std::cout <<" Pawn ";
}
