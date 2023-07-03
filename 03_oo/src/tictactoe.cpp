#include "normal_player.hpp"
#include "human_player.hpp"
#include "game_controller.hpp"

#include <iostream>
#include <string>

int main() {
    std::cout << "Willkommen zu Tic Tac Toe!\n\n";

    // Player selection
    std::cout << "Waehlen Sie einen Spieler:\n";
    std::cout << "1. Human Player\n";
    std::cout << "2. Random Player\n";
    std::cout << "3. Perfect Player\n";
    std::cout << "Ihre Wahl (1-3): ";

    int playerChoice;
    std::cin >> playerChoice;

    Player* humanPlayer;
    Player* computerPlayer;

    switch (playerChoice) {
        case 1:
            humanPlayer = new HumanPlayer(Color::CIRCLE);
            break;
        case 2:
            computerPlayer = new RandomPlayer(Color::CIRCLE);
            humanPlayer = new HumanPlayer(Color::CROSS);
            break;
        case 3:
            computerPlayer = new PerfectPlayer(Color::CIRCLE);
            humanPlayer = new HumanPlayer(Color::CROSS);
            break;
        default:
            std::cerr << "Ungueltige Auswahl. Das Spiel wird beendet.\n";
            return 1;
    }

    GameController gameController;
    gameController.play(*humanPlayer, *computerPlayer);

    // Cleanup
    delete humanPlayer;
    delete computerPlayer;

    return 0;
}
