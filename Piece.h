#pragma once
#ifndef PIECE_H
#define PIECE_H

class Piece {
private:
    char color;   // 'W' = White,  'B' = Black
    int  row;     // 0 (top) to 7 (bottom)
    int  col;     // 0 (file a) to 7 (file h)

public:
    Piece(char color, int row, int col);
    virtual ~Piece();

    char getColor();
    int  getRow();
    int  getCol();

    void setRow(int row);
    void setCol(int col);

    virtual bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) = 0;
    virtual char getSymbol() = 0;
};

#endif
