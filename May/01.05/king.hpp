#ifndef __KING_HPP__
#define __KING_HPP__

#include "piece.hpp"

class King : public Piece
{
	public:
		King();
		King(bool, char, int);
		~King() override;

	public:
		void display() const override;

	private:
		bool validateMove(int, int) const override;
};

#endif //__KING_HPP__
