#include <iostream>
#include <chrono>
#include <thread>

#include "../inc/game.h"

Movement Game::ask_turn(char player){
  int x, y;
  bool ok = 1;
  while(ok){
    std::cout << "\nX:";
    std::cin >> x;
    std::cout << "Y:";
    std::cin >> y;
    if(state.check_free(x, y) == -1){
      std::cout << "  Illegal move: abroad";
    }
    if(state.check_free(x, y) == 1){
      std::cout << "\n  Illegal move: cell occupied";
    }
    if(state.check_free(x, y) == 0){
      ok = 0;
    }
  }
  return Movement(x, y, player);
}

void Game::show_info(){
  if(!info) return;
  std::cout << "\n  Last move: (" << info_data.move.x() << ","
                << info_data.move.y() << "): " << info_data.move.cell()
            << "\n    time: " << info_data.time << " ms"
            << "\n    tree nodes: " << info_data.nodes
            << "\n    move value: " << info_data.value << "\n";
}
void Game::play(){
  Movement move();
  system("clear");
  state.display();
  do_move(first_player);
  if(AI1 && AI0) delay(delay_time);
  system("clear");
  state.display();
  show_info();
  while(!state.game_over(rules)){
    do_move(opposite(history.back().cell(), rules));
    if(AI1 && AI0) delay(delay_time);
    system("clear");
    state.display();
    show_info();
  }
  game_over();
}


void Game::jump_back(){
  if(history.empty()) return;
  state.undo_move(history.back());
  history.pop_back();
  system("clear");
  state.display();

  std::cout << "\n\n  p - play from here"
            << "\n  b - jump back to previous move"
            << "\n  s - Advanced setup (changing board dimensions will erase board state)"
            << "\n  q - Quit\n";
  jump_back_menu();
}

void Game::jump_back_menu(){
  std::cout << ">";
  char answer = ask_char();
  if(answer == 'p') {
    first_player = opposite(history.back().cell(), rules);
    play();
    return;
  }
  if(answer == 'b') {
    jump_back();
    return;
  }
  if(answer == 's') {
    setup();
    system("clear");
    state.display();
    std::cout << "\n\n  p - play from here"
              << "\n  b - jump back to previous move"
              << "\n  s - Advanced setup (changing board dimensions will erase board state)"
              << "\n  q - Quit\n";
  }
  if(answer == 'q') {
    state.clear();
    return;
  }
  jump_back_menu();
}

void Game::game_over(){
  std::cout << "\n  Game over!";
  if(state.game_over(rules) == -1) std::cout << "\n  Draw!";
  if(state.game_over(rules) == 1) std::cout << "\n  Player 1 (" << rules.player0 <<") wins";
  if(state.game_over(rules) == 2) std::cout << "\n  Player 2 (" << rules.player1 <<") wins";
  std::cout << "\n\n  n - New game (same conditions)"
              << "\n  b - jump back to previous move"
              << "\n  q - Quit\n";
  game_over_menu();
}
void Game::game_over_menu(){
  std::cout <<  ">";
  char answer = ask_char();
  if(answer == 'n') {
    state.clear();
    first_player = opposite(first_player, rules);
    play();
    return;
  }
  if(answer == 'b') {
    jump_back();
    return;
  }
  if(answer == 'q') {
    state.clear();
    return;
  }
  game_over_menu();
}

int ask_int(){
  int out;
  std::cin >> out;
  return out;
}

char ask_char(){
  char out;
  std::cin >> out;
  return out;
}

void delay(int ms){
  if(ms < 0) std::cin.get();
  else std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int Game::number_set(char x){
  system("clear");
  std::cout << "\n    " << x << ": ";
  int size = ask_int();
  while(size < 1){
    system("clear");
    std::cout << "\n  " << x << " = " << size
              << "\n  Too small"
              << "\n    " << x << ": ";
    size = ask_int();
  }
  if(size > 16){
    system("clear");
    std::cout << "\n  " << x << " = " << size
              << "?\n  Well thats quite a few.. "
              << "\n  Do you want to set this number? 'y' = yes >";
    int answer = ask_char();

    if(answer != 'y') {
      size = number_set(x);
    }
  }
  return size;
}

void Game::presets(){
  system("clear");
  std::cout << "\n  Presets:"
            << "\n   1: Default, 3x3"
            << "\n   2: bot VS bot 4x4"
            << "\n   3: no AB, 4x4 with info"
            << "\n   4: with AB, 4x4 with info"
            << "\n>";
  int answer = ask_char();

  if(answer == '1') {
    state.setup(3,3);
    rules.row_size = 3;
    rules.win_rate = 6;
    depth = 9;
    ab = 1;
    first_player = X;
    AI0 = 0;
    AI1 = 1;
    return;
  }
  if(answer == '2') {
    state.setup(4,4);
    rules.row_size = 4;
    rules.win_rate = 12;
    depth = 6;
    ab = 1;
    first_player = X;
    AI0 = 1;
    AI1 = 1;
    delay_time = 500;
    return;
  }
  if(answer == '3') {
    state.setup(4,4);
    rules.row_size = 4;
    rules.win_rate = 12;
    depth = 6;
    ab = 0;
    first_player = X;
    AI0 = 0;
    AI1 = 1;
    delay_time = 500;
    info = 1;
    return;
  }
  if(answer == '4') {
    state.setup(4,4);
    rules.row_size = 4;
    rules.win_rate = 12;
    depth = 6;
    ab = 0;
    first_player = X;
    AI0 = 0;
    AI1 = 1;
    delay_time = 500;
    info = 1;
    return;
  }
  presets();
}

void about(){
  system("clear");
  std::cout << "\n  Tic-Tac-Toe. With MiniMax & Alpha–beta pruning."
            << "\n    More info on"
            << "\n    https://github.com/221349/PAMSI/tree/master/project3\n\n";
  std::cin.get();
}

void Game::menu() {
  system("clear");
  std::cout << "\n\n  n - Start new game"
            << "\n  p - Presets"
            << "\n  s - Setup"
            << "\n  a - About"
            << "\n  q - Quit"
            << "\n>";
  char answer = ask_char();
  if(answer == 'n') play();
  if(answer == 'p') presets();
  if(answer == 's') setup();
  if(answer == 'a') {
    about();
    std::cin.get();
  }
  if(answer == 'q') return;
  menu();
}

void Game::setup(){
  system("clear");
  std::cout << "\n  Game:"
            << "\n    Mode,               m: P1- ";
  if(AI0 == 0) std::cout << "human";
  else std::cout << "computer";
  std::cout << "  VS  P2- ";
  if(AI1 == 0) std::cout << "human";
  else std::cout << "computer";
  std::cout << "\n    First player,       f: ";
  if(first_player == rules.player0) std::cout << "Player 1";
  else std::cout << "Player 2";
  std::cout << "\n    Delay time [ms],    d: ";
  if(delay_time >= 0) std::cout << delay_time;
  else std::cout << "Press Enter for next move";
  std::cout << "  (for computer VS computer mode only)";
  std::cout << "\n\n  Board_size [x,y]: "
            << "\n                        x: " << state.x()
            << "\n                        y: " << state.y()
            << "\n    Row length to win,  l: " << rules.row_size
            << "\n    Player 1 symbol,    1: " << rules.player0
            << "\n    Player 2 symbol,    2: " << rules.player1;

  std::cout << "\n\n  MiniMax algorithm:"
            << "\n    Search depth,       s: " << depth
            << "\n    Win ratio,          r: " << rules.win_rate << "  (less = easier)"
            << "\n    Alpha–beta,         a: ";
  if(ab) std::cout << "yes";
  else std::cout << "no";
  std::cout << "\n    Display info,       i: ";
  if(info) std::cout << "yes";
  else std::cout << "no";
  std::cout << "\n\n q to quit\n>";

  char answer = ask_char();
  if(answer == 'm') toggle_mode();
  if(answer == 'f') first_player = opposite(first_player, rules);
  if(answer == 'd') set_delay();
  if(answer == 'x') set_x();
  if(answer == 'y') set_y();
  if(answer == 'l') set_l();
  if(answer == '1') set_symbol0();
  if(answer == '2') set_symbol1();
  if(answer == 's') set_depth();
  if(answer == 'r') set_win_ratio();
  if(answer == 'a') ab = !ab;
  if(answer == 'i') info = !info;
  if(answer == 'q') return;
  setup();
}

void Game::toggle_mode(){
  if(!AI0 && AI1) {
    AI1 = 0;
    return;
  }
  if(AI0 && AI1) {
    AI0 = 0;
    return;
  }
  else{
    AI0 = 1;
    AI1 = 1;
  }
}

void Game::set_delay(){
  system("clear");
  std::cout << "\n  Set delay:"
            << "\n    set < 0 for keypress"
            << "\n    delay [ms]: ";
  delay_time = ask_int();
}

void Game::set_x(){
  system("clear");
  int x = number_set('x');
  state.setup(x, state.y());
}

void Game::set_y(){
  system("clear");
  int y = number_set('y');
  state.setup(state.x(), y);
}

void Game::set_l(){
  system("clear");
  rules.row_size = number_set('l');
}

void Game::set_symbol0(){
  system("clear");
  std::cout << "\n  Player 1 symbol: ";
  rules.player0 = ask_char();
}

void Game::set_symbol1(){
  system("clear");
  std::cout << "\n  Player 2 symbol: ";
  rules.player1 = ask_char();
}

void Game::set_depth(){
  system("clear");
  std::cout << "\n  Depth: ";
  depth = ask_int();
}

void Game::set_win_ratio(){
  system("clear");
  std::cout << "\n  Win ratio: ";
  rules.win_rate = ask_int();
}
