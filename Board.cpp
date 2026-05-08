#include <iostream>
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

using namespace std;

Board::Board() {
    int r = 0;
    int c = 0;
    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            grid[r][c] = 0;
        }
    }
}

Board::~Board() {
    clearBoard();
}

void Board::clearBoard() {
    int r = 0;
    int c = 0;
    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            if (grid[r][c] != 0) {
                delete grid[r][c];
                grid[r][c] = 0;
            }
        }
    }
}

void Board::initBoard() {
    clearBoard();

    // Row 0 = Black back row
    grid[0][0] = new Rook('B', 0, 0);
    grid[0][1] = new Knight('B', 0, 1);
    grid[0][2] = new Bishop('B', 0, 2);
    grid[0][3] = new Queen('B', 0, 3);
    grid[0][4] = new King('B', 0, 4);
    grid[0][5] = new Bishop('B', 0, 5);
    grid[0][6] = new Knight('B', 0, 6);
    grid[0][7] = new Rook('B', 0, 7);

    // Row 1 = Black pawns
    int c = 0;
    for (c = 0; c < 8; c++) {
        grid[1][c] = new Pawn('B', 1, c);
    }

    // Row 6 = White pawns
    for (c = 0; c < 8; c++) {
        grid[6][c] = new Pawn('W', 6, c);
    }

    // Row 7 = White back row
    grid[7][0] = new Rook('W', 7, 0);
    grid[7][1] = new Knight('W', 7, 1);
    grid[7][2] = new Bishop('W', 7, 2);
    grid[7][3] = new Queen('W', 7, 3);
    grid[7][4] = new King('W', 7, 4);
    grid[7][5] = new Bishop('W', 7, 5);
    grid[7][6] = new Knight('W', 7, 6);
    grid[7][7] = new Rook('W', 7, 7);
}

void Board::displayBoard() {
    int r = 0;
    int c = 0;

    cout << "\n        a     b     c     d     e     f     g     h\n";

    for (r = 0; r < 8; r++) {

        // Top border of row
        cout << "     -------------------------------------------------\n";

        // Row number
        cout << "  " << (8 - r) << "  ";

        for (c = 0; c < 8; c++) {

            cout << "|";

            if (grid[r][c] == 0) {
                cout << "     ";
            }
            else {
                char piece = grid[r][c]->getSymbol();
                char color = grid[r][c]->getColor();

                if (color == 'W') {
                    // Yellow for White player
                    cout << "  \033[33m" << piece << "\033[0m  ";
                }
                else {
                    // Red for Black player
                    cout << "  \033[31m" << piece << "\033[0m  ";
                }
            }
        }

        cout << "|\n";
    }

    // Bottom border
    cout << "     -------------------------------------------------\n";

    cout << "\n        a     b     c     d     e     f     g     h\n\n";
}


bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    Piece* piece = grid[fromRow][fromCol];

    if (piece == 0) {
        cout << "  There is no piece on that square!\n";
        return false;
    }

    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7) {
        cout << "  Destination is off the board!\n";
        return false;
    }

    if (piece->isValidMove(fromRow, fromCol, toRow, toCol, grid) == false) {
        cout << "  That is not a valid move for this piece!\n";
        return false;
    }

    if (grid[toRow][toCol] != 0) {
        cout << "  Captured: " << grid[toRow][toCol]->getSymbol() << "\n";
        delete grid[toRow][toCol];
        grid[toRow][toCol] = 0;
    }

    grid[toRow][toCol] = piece;
    grid[fromRow][fromCol] = 0;

    piece->setRow(toRow);
    piece->setCol(toCol);

    return true;
}

bool Board::isKingAlive(char color) {
    int r = 0;
    int c = 0;
    char sym = ' ';

    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            if (grid[r][c] != 0) {
                if (grid[r][c]->getColor() == color) {
                    sym = grid[r][c]->getSymbol();
                    if (sym == 'K' || sym == 'k') {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Board::isInCheck(char color) {
    int r = 0;
    int c = 0;
    int kingRow = -1;
    int kingCol = -1;
    char sym = ' ';
    char enemyColor = ' ';

    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            if (grid[r][c] != 0) {
                if (grid[r][c]->getColor() == color) {
                    sym = grid[r][c]->getSymbol();
                    if (sym == 'K' || sym == 'k') {
                        kingRow = r;
                        kingCol = c;
                    }
                }
            }
        }
    }

    if (kingRow == -1) {
        return false;
    }

    if (color == 'W') {
        enemyColor = 'B';
    }
    else {
        enemyColor = 'W';
    }

    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            if (grid[r][c] != 0) {
                if (grid[r][c]->getColor() == enemyColor) {
                    if (grid[r][c]->isValidMove(r, c, kingRow, kingCol, grid)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

char Board::getPieceColor(int row, int col) {
    if (grid[row][col] == 0) {
        return ' ';
    }
    return grid[row][col]->getColor();
}
