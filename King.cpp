#include "King.h"

King::King(char color, int row, int col) : Piece(color, row, col) {}
King::~King() {}

char King::getSymbol() {
    if (getColor() == 'W') {
        return 'K';
    }
    return 'k';
}

bool King::isValidMove(int fromRow, int fromCol,
    int toRow, int toCol,
    Piece* board[8][8]) {
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    int absRowDiff = 0;
    int absColDiff = 0;

    if (rowDiff < 0) {
        absRowDiff = rowDiff * -1;
    }
    else {
        absRowDiff = rowDiff;
    }

    if (colDiff < 0) {
        absColDiff = colDiff * -1;
    }
    else {
        absColDiff = colDiff;
    }

    if (absRowDiff == 0 && absColDiff == 0) {
        return false;
    }

    if (absRowDiff > 1 || absColDiff > 1) {
        return false;
    }

    if (board[toRow][toCol] == 0) {
        return true;
    }
    if (board[toRow][toCol]->getColor() != getColor()) {
        return true;
    }
    return false;
}
