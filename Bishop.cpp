#include "Bishop.h"

Bishop::Bishop(char color, int row, int col) : Piece(color, row, col) {}
Bishop::~Bishop() {}

char Bishop::getSymbol() {
    if (getColor() == 'W') {
        return 'B';
    }
    return 'b';
}

bool Bishop::isValidMove(int fromRow, int fromCol,
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

    if (absRowDiff != absColDiff) {
        return false;
    }
    if (absRowDiff == 0) {
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
