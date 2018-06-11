#include "../inc/Board.h"

Board::Board(){
  x_size = 0;
  y_size = 0;
  field = 0;
}

Board::Board(int x_size, int y_size){
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

Board::Board(const Board &in){
  x_size = in.x();
  y_size = in.y();
  field = new char * [x_size];
  for(int x = 0; x < x_size; x++){
    field[x] = new char[y_size];
    for(int y = 0; y < y_size; y++){
      field[x][y] = in.field_pointer()[x][y];
    }
  }
}

void Board::operator = (const Board &in){
  for(int x = 0; x < x_size; x++)
    delete[] field[x];
  delete[] field;

  x_size = in.x();
  y_size = in.y();
  field = new char * [x_size];
  for(int x = 0; x < x_size; x++){
    field[x] = new char[y_size];
    for(int y = 0; y < y_size; y++){
      field[x][y] = in.field_pointer()[x][y];
    }
  }
}

Board::~Board(){
  for(int x = 0; x < x_size; x++)
    delete[] field[x];
  delete[] field;
}

void Board::clear(){
  for(int x = 0; x < x_size; x++){
    for(int y = 0; y < y_size; y++){
      field[x][y] = BLANK;
    }
  }
}

int Board::check_free(int x, int y){
  if((x >= x_size) || (y >= y_size) || (x < 0) || (y < 0))
    return -1;
  if(field[x][y] == BLANK) return 0;
  else return 1;
}

void Board::setup(int x_size_, int y_size_){
  for(int x = 0; x < x_size; x++)
    delete[] field[x];
  delete[] field;

  x_size = x_size_;
  y_size = y_size_;
  field = new char * [x_size];
  for(int x = 0; x < x_size; x++){
    field[x] = new char[y_size];
    for(int y = 0; y < y_size; y++){
      field[x][y] = BLANK;
    }
  }
}

int Board::do_move(Movement in){
  if((in.x() >= x_size) || (in.y() >= y_size) || (in.x() < 0) || (in.y() < 0))
    return -1;
  field[in.x()][in.y()] = in.cell();
  return 0;
}

int Board::undo_move(Movement in){
  if((in.x() >= x_size) || (in.y() >= y_size) || (in.x() < 0) || (in.y() < 0))
    return -1;
  field[in.x()][in.y()] = BLANK;
  return 0;
}

int Board::count(const char in){
  int tmp = 0;
  for(int x = 0; x < x_size; x++){
    for(int y = 0; y < y_size; y++){
      if(field[x][y] == in)
        tmp++;
    }
  }
  return tmp;
}

std::vector<Movement> Board::get_moves(const char in){
  std::vector<Movement> moves;
  for(int x = 0; x < x_size; x++){
    for(int y = 0; y < y_size; y++){
      if(field[x][y] == BLANK){
        Movement tmp(x, y, in);
        //moves.insert(moves.begin(), tmp);
        moves.push_back(tmp);
      }
    }
  }
  return moves;
}

int Board::scan_horizontal(const char target, const int size){
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

int Board::scan_vertical(const char target, const int size){
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

int Board::scan_diagonal_NW(const char target, const int size){
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

int Board::scan_diagonal_SW(const char target, const int size){
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

int Board::scan(const char target, const int size){
  return scan_horizontal(target, size) +
          scan_vertical(target, size) +
          scan_diagonal_NW(target, size) +
          scan_diagonal_SW(target, size);
}


int Board::scan_horizontal(const Movement &move, const int size){
  if((move.x() < 0)||(move.x() >= x_size)) return 0;
  if((move.y() < 0)||(move.y() >= y_size)) return 0;
  int out = 0;
  int buf = 0;
  for(int x = 0; x < x_size; x++){
    if(field[x][move.y()] == move.cell()) buf++;
    else{
      if(buf >= size) out++;
      buf = 0;
    }
  }
  if(buf >= size) out++;
  return out;
}

int Board::scan_vertical(const Movement &move, const int size){
  if((move.x() < 0)||(move.x() >= x_size)) return 0;
  if((move.y() < 0)||(move.y() >= y_size)) return 0;
  int out = 0;
  int buf = 0;
  for(int y = 0; y < y_size; y++){
    if(field[move.x()][y] == move.cell()) buf++;
    else{
      if(buf >= size) out++;
      buf = 0;
    }
  }
  if(buf >= size) out++;
  return out;
}

int Board::scan_diagonal_NW(const Movement &move, const int size){
  if((move.x() < 0)||(move.x() >= x_size)) return 0;
  if((move.y() < 0)||(move.y() >= y_size)) return 0;
  int out = 0;
  int buf = 0;
  if(move.x() >= move.y()){
    for(int x = move.x() - move.y(), y = 0; (y < y_size)&&(x < x_size); x++, y++){
      if(field[x][y] == move.cell()) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
  }
  else{
    for(int x = 0, y = move.y() - move.x(); (y < y_size)&&(x < x_size); x++, y++){
      if(field[x][y] == move.cell()) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
  }
  return out;
}

#include <iostream>

int Board::scan_diagonal_SW(const Movement &move, const int size){
  if((move.x() < 0)||(move.x() >= x_size)) return 0;
  if((move.y() < 0)||(move.y() >= y_size)) return 0;
  int out = 0;
  int buf = 0;
  if(move.x() + move.y() < x_size){
    for(int x = move.x() + move.y(), y = 0; (y < y_size)&&(x >= 0); x--, y++){
      if(field[x][y] == move.cell()) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
  }
  else{
    for(int x = x_size-1, y = move.x() + move.y() + 1 - x_size; (y < y_size)&&(x >= 0); x--, y++){
      if(field[x][y] == move.cell()) buf++;
      else{
        if(buf >= size) out++;
        buf = 0;
      }
    }
    if(buf >= size) out++;
  }
  return out;
}

int Board::scan(const Movement &move, const int size){
  return scan_horizontal(move, size) +
         scan_vertical(move, size) +
         scan_diagonal_NW(move, size) +
         scan_diagonal_SW(move, size);
}

int Board::game_over(const Conditions &rules){
  if(scan(rules.player0, rules.row_size)) return 1;
  if(scan(rules.player1, rules.row_size)) return 2;
  if(!count(BLANK)) return -1;
  return 0;
}
