#ifndef GAMETREE_H
#define GAMETREE_H

#define BLANK 32
#define X 88
#define O 79

#include <iostream>
#include <vector>

class movement{
public:
  int x, y;
  char cell;
};

class conditions{
public:
  int row_size; // how many items must be lined up to win
};

class desk{
public:
  char ** field;
  int x_size; // desk size by X
  int y_size; // desk size by Y

  desk(int x_size, int y_size);
  ~desk();

  void display();
  int do_move(const movement in);
  int count(const char in);
};


class mm_tree_node{
public:
  int value;
  std::vector<mm_tree_node> children;
  movement move;
  desk state;
};

#endif
