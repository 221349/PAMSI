#ifndef GAMEELEMENTS_H
#define GAMEELEMENTS_H

#include <vector>

#define BLANK 32
#define X 88
#define O 79
#define DEFAULT_SIZE 3


class conditions{
public:
  int row_size; // how many items must be lined up to win
  char player0, player1;

  conditions();
};

class movement{
private:
  int x_, y_;
  char cell_;
public:
  movement();
  movement(int x, int y, char cell);
  movement(const movement &in);
  void operator = (const movement &in);

  inline int x() const { return x_; }
  inline int y() const { return y_; }
  inline char cell() const { return cell_; }
};

class desk{
private:
  char ** field;
  int x_size; // desk size by X
  int y_size; // desk size by Y

public:
  desk();
  desk(int x_size, int y_size);
  ~desk();

  void display();
  int do_move(movement in);
  int count(char in);
  std::vector<movement> get_moves(const char in);

  int scan(const char target, const int size);
  int scan_horizontal(const char target, const int size);
  int scan_vertical(const char target, const int size);
  int scan_diagonal_NW(const char target, const int size);
  int scan_diagonal_SW(const char target, const int size);
};

#endif
