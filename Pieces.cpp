#include "Piece.h"

Piece::Piece(char color, int row, int col) {
    this->color = color;
    this->row = row;
    this->col = col;
}

Piece::~Piece() {}

char Piece::getColor() {
    return this->color;
}
int  Piece::getRow() {
    return this->row;
}
int  Piece::getCol() {
    return this->col;
}

void Piece::setRow(int row) {
    this->row = row;
}
void Piece::setCol(int col) {
    this->col = col;
}
