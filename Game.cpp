#include <iostream>
#include "Game.h"

using namespace std;

// Player 1 = White, Player 2 = Black
Game::Game(string p1Name, string p2Name)
    : player1(p1Name, 'W'), player2(p2Name, 'B') {
    this->currentTurn = 0;
}

Game::~Game() {}

void Game::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Game::switchTurn() {
    if (currentTurn == 0) {
        currentTurn = 1;
    }
    else {
        currentTurn = 0;
    }
}

bool Game::isGameOver() {
    if (board.isKingAlive('W') == false) { return true; }
    if (board.isKingAlive('B') == false) { return true; }
    return false;
}

void Game::start() {
    board.initBoard();

    clearScreen();
    cout << "========================================\n";
    cout << "         WELCOME TO CONSOLE CHESS\n";
    cout << "  Moves: type  <from> <to>  e.g.  e2 e4\n";
    cout << "========================================\n";

    while (true) {
        clearScreen();
        board.displayBoard();

        if (board.isInCheck('W')) {
            cout << "  *** WHITE KING IS IN CHECK! ***\n";
        }
        if (board.isInCheck('B')) {
            cout << "  *** BLACK KING IS IN CHECK! ***\n";
        }

        Player* current = 0;
        if (currentTurn == 0) {
            current = &player1;
        }
        else {
            current = &player2;
        }

        cout << "\n";

        int fromRow = 0;
        int fromCol = 0;
        int toRow = 0;
        int toCol = 0;

        bool validInput = current->makeMove(fromRow, fromCol, toRow, toCol);

        if (validInput == false) {
            cout << "  Please try again. Press Enter...\n";
            cin.ignore();
            cin.get();
            continue;
        }

        char pieceColor = board.getPieceColor(fromRow, fromCol);

        if (pieceColor == ' ') {
            cout << "  No piece there! Press Enter to try again...\n";
            cin.ignore();
            cin.get();
            continue;
        }

        if (pieceColor != current->getColor()) {
            cout << "  That is not your piece! Press Enter to try again...\n";
            cin.ignore();
            cin.get();
            continue;
        }

        bool moved = board.movePiece(fromRow, fromCol, toRow, toCol);

        if (moved == false) {
            cout << "  Press Enter to try again...\n";
            cin.ignore();
            cin.get();
            continue;
        }

        if (board.isKingAlive('W') == false) {
            clearScreen();
            board.displayBoard();
            cout << "\n  *** BLACK WINS! White King has been captured! ***\n";
            cout << "  Congratulations, " << player2.getName() << "!\n\n";
            break;
        }

        if (board.isKingAlive('B') == false) {
            clearScreen();
            board.displayBoard();
            cout << "\n  *** WHITE WINS! Black King has been captured! ***\n";
            cout << "  Congratulations, " << player1.getName() << "!\n\n";
            break;
        }

        switchTurn();
    }

    cout << "  Thanks for playing!\n";
}
