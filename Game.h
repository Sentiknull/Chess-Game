#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
private:
    Board  board;
    Player player1;       // White
    Player player2;       // Black
    int    currentTurn;   // 0 = player1,  1 = player2

    void clearScreen();

public:
    Game(string p1Name, string p2Name);
    ~Game();

    void start();
    void switchTurn();
    bool isGameOver();
};

#endif
