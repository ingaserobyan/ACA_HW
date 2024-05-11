#include "board.hpp"

Board::Board() : _size(d_size)
{
	_board = new Piece*[_size];
	for (int i = 0; i < _size; ++i)
	{
		_board[i] = nullptr;
	}
}

Board::~Board()
{
	for (int i = _size; i < _size; ++i)
		delete _board[i];
	delete[] _board;
}

void Board::show()
{
	for(int i = 0; i < _size; ++i)
	{
		for(int j = 0; j < _size; ++j)
		{
			_board[i][j].display();
		}
	}
}

Piece& Board::operator= (const Pawn& pawn)
{
	int i = pawn.getRow();
	int j = pawn.getCol();
	if (_board[i][j] == nullptr)
        {
            Pawn* newPawn = new Pawn(pawn.getColor(), pawn.getRow(), pawn.getCol());

            _board[i][j] = <Piece*> newPawn;
        }
	else
	{
		Pawn* oldPawn = &(_board[i][j]);
		Pawn* newPawn = new Pawn(pawn.getColor(), pawn.getRow(), pawn.getCol());
		_board[i][j] = newPawn;
	}
}

void Board::setBoard()
{
	int i = 1;
	for(int j = 0; j < d_size; ++j)
	{
		_board[i][j] = new Pawn(d_white, 1, j);
	}
}
