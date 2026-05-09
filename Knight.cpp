#include "Knight.h"

Knight::Knight(char color, int row, int col) : Piece(color, row, col) {}
Knight::~Knight() {}

char Knight::getSymbol() {
    if (getColor() == 'W') {
        return 'N';
    }
    return 'n';
}

bool Knight::isValidMove(int fromRow, int fromCol,
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

    // Valid L-shapes: (2,1) or (1,2)
    bool isLShape = false;
    if (absRowDiff == 2 && absColDiff == 1) { isLShape = true; }
    if (absRowDiff == 1 && absColDiff == 2) { isLShape = true; }

    if (isLShape == false) {
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
