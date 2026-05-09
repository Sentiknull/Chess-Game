#pragma once
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(char color, int row, int col);
    ~Queen();

    char getSymbol();   // 'Q' = White,  'q' = Black
    bool isValidMove(int fromRow, int fromCol,
        int toRow, int toCol,
        Piece* board[8][8]);
};

#endif
