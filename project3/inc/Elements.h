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


char opposite(const char in, const Conditions &rules);

#endif
