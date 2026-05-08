#include "Rook.h"

Rook::Rook(char color, int row, int col) : Piece(color, row, col) {}
Rook::~Rook() {}

char Rook::getSymbol() {
    if (getColor() == 'W') {
        return 'R';
    }
    return 'r';
}

bool Rook::isValidMove(int fromRow, int fromCol,
    int toRow, int toCol,
    Piece* board[8][8]) {
    if (fromRow != toRow && fromCol != toCol) {
        return false;
    }

    if (fromRow == toRow && fromCol == toCol) {
        return false;
    }

    int rowStep = 0;
    int colStep = 0;

    if (toRow > fromRow) { rowStep = 1; }
    if (toRow < fromRow) { rowStep = -1; }
    if (toCol > fromCol) { colStep = 1; }
    if (toCol < fromCol) { colStep = -1; }

    int r = fromRow + rowStep;
    int c = fromCol + colStep;

    while (r != toRow || c != toCol) {
        if (board[r][c] != 0) {
            return false;
        }
        r = r + rowStep;
        c = c + colStep;
    }

    if (board[toRow][toCol] == 0) {
        return true;
    }
    if (board[toRow][toCol]->getColor() != getColor()) {
        return true;
    }
    return false;
}
