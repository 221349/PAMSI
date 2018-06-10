#ifndef GAME_H
#define GAME_H

#include <vector>

#include "gameTree.h"

class Game{
public:
  std::vector<Movement> history;
  Board state;
  Conditions rules;
  int depth;
  bool ab;

  char first_player;
  bool AI0;
  bool AI1;
  bool info;
  int delay_time; //[ms]

  Game();

  void menu();
  void play();
  void do_move(const char player);

  void jump_back();
  void jump_back_menu();
  void game_over_menu();
  void game_over();
  void basic_setup();
  void setup();

  void toggle_mode();
  void set_delay();

  void set_x();
  void set_y();
  void set_l();
  void set_symbol0();
  void set_symbol1();

  void set_depth();
  void set_win_ratio();

  void show_info();


  int number_set(char x);
  Movement ask_turn(char player);
};

int ask_int();
char ask_char();
void help();
void about();
void delay(int ms);

#endif
