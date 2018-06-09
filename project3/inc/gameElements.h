#ifndef GAMEELEMENTS_H
#define GAMEELEMENTS_H

#include <vector>

#define BLANK 32
#define X 88
#define O 79
#define DEFAULT_SIZE 3



class Conditions{
public:
  int row_size; // how many items must be lined up to win
  char player0, player1;
  int win_rate;
  Conditions();
};

class Movement{
private:
  int x_, y_;
  char cell_;
public:
  Movement();
  Movement(int x, int y, char cell);
  Movement(const Movement &in);
  void operator = (const Movement &in);

  inline int x() const { return x_; }
  inline int y() const { return y_; }
  inline char cell() const { return cell_; }
};

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

  void display();
  int do_move(Movement in);
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
};

char opposite(const char in, const Conditions &rules);

#endif
