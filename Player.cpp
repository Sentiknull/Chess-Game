#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player::Player(string name, char color) {
    this->name = name;
    this->color = color;
}

Player::~Player() {}

string Player::getName() { return this->name; }
char   Player::getColor() { return this->color; }

bool Player::makeMove(int& fromRow, int& fromCol,
    int& toRow, int& toCol) {
    string from = "";
    string to = "";

    cout << "  " << name << " [" << color << "] enter move (e.g. e2 e4): ";
    cin >> from >> to;

    if (from.length() != 2 || to.length() != 2) {
        cout << "  Bad format! Use letter + digit, e.g.: e2 e4\n";
        return false;
    }

    char fromFile = from[0];
    char fromRank = from[1];
    char toFile = to[0];
    char toRank = to[1];

    // Files: a-h
    if (fromFile < 'a' || fromFile > 'h' || toFile < 'a' || toFile > 'h') {
        cout << "  Invalid file! Use letters a to h.\n";
        return false;
    }

    // Ranks: 1-8
    if (fromRank < '1' || fromRank > '8' || toRank < '1' || toRank > '8') {
        cout << "  Invalid rank! Use digits 1 to 8.\n";
        return false;
    }

    // 'a' -> 0, 'b' -> 1, ... 'h' -> 7
    fromCol = fromFile - 'a';
    toCol = toFile - 'a';

    // '8' -> 0, '7' -> 1, ... '1' -> 7
    fromRow = 8 - (fromRank - '0');
    toRow = 8 - (toRank - '0');

    return true;
}
