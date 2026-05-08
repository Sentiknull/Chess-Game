#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
private:
    Piece* grid[8][8];   // nullptr = empty square

    void clearBoard();

public:
    Board();
    ~Board();

    void initBoard();
    void displayBoard();
    bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
    bool isKingAlive(char color);
    bool isInCheck(char color);
    char getPieceColor(int row, int col);
};

#endif
