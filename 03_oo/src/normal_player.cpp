#include "normal_player.hpp"
#include <cstdlib>
#include <ctime>

NormalPlayer::NormalPlayer(Color color) : PerfectPlayer(color), RandomPlayer(color), Player(color) {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void NormalPlayer::performNextMove(Board& board) {
    // Randomly choose between PerfectPlayer and RandomPlayer
    int choice = std::rand() % 2;

    if (choice == 0) {
        // Call performNextMove() of PerfectPlayer
        PerfectPlayer::performNextMove(board);
    } else {
        // Call performNextMove() of RandomPlayer
        RandomPlayer::performNextMove(board);
    }
}
