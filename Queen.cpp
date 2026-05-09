#include "Queen.h"

Queen::Queen(char color, int row, int col) : Piece(color, row, col) {}
Queen::~Queen() {}

char Queen::getSymbol() {
    if (getColor() == 'W') {
        return 'Q';
    }
    return 'q';
}

bool Queen::isValidMove(int fromRow, int fromCol,
    int toRow, int toCol,
    Piece* board[8][8]) {
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    if (rowDiff == 0 && colDiff == 0) {
        return false;
    }

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

    bool isStraight = false;
    if (fromRow == toRow || fromCol == toCol) {
        isStraight = true;
    }

    bool isDiagonal = false;
    if (absRowDiff == absColDiff) {
        isDiagonal = true;
    }

    if (isStraight == false && isDiagonal == false) {
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
