#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class Knight : public Piece
{
	public:
		Knight(bool, int, int);
		~Knight();

	public:
		void move(char, int) override;
		void display() const override;

	private:
		bool validateMove(int, int) const override;


};

#endif // __KNIGHT_HPP__
