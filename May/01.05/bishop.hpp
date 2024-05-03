#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "piece.hpp"

class Bishop : public Piece
{
	public:
		Bishop();
		Bishop(bool, char, int);
		~Bishop() override;

	public:
		void display() const override;

	private:
		bool validateMove(int, int) const override;
};

#endif //__BISHOP_HPP__
