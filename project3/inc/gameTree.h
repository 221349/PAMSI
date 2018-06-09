#ifndef GAMETREE_H
#define GAMETREE_H

#include <vector>

#include "gameElements.h"


class ab{
public:
  int alpha = 0;
  int beta = 0;
};

class mm_tree_node{
public:
  int value;
  std::vector<mm_tree_node> children;
  //movement move;
  desk state;

  mm_tree_node();
  mm_tree_node(const mm_tree_node &in);
  void operator = (const mm_tree_node &in);
  mm_tree_node(const desk &state_in, const movement &move, const conditions &rules, int depth);

  int game_over(const conditions &rules);
};

#endif
