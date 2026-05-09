#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main() {
    string name1 = "";
    string name2 = "";

    cout << "==============================\n";
    cout << "       CONSOLE CHESS\n";
    cout << "==============================\n\n";

    cout << "Enter name for White player: ";
    cin >> name1;

    cout << "Enter name for Black player: ";
    cin >> name2;

    Game chess(name1, name2);
    chess.start();

    return 0;
}
