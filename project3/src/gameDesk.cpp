#include "../inc/gameTree.h"


desk::desk(int x_size, int y_size){
  this->x_size = x_size;
  this->y_size = y_size;
  field = new char * [x_size];
  for(int x = 0; x < x_size; x++){
    field[x] = new char[y_size];
    for(int y = 0; y < y_size; y++){
      field[x][y] = BLANK;
    }
  }
}

desk::~desk(){
  for(int x = 0; x < x_size; x++)
    delete[] field[x];
  delete[] field;
}

int desk::do_move(movement in){
  if((in.x > x_size) || (in.y > y_size))
    return -1;
  field[in.x][in.y] = in.cell;
  return 0;
}

int desk::count(const char in){
  int tmp = 0;
  for(int x = 0; x < x_size; x++){
    for(int y = 0; y < y_size; y++){
      if(field[x][y] == in)
        tmp++;
    }
  }
  return tmp;
}
