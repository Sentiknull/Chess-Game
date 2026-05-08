#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(char color, int row, int col);
    ~Bishop();

    char getSymbol();   // 'B' = White,  'b' = Black
    bool isValidMove(int fromRow, int fromCol,
        int toRow, int toCol,
        Piece* board[8][8]);
};

#endif
