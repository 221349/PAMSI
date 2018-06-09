
#include <iostream>

#include "../inc/gameElements.h"

void desk::display(){
  if((x_size == 0) || (y_size == 0)) return;
  std::cout << "╔═══╦";
  for(int x = 0; x < x_size - 1; x++) std::cout << "═══╦";
  std::cout << "═══╗\n";
  std::cout << "║   ║ ";
  for(int x = 0; x < x_size; x++) std::cout << x << " ║ ";
  std::cout << "\n";
  std::cout << "╠═══╬";
  for(int x = 0; x < x_size - 1; x++) std::cout << "═══╬";
  std::cout << "═══╣\n";

  for(int y = 0; y < y_size - 1; y++){
    std::cout << "║ " << y << " ║ ";
    for(int x = 0; x < x_size - 1; x++){
      std::cout << field[x][y] << " │ ";
    }
    std::cout << field[x_size - 1][y] << " ║";
    std::cout << "\n╠═══╬";
    for(int x = 0; x < x_size - 1; x++) std::cout << "───┼";
    std::cout << "───╢\n";
  }
  std::cout << "║ " << y_size - 1 << " ║ ";
  for(int x = 0; x < x_size - 1; x++){
    std::cout << field[x][y_size - 1] << " │ ";
  }
  std::cout << field[x_size - 1][y_size - 1] << " ║";
  std::cout << "\n╚═══╩";
  for(int x = 0; x < x_size - 1; x++) std::cout << "═══╧";
  std::cout << "═══╝\n";
}
