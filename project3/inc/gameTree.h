#ifndef GAMETREE_H
#define GAMETREE_H

#include <vector>

#include "gameElements.h"


class ab{
public:
  int alpha = 0;
  int beta = 0;
};

class MM_tree_node{
public:
  int value;
  std::vector<MM_tree_node> children;
  //Movement move;
  Board state;

  MM_tree_node();
  MM_tree_node(const MM_tree_node &in);
  void operator = (const MM_tree_node &in);
  MM_tree_node(const Board &state_in, const Movement &move, const Conditions &rules, char player, int depth);

  void calc_value(const Conditions &rules, const char player);
  void min();
  void max();
  Movement min_move();
  Movement max_move();

  void disp();

  int game_over(const Conditions &rules);
  int game_over(const Conditions &rules, const Movement &move);
};

#endif
