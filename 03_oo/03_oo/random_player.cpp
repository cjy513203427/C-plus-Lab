#include "random_player.hpp"
#include <cstdlib>
#include <ctime>

RandomPlayer::RandomPlayer(Color color) : Player(color) {
    // Initialize random seed
    std::srand(std::time(nullptr));
}

void RandomPlayer::performNextMove(Board& board) {
    // Generate random row and column indices
    int row = std::rand() % 3;
    int col = std::rand() % 3;

    // Check if the randomly chosen position is empty
    if (board[row][col] == Field::EMPTY) {
        // Set the random position to a circle
        board[row][col] = asField(color);
        std::cout << "RandomPlayer set a circle at position (" << row << ", " << col << ")." << std::endl;
    }
    else {
        // If the position is not empty, generate new random positions until an empty position is found
        while (board[row][col] != Field::EMPTY) {
            row = std::rand() % 3;
            col = std::rand() % 3;
        }

        // Set the randomly chosen empty position to a circle
        board[row][col] = asField(color);
        std::cout << "RandomPlayer set a circle at position (" << row << ", " << col << ")." << std::endl;
    }
}