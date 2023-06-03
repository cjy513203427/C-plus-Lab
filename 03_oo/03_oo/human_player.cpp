#include "human_player.hpp"

#include <iostream>

HumanPlayer::HumanPlayer(Color color) : Player(color) {}

void HumanPlayer::performNextMove(Board& board) {
    int row, col;
    bool validInput = false;

    while (!validInput) {
        getUserInput();
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);

        if (iss >> row >> col) {
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == Field::EMPTY) {
                validInput = true;
            }
        }

        if (!validInput) {
            std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut.\n";
        }
    }

    board[row][col] = asField(color);
    std::cout << "Ihr Zug wurde ausgefuehrt.\n";
}

void HumanPlayer::getUserInput() {
    std::cout << "Wo moechten Sie Ihr Kreuz setzen? Geben Sie die Zeile und Spalte getrennt durch Leerzeichen ein.\n";
    std::cout << "Eingabeformat: <Zeile> <Spalte>, z.B. '1 2': ";
}