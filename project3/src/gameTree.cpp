#include "../inc/Tree.h"
#include <iostream>

void MM_tree_node::disp(){
  state.display();
  std::cout << "children: " << children.size() << "  value: " << value << "\n";
  std::cin.get();
}

MM_tree_node::MM_tree_node(){
  value = 0;
}

MM_tree_node::MM_tree_node(const MM_tree_node &in){
  value = in.value;
  children = in.children;
  state = in.state;
  move_ = in.move_;
}

void MM_tree_node::operator = (const MM_tree_node &in){
  value = in.value;
  children = in.children;
  state = in.state;
  move_ = in.move_;
}

int MM_tree_node::game_over(const Conditions &rules){
  if(state.scan(rules.player0, rules.row_size)) return 1;
  if(state.scan(rules.player1, rules.row_size)) return 2;
  if(!state.count(BLANK)) return -1;
  return 0;
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
