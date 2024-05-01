#include "rook.hpp"

Rook::Rook(bool color, char col, int row) : Piece(color, col, row) {}

Rook::~Rook() {}

void Rook::display() const
{
	if (getColor())
	{
		std::cout << "White";
	}
	else
	{
		std::cout << "Black";
	}
	std::cout <<" Rook ";
}

bool Rook::validateMove(int row, int col) const
{
	return (_row == row || _col == col);
}

void Rook::move(char col_u, int row)
{
	int col = 0;
	if(row < 1 || row > 8)
	{
		std::cout << "Not valid Coordinate" << std::endl;
		return ;
	}
	if (col_u >= 'A' && col_u <= 'Z')
		col = col_u - 'A';
	else if (col_u >= 'a' && col_u <= 'z')
		col = col_u - 'a';
	else
	{
		std::cout << "Not valid Coordinate" << std::endl;
		return ;
	}

	--row;
	if(validateMove(row, col))
	{
		_row = row;
		_col = col;
	}
	else
	{
		std::cout << "Cannot move" << std::endl;
		return ;
	}
}