#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include <vector>
#include "../inc/gameTree.h"


//using namespace std;


int main(int argc, char *argv[])
{
  Board de(3,3);
  system("clear");

  Movement ss(1, 1, O);
  Conditions co;
  co.row_size = 3;
  co.win_rate = 4;
  co.player0 = X;
  co.player1 = O;

  MM_tree_node tree(de, ss, co, O, 9);
  std::cout << "\n V: " << tree.value;
  std::cin.get();

  return 0;
}
