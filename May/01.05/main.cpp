#include "pawn.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

int main()
{
	Piece*  pawn = new Pawn(d_white, 'B', 2);
	pawn->display();
	pawn->displayCoords();
	pawn->move('b', 3);
	pawn->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* knight = new Knight(d_white, 'B', 1);
	knight->display();
	knight->displayCoords();
	knight->move('A', 3);
	knight->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* rook = new Rook(d_white, 'A', 1);
	rook->display();
	rook->displayCoords();
	rook->move('A', 5);
	rook->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* bishop = new Bishop(d_white, 'F', 1);
	bishop->display();
	bishop->displayCoords();
	bishop->move('C', 4);
	bishop->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* queen = new Queen(d_white, 'D', 1);
	queen->display();
	queen->displayCoords();
	queen->move('F', 3);
	queen->displayCoords();

	std::cout << "-------------" << std::endl;
	Piece* king = new King(d_white, 'E', 1);
	king->display();
	king->displayCoords();
	king->move('F', 2);
	king->displayCoords();

	delete king;
	delete queen;
	delete bishop;
	delete rook;
	delete knight;
	delete pawn;

	return 0;
}
