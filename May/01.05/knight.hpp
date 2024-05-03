#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class Knight : public Piece
{
	public:
		Knight();
		Knight(bool, char, int);
		~Knight();

	public:
		void display() const override;

	private:
		bool validateMove(int, int) const override;


};

#endif // __KNIGHT_HPP__
