#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    string name;
    char   color;   // 'W' = White,  'B' = Black

public:
    Player(string name, char color);
    ~Player();

    string getName();
    char   getColor();

    bool makeMove(int& fromRow, int& fromCol, int& toRow, int& toCol);
};

#endif
