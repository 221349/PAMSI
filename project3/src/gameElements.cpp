#include "../inc/gameElements.h"

Conditions::Conditions(){
  row_size = 3;
  player0 = X;
  player1 = O;
}


Movement::Movement(){
  x_ = -1;
  y_ = -1;
  cell_ = BLANK;
}

Movement::Movement(int x, int y, char cell){
  x_ = x;
  y_ = y;
  cell_ = cell;
}

Movement::Movement(const Movement &in){
  x_ = in.x();
  y_ = in.y();
  cell_ = in.cell();
}

void Movement::operator = (const Movement &in){
  x_ = in.x();
  y_ = in.y();
  cell_ = in.cell();
}

char opposite(const char in, const Conditions &rules){
  if(in == rules.player0) return rules.player1;
  if(in == rules.player1) return rules.player0;
  return 0;
}
