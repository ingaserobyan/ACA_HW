#include "knight.hpp"

Knight::Knight() : Piece(d_white, 'B', 1) {}

Knight::Knight(bool color, char col, int row) : Piece(color, col, row) {}

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
