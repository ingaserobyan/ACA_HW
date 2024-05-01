#include "pawn.hpp"

Pawn::Pawn() : Piece(d_white, 1, 1) {}

Pawn::Pawn(bool color, int row, int col) : Piece(color, row, col) {}

Pawn::~Pawn() {};

bool Pawn::validateMove(int row, int col) const
{
	if (_col != col)
    {
        return false;
    }
	if (getColor())
	{
		return ((_row - row) == 1);
	}
	else
	{
		return ((row - _row) == 1);
	}
}

void Pawn::move(char, int)
{
	if(getColor())
	{
		if(_row > 0 && _row < d_size)
			_row++;
		else
		{
			std::cout << "Cannot move" << std::endl;
			return ;
		}
	}
	else
	{
		if(_row >= 0 && _row < (d_size - 1))
			_row--;
		else
		{
			std::cout << "Cannot move" << std::endl;
			return ;
		}
	}
}

void Pawn::display() const
{
	if (getColor())
	{
		std::cout << "White";
	}
	else
	{
		std::cout << "Black";
	}
	std::cout <<" Pawn ";
}