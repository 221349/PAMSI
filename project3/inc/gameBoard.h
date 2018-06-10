#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "../inc/gameElements.h"

class Board{
private:
  char ** field;
  int x_size; // Board size by X
  int y_size; // Board size by Y

public:
  Board();
  Board(int x_size, int y_size);
  Board(const Board &in);
  void operator = (const Board &in);
  ~Board();

  inline int x() const { return x_size; }
  inline int y() const { return y_size; }
  inline char ** field_pointer() const { return field; }
  int check_free(int x, int y);

  void setup(int x_size_, int y_size_);

  void display();
  void clear();
  int do_move(Movement in);
  int undo_move(Movement in);
  int count(char in);
  std::vector<Movement> get_moves(const char in);

  int scan(const Movement &move, const int size);
  int scan_horizontal(const Movement &move, const int size);
  int scan_vertical(const Movement &move, const int size);
  int scan_diagonal_NW(const Movement &move, const int size);
  int scan_diagonal_SW(const Movement &move, const int size);

  int scan(const char target, const int size);
  int scan_horizontal(const char target, const int size);
  int scan_vertical(const char target, const int size);
  int scan_diagonal_NW(const char target, const int size);
  int scan_diagonal_SW(const char target, const int size);

  int game_over(const Conditions &rules);
};

#endif
