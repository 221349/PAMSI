#ifndef GAMETREE_H
#define GAMETREE_H

#include <vector>

#include "Elements.h"
#include "Board.h"


class AB{
private:
  int alpha_;
  int beta_;
public:
  AB();

  void reset();
  inline int alpha() const { return alpha_; }
  inline int beta() const { return beta_; }

  int min(int value);
  int max(int value);

  void alpha(int a);
  void beta(int b);
};

class MM_tree_node{
public:
  Movement move_;
  int value;
  std::vector<MM_tree_node> children;
  Board state;

  MM_tree_node();
  MM_tree_node(const MM_tree_node &in);
  void operator = (const MM_tree_node &in);
  //Regular Minimax
  MM_tree_node(int &n, const Board &state_in, const Movement &move, const Conditions &rules, char player, int depth);
  void build(int &n, const Conditions &rules, const Movement &move, char player, int depth);
  //Regular Minimax, Root Node
  Movement calc_best_move(int &n, const Board &state_in, const Conditions &rules, char player, int depth);
  void build_move(int &n, const Conditions &rules, char player, int depth);

  //Alpha-Beta Minimax
  MM_tree_node(int &n, const Board &state_in, const Movement &move, const Conditions &rules, char player, int depth, AB ab);
  void build(int &n, const Conditions &rules, const Movement &move, char player, int depth, AB ab);
  //Alpha-Beta Minimax, Root node
  Movement calc_best_move(int &n, const Board &state_in, const Conditions &rules, char player, int depth, AB ab);
  void build_move(int &n, const Conditions &rules, char player, int depth, AB ab);

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
