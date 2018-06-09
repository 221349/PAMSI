#ifndef GAME_H
#define GAME_H

#include <vector>

#include "gameTree.h"


class Game{
public:
  std::vector<position> moves;
  Board state;
  Conditions rules;

  do move(const Movement in);
};

#endif
