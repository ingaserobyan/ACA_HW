#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"

class Queen : public Piece
{
	public:
		Queen();
		Queen(bool, char, int);
		~Queen() override;

	public:
		void display() const override;

	private:
		bool validateMove(int, int) const override;
};

#endif //__QUEEN_HPP__
