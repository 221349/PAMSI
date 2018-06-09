#ifndef GAME_H
#define GAME_H

#include <vector>

#include "gameTree.h"


class game{
public:
  std::vector<position> moves;
  desk state;
  conditions rules;

  do move(const movement in);
};

#endif
