#include "../inc/Tree.h"

AB::AB(){
  alpha_ = -1000000;
  beta_  = 1000000;
}

void AB::reset(){
  alpha_ = -1000000;
  beta_  = 1000000;
}

int AB::min(int value){
  if(value < alpha_ ) {
    return 1;
  }
  if(value < beta_ ) beta_ = value;
  return 0;
}

int AB::max(int value){
  if(value > beta_ ) {
    return 1;
  }
  if(value > alpha_ ) alpha_ = value;
  return 0;
}


MM_tree_node::MM_tree_node(int &n, const Board &state_in, const Movement &move, const Conditions &rules, const char player, int depth, AB ab){
  n++;
  state = state_in;
  move_ = move;
  state.do_move(move);
  value = 0;
  if(depth <= 0) {
    calc_value(rules, player);
    return;
  }
  build(n, rules, move, player, depth, ab);
}

void MM_tree_node::build(int &n, const Conditions &rules, const Movement &move, char player, int depth, AB ab){
  std::vector<Movement> possible_moves = state.get_moves(opposite(move.cell(), rules));
  if(possible_moves.empty() || state.scan(move, rules.row_size)){
    calc_value(rules, player);
    return;
  }
  while (!possible_moves.empty()) {
    children.push_back(MM_tree_node(n, state, possible_moves.back(), rules, player, depth - 1, ab));
    possible_moves.pop_back();

    // Alpha-Beta here:
    if(player == move.cell()) {
      if( ab.min(children.back().value) ) {
        value = children.back().value;
        return;
      }
    }
    else{
      if( ab.max(children.back().value) ) {
        value = children.back().value;
        return;
      }
    }
  }
  if(player == move.cell()) min();
  else max();
}

Movement MM_tree_node::calc_best_move(int &n, const Board &state_in, const Conditions &rules, char player, int depth, AB ab){
  n++;
  state = state_in;
  value = 0;
  if(depth <= 0) {
    calc_value(rules, player);
    return Movement(-1, -1, player);
  }
  build_move(n, rules, player, depth, ab);
  return max_move();
}

void MM_tree_node::build_move(int &n, const Conditions &rules, char player, int depth, AB ab){
  std::vector<Movement> possible_moves = state.get_moves(player);
  if(possible_moves.empty()){
    calc_value(rules, player);
    return;
  }
  while (!possible_moves.empty()) {
    children.push_back(MM_tree_node(n, state, possible_moves.back(), rules, player, depth - 1, ab));
    possible_moves.pop_back();

    // Alpha-Beta here:
    if( ab.max(children.back().value) ) {
      value = children.back().value;
      return;
    }
  }
}
