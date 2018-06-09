#include "../inc/gameTree.h"
#include <iostream>

void MM_tree_node::min(){
//  disp();             ////////////////////////
  if(children.empty()) return;
  int tmp = children.back().value;
  while (!children.empty()) {
    if (children.back().value < tmp) {
      tmp = children.back().value;
    }
    children.pop_back();
  }
  value = tmp;
}

void MM_tree_node::max(){
//  disp();             ////////////////////////
  if(children.empty()) return;
  int tmp = children.back().value;
  while (!children.empty()) {
    if (children.back().value > tmp) {
      tmp = children.back().value;
    }
    children.pop_back();
  }
  value = tmp;
}

Movement MM_tree_node::min_move(){
//   disp();             ////////////////////////
  Movement worst_move;
  if(children.empty()) return worst_move;
  int tmp = children.back().value;
  worst_move = children.back().move_;
  while (!children.empty()) {
    if (children.back().value < tmp) {
      tmp = children.back().value;
      worst_move = children.back().move_;
    }
    children.pop_back();
  }
  value = tmp;
  return worst_move;
}

Movement MM_tree_node::max_move(){
//  disp();             ////////////////////////
  Movement best_move(-5,-5, 'G');    /////////////FIX
  if(children.empty()) {
    return best_move;
  }

  int tmp = children.back().value;
  best_move = children.back().move_;
  while (!children.empty()) {
    if (children.back().value > tmp) {
      tmp = children.back().value;
      best_move = children.back().move_;
    }
    children.pop_back();
  }
  value = tmp;
  return best_move;
}
