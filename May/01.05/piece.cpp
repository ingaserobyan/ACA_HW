#include "piece.hpp"

Piece::Piece(bool color, char col_u, int row) : _color(color)
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
	_row  = row;
	_col = col;
}

Piece::~Piece() {}

bool Piece::getColor() const {return _color;}

int	Piece::getRow() const {return _row;}

int Piece::getCol() const {return _col;}

void Piece::displayCoords() const
{
	std::cout << _letters[_col] << (_row + 1) << std::endl;
}