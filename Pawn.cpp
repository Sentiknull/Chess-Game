#include "Pawn.h"

Pawn::Pawn(char color, int row, int col) : Piece(color, row, col) {}
Pawn::~Pawn() {}

char Pawn::getSymbol() {
    if (getColor() == 'W') {
        return 'P';
    }
    return 'p';
}

bool Pawn::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) {
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    int direction = 0;
    int startRow = 0;

    if (getColor() == 'W') {
        direction = -1;   // White moves up
        startRow = 6;
    }
    else {
        direction = 1;    // Black moves down
        startRow = 1;
    }

    // Straight forward
    if (colDiff == 0) {
        if (rowDiff == direction) {
            if (board[toRow][toCol] == 0) {
                return true;
            }
            return false;
        }

        if (rowDiff == 2 * direction) {
            if (fromRow == startRow) {
                int midRow = fromRow + direction;
                if (board[midRow][fromCol] == 0 && board[toRow][toCol] == 0) {
                    return true;
                }
            }
            return false;
        }

        return false;
    }

    // Diagonal capture
    if (rowDiff == direction) {
        if (colDiff == 1 || colDiff == -1) {
            if (board[toRow][toCol] != 0) {
                if (board[toRow][toCol]->getColor() != getColor()) {
                    return true;
                }
            }
        }
    }

    return false;
}
