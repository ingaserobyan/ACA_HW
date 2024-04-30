#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"

class Pawn : public Piece
{
	public:
		Pawn();
		Pawn(bool, int, int);
		~Pawn();

	public:
		void move() override;
		void display() override;
};

#endif //__PAWN_HPP__