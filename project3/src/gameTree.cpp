#include "../inc/gameTree.h"


mm_tree_node::mm_tree_node(const mm_tree_node &in){
  value = in.value;
  children = in. children;
  state = in.state;
}

void mm_tree_node::operator = (const mm_tree_node &in){
  value = in.value;
  children = in. children;
  state = in.state;
}

mm_tree_node::mm_tree_node(const desk &state_in, const movement &move, const conditions &rules, int depth){
  state = state_in;
  state.do_move(move);

}

int mm_tree_node::game_over(const conditions &rules){
  if(state.scan(rules.player0, rules.row_size)) return 1;
  if(state.scan(rules.player1, rules.row_size)) return 2;
  return 0;
}
