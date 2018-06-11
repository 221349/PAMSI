#include <chrono>
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
  AB alpha_beta;
  MM_tree_node tree;
  int n = 0;
  Movement move(-1, -1, player);

  auto start = std::chrono::steady_clock::now();
  if(player == rules.player0){
    if(AI0) {
      if(ab) move = tree.calc_best_move(n, state, rules, player, depth, alpha_beta);
      else move = tree.calc_best_move(n, state, rules, player, depth);
    }
    else move = ask_turn(player);
  }
  if(player == rules.player1){
    if(AI1) {
      if(ab) move = tree.calc_best_move(n, state, rules, player, depth, alpha_beta);
      else move = tree.calc_best_move(n, state, rules, player, depth);
    }
    else move = ask_turn(player);
  }
  auto end = std::chrono::steady_clock::now();
  info_data.time = (std::chrono::duration_cast<std::chrono::milliseconds> (end - start) ).count();
  info_data.nodes = n;
  info_data.value = tree.value;
  info_data.move = move;

  state.do_move(move);
  history.push_back(move);
}
