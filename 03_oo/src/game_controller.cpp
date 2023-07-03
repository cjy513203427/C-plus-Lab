#include "game_controller.hpp"

void GameController::play(Player& cross, Player& circle) {
    
    // Randomly choose the starting player
    int startingPlayer = std::rand() % 2;

    Player* currentPlayer;
    Player* otherPlayer;

    if (startingPlayer == 0) {
        currentPlayer = &cross;
        otherPlayer = &circle;
    } else {
        currentPlayer = &circle;
        otherPlayer = &cross;
    }

    // Main game loop
    while (true) {
        // Current player's turn
        currentPlayer->performNextMove(board);

        // Check for game end conditions
        std::optional<GameStatus> winner = board.whoWon();
        if (winner.has_value()) {
            // Display the winner
            switch (winner.value()) {
                case GameStatus::CROSS:
                    std::cout << "Player X wins!\n";
                    break;
                case GameStatus::CIRCLE:
                    std::cout << "Player O wins!\n";
                    break;
                case GameStatus::TIE:
                    std::cout << "It's a tie!\n";
                    break;
            }

            // Ask to play again
            std::cout << "Play again? (y/n): ";
            char choice;
            std::cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                return;
            }

            // Reset the board
            board = Board();
        }

        // Switch players
        std::swap(currentPlayer, otherPlayer);
    }
}