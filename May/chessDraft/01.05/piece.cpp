#include "piece.hpp"

Piece::Piece(bool color, char col_u, int row) : _color(color)
{
	int col = 0;
	if(!validateInput(col_u, row, col))
		return ;

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

bool	Piece::validateInput(const char& col_u, const int& row, int& col)
{
	col = 0;
	if(row < 1 || row > 8)
	{
		std::cout << "Not valid Coordinate" << std::endl;
		return false;
	}
	if (col_u >= 'A' && col_u <= 'Z')
		col = col_u - 'A';
	else if (col_u >= 'a' && col_u <= 'z')
		col = col_u - 'a';
	else
	{
		std::cout << "Not valid Coordinate" << std::endl;
		return false;
	}
	return true;
}

void Piece::move(char col_u, int row)
{
	int col = 0;
	if(!validateInput(col_u, row, col))
		return ;

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
