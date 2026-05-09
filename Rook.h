#pragma once
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(char color, int row, int col);
    ~Rook();

    char getSymbol();   // 'R' = White,  'r' = Black
    bool isValidMove(int fromRow, int fromCol,
        int toRow, int toCol,
        Piece* board[8][8]);
};

#endif
