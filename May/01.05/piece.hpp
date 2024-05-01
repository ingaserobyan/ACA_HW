#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#define d_white true
#define d_black false
#define d_size 8

#include <iostream>

class Piece
{
	public:
		Piece(bool, char, int);
		virtual ~Piece();

	public:
		virtual void move(char col = 'A', int row = 0) = 0;
		virtual	void display() const = 0;
		bool getColor() const;
		int	getRow() const;
		int getCol() const;
		void displayCoords() const;

	protected:
		virtual bool validateMove(int, int) const = 0;

	private:
		bool	_color;
		const char*	_letters = "ABCDEFG";
	protected:
		int	_row;
		int	_col;
};


#endif // __PIECE_HPP__