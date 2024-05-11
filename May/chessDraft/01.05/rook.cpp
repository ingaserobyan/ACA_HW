#include "rook.hpp"

Rook::Rook( ) : Piece(d_white, 'A', 1) {}

Rook::Rook(bool color, char col, int row) : Piece(color, col, row) {}

Rook::~Rook() {}

void Rook::display() const
{
	if (getColor())
		std::cout << "White";
	else
		std::cout << "Black";

	std::cout << " Rook ";
}

bool Rook::validateMove(int row, int col) const
{
	return (_row == row || _col == col);
}
