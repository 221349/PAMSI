#ifndef GAME_H
#define GAME_H

#include "gameTree.h"

class game{
public:
  position last_move;
  desk state;
  conditions rules;
};

#endif
