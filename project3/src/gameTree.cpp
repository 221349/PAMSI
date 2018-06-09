#include "../inc/gameTree.h"
#include <iostream>

void MM_tree_node::disp(){
  state.display();
  std::cout << "children: " << children.size() << "  value: " << value << "\n";
  //std::cin.get();
}

MM_tree_node::MM_tree_node(){
  value = 0;
}

MM_tree_node::MM_tree_node(const MM_tree_node &in){
  value = in.value;
  children = in.children;
  state = in.state;
}

void MM_tree_node::operator = (const MM_tree_node &in){
  value = in.value;
  children = in.children;
  state = in.state;
}

MM_tree_node::MM_tree_node(const Board &state_in, const Movement &move, const Conditions &rules, const char player, int depth){
  state = state_in;
  state.do_move(move);
  value = 0;
  if(depth == 0) {
    calc_value(rules, player);
     disp();
    return;
  }
  std::vector<Movement> possible_moves = state.get_moves(opposite(move.cell(), rules));
  if(possible_moves.empty() || state.scan(move, rules.row_size)){
    calc_value(rules, player);
     disp();             ////////////////////////
    return;
  }
  possible_moves.back();
  while (!possible_moves.empty()) {
    children.push_back(MM_tree_node(state, possible_moves.back(), rules, player, depth - 1));
    possible_moves.pop_back();
  }
  if(player == move.cell()) max();
  else min();
}

void MM_tree_node::min(){
  disp();             ////////////////////////
  if(children.empty()) return;
  int tmp = children.back().value;
  while (!children.empty()) {
    if (children.back().value < tmp) {
      tmp = children.back().value;
      std::cout << tmp;
    }
    children.pop_back();
  }
  value = tmp;
}

void MM_tree_node::max(){
  disp();             ////////////////////////
  if(children.empty()) return;
  int tmp = children.back().value;
  while (!children.empty()) {
    if (children.back().value > tmp) {
      tmp = children.back().value;
      std::cout << tmp;
    }
    children.pop_back();
  }
  value = tmp;
}
/
void MM_tree_node::min(){
   disp();             ////////////////////////
  if(children.empty()) return;
  int tmp = children.back().value;
  while (!children.empty()) {
    if (children.back().value < tmp) {
      tmp = children.back().value;
      std::cout << tmp;
    }
    children.pop_back();
  }
  value = tmp;
}

void MM_tree_node::max(){
  disp();             ////////////////////////
  if(children.empty()) return;
  int tmp = children.back().value;
  while (!children.empty()) {
    if (children.back().value > tmp) {
      tmp = children.back().value;
      std::cout << tmp;
    }
    children.pop_back();
  }
  value = tmp;
}

void MM_tree_node::calc_value(const Conditions &rules, const char player){
  int bufer = 0;
  for(int l = 2; l < rules.row_size; l++){
    bufer += state.scan(player, l);
    bufer -= state.scan(opposite(player, rules), l);
  }
  bufer += (state.scan(player, rules.row_size) * rules.win_rate);
  bufer -= (state.scan(opposite(player, rules), rules.row_size) * rules.win_rate);
  value = bufer;
}
