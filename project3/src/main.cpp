#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include <vector>
#include "../inc/gameTree.h"


//using namespace std;


int main(int argc, char *argv[])
{
  desk de(4,3);
  int t = 0;
  system("clear");

  std::vector<movement> mov = de.get_moves(X);
  while(!mov.empty()){
    std::cin >> t;
    if(t == 1)  de.do_move(mov.back());
    de.display();
    mov.pop_back();
    std::cin.get();
  }
  de.display();
  std::cout << de.scan(X, 3);
  std::cin.get();

  return 0;
}
