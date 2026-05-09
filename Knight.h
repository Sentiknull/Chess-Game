#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(char color, int row, int col);
    ~Knight();

    char getSymbol();   // 'N' = White,  'n' = Black
    bool isValidMove(int fromRow, int fromCol,
        int toRow, int toCol,
        Piece* board[8][8]);
};

#endif
