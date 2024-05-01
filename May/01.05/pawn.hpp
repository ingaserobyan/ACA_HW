#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"

class Pawn : public Piece
{
	public:
		Pawn();
		Pawn(bool, int, int);
		~Pawn() override;

	public:
		void move(char, int) override;
		void display() const override;

	private:
		bool validateMove(int, int) const override;
};

#endif //__PAWN_HPP__