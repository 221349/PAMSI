#include "../inc/gameElements.h"

conditions::conditions(){
  row_size = 3;
  player0 = X;
  player1 = O;
}


movement::movement(){
  x_ = -1;
  y_ = -1;
  cell_ = BLANK;
}

movement::movement(int x, int y, char cell){
  x_ = x;
  y_ = y;
  cell_ = cell;
}

movement::movement(const movement &in){
  x_ = in.x();
  y_ = in.y();
  cell_ = in.cell();
}

void movement::operator = (const movement &in){
  x_ = in.x();
  y_ = in.y();
  cell_ = in.cell();
}
