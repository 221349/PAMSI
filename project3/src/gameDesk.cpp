#include "../inc/gameElements.h"

desk::desk(){
  x_size = 0;
  y_size = 0;
  field = 0;
}

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
  if((in.x() > x_size) || (in.y() > y_size))
    return -1;
  field[in.x()][in.y()] = in.cell();
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

std::vector<movement> desk::get_moves(const char in){
  std::vector<movement> moves;
  for(int x = 0; x < x_size; x++){
    for(int y = 0; y < y_size; y++){
      if(field[x][y] == BLANK){
        movement tmp(x, y, in);
        //moves.insert(moves.begin(), tmp);
        moves.push_back(tmp);
      }
    }
  }
  return moves;
}

int desk::scan_horizontal(const char target, const int size){
  int out = 0;
  int buf = 0;
  for(int y = 0; y < y_size; y++){
    for(int x = 0; x < x_size; x++){
      if(field[x][y] == target) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
    buf = 0;
  }
  return out;
}

int desk::scan_vertical(const char target, const int size){
  int out = 0;
  int buf = 0;
  for(int x = 0; x < x_size; x++){
    for(int y = 0; y < y_size; y++){
      if(field[x][y] == target) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
    buf = 0;
  }
  return out;
}


int desk::scan_diagonal_NW(const char target, const int size){
  int out = 0;
  int buf = 0;
  for(int bx = 0; bx < x_size; bx++){
    for(int x = bx, y = 0; (y < y_size)&&(x < x_size); x++, y++){
      if(field[x][y] == target) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
    buf = 0;
  }

  for(int by = 1; by < y_size; by++){
    for(int x = 0, y = by; (y < y_size)&&(x < x_size); x++, y++){
      if(field[x][y] == target) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
    buf = 0;
  }
  return out;
}

int desk::scan_diagonal_SW(const char target, const int size){
  int out = 0;
  int buf = 0;
  for(int bx = 0; bx < x_size; bx++){
    for(int x = bx, y = 0; (y < y_size)&&(x >= 0); x--, y++){
      if(field[x][y] == target) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
    buf = 0;
  }

  for(int by = 1; by < y_size; by++){
    for(int x = x_size-1, y = by; (y < y_size)&&(x >= 0); x--, y++){
      if(field[x][y] == target) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
    buf = 0;
  }
  return out;
}

int desk::scan(const char target, const int size){
  return scan_horizontal(target, size) +
          scan_vertical(target, size) +
          scan_diagonal_NW(target, size) +
          scan_diagonal_SW(target, size);
}
