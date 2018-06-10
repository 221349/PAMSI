#include "../inc/game.h"

Game::Game(){
  about();
  state.setup(3,3);

  rules.row_size = 3;
  rules.player0 = X;
  rules.player1 = O;
  rules.win_rate = 6;
  depth = 9;
  ab = 1;

  first_player = X;
  AI0 = 0;
  AI1 = 1;
  info = 0;

  delay_time = 1000; //[ms]
}


void Game::do_move(const char player){
  MM_tree_node tree;
  Movement move(-1, -1, player);
  if(player == rules.player0){
    if(AI0) move = tree.calc_best_move(state, rules, player, depth);
    else move = ask_turn(player);
  }
  if(player == rules.player1){
    if(AI1) move = tree.calc_best_move(state, rules, player, depth);
    else move = ask_turn(player);
  }
  state.do_move(move);
  history.push_back(move);
}
