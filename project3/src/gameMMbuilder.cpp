#include "../inc/gameTree.h"

MM_tree_node::MM_tree_node(const Board &state_in, const Movement &move, const Conditions &rules, const char player, int depth){
  state = state_in;
  move_ = move;
  state.do_move(move);
  value = 0;
  if(depth == 0) {
    calc_value(rules, player);
    return;
  }
  build(rules, move, player, depth);
}

void MM_tree_node::build(const Conditions &rules, const Movement &move, char player, int depth){
  std::vector<Movement> possible_moves = state.get_moves(opposite(move.cell(), rules));
  if(possible_moves.empty() || state.scan(move, rules.row_size)){
    calc_value(rules, player);
    return;
  }
  while (!possible_moves.empty()) {
    children.push_back(MM_tree_node(state, possible_moves.back(), rules, player, depth - 1));
    possible_moves.pop_back();
  }
  if(player == move.cell()) min();
  else max();
}

Movement MM_tree_node::calc_best_move(const Board &state_in, const Conditions &rules, char player, int depth){
  state = state_in;
  value = 0;
  if(depth == 0) {
    calc_value(rules, player);
    return move_;
  }
  build_move(rules, player, depth);
  return max_move();
}

void MM_tree_node::build_move(const Conditions &rules, char player, int depth){
  std::vector<Movement> possible_moves = state.get_moves(player);
  if(possible_moves.empty()){
    calc_value(rules, player);
    return;
  }
  while (!possible_moves.empty()) {
    children.push_back(MM_tree_node(state, possible_moves.back(), rules, player, depth - 1));
    possible_moves.pop_back();
  }
}
