#pragma once
#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(char color, int row, int col);
    ~Pawn();

    char getSymbol();   // 'P' = White,  'p' = Black
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]);
};

#endif
