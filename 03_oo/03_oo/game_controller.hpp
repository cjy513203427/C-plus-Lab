#pragma once

#include "player.hpp"
#include "board.hpp"
#include <iostream>

class GameController {
public:
  void play(Player& cross, Player& circle);

private:
  Board board;
};
