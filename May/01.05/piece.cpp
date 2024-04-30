#include "piece.hpp"

Piece::Piece(bool color, int row, int col) : _color(color), _row(row), _col(col) {}

Piece::~Piece() {}

bool Piece::getColor() const {return _color;}

int	Piece::getRow() const {return _row;}


int Piece::getCol() const {return _col;}
