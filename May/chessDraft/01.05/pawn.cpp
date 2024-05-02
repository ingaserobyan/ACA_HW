#include "pawn.hpp"

Pawn::Pawn() : Piece(d_white, 1, 1) {}

Pawn::Pawn(bool color, int row, int col) : Piece(color, row, color) {}

Pawn::~Pawn() {};

void Pawn::move()
{
	if(getColor())
	{
		if(_row > 0 && _row < d_size)
			_row++;
		else
			throw ;
	}
	else
	{
		if(_row >= 0 && _row < (d_size - 1))
			_row--;
		else
			throw ;
	}
}

void Pawn::display()
{
	if (getColor())
	{
		std::cout << "White";
	}
	else
	{
		std::cout << "Black ";
	}
	std::cout <<" Pawn";
}