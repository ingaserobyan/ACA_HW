#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#define d_white true
#define d_black false
#define d_size 8

#include <iostream>

class Piece
{
	public:
		Piece(bool color, int row, int col);
		~Piece();

	public:
		virtual void move() = 0;
		virtual	void display() = 0;
		bool getColor() const;
		int	getRow() const;
		int getCol() const;

	private:
		bool	_color;
	protected:
		int	_row;
		int	_col;
};


#endif // __PIECE_HPP__