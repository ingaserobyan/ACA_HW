#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "piece.hpp"
#include "pawn.hpp"

class Board
{
	public:
		Board();
		~Board();

	public:
		Piece& operator= (const Pawn& pawn);

	public:
		void show();
		void setBoard();

	private:
		Piece**	_board;
		int	_size;
};

#endif // __BOARD_HPP__

/*
BK
WK
WQ
WB
WR
*/
