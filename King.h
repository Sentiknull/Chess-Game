#pragma once
#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(char color, int row, int col);
    ~King();

    char getSymbol();   // 'K' = White,  'k' = Black
    bool isValidMove(int fromRow, int fromCol,
        int toRow, int toCol,
        Piece* board[8][8]);
};

#endif
