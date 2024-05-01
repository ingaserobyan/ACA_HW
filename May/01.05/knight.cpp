#include "knight.hpp"

Knight::Knight(bool color, int row, int col) : Piece(color, row, col) {}

Knight::~Knight() {}

bool Knight::validateMove(int row, int col) const
{
    int rowDiffs[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int colDiffs[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < 8; ++i) {
        if ((_row - row) == rowDiffs[i] && (_col - col) == colDiffs[i])
            return true;
    }
    return false;
}

void Knight::move(char col_u, int row)
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
		// I will need to connect with and do changes in board class as well
		_row = row;
		_col = col;
	}
	else
	{
		std::cout << "Cannot move" << std::endl;
		return ;
	}
}

void Knight::display() const
{
	if (getColor())
	{
		std::cout << "White";
	}
	else
	{
		std::cout << "Black";
	}
	std::cout <<" Knight ";
}