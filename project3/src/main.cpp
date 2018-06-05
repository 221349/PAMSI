#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include <vector>
#include "../inc/gameTree.h"


//using namespace std;


int main(int argc, char *argv[])
{
  std::vector<int> a(12);

  movement w1;
  w1.x = 1;
  w1.y = 2;
  w1.cell = X;
  desk de(6,5);
  system("clear");
  de.display();

  de.do_move(w1);
  std::cin.get();
  return 0;
}
