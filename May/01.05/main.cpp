#include "pawn.hpp"
#include "knight.hpp"
#include "rook.hpp"

int main()
{
	Piece*  pawn = new Pawn(d_white, 'B', 2);
	pawn->display();
	pawn->displayCoords();
	pawn->move();
	pawn->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* knight = new Knight(d_white, 'B', 1);
	knight->display();
	knight->displayCoords();
	knight->move('B', 3);
	knight->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* rook = new Rook(d_white, 'A', 1);
	rook->display();
	rook->displayCoords();
	rook->move('A', 5);
	rook->displayCoords();

	delete pawn;
	delete knight;
	delete rook;

	return 0;
}