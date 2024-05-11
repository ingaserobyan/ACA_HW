#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "piece.hpp"

class Rook : public Piece
{
	public:
		Rook();
		Rook(bool, char, int);
		~Rook() override;

	public:
		void display() const override;

	protected:
		bool validateMove(int, int) const override;
};

#endif // __ROOK_HPP__
