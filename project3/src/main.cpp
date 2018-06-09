#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include <vector>
#include "../inc/gameTree.h"


//using namespace std;

Movement ask(){
  int x, y;
  std::cout << "\nX:";
  std::cin >> x;
  std::cout << "\nY:";
  std::cin >> y;
  return Movement(x, y, X);
}

int main(int argc, char *argv[])
{
  Board desk(3,3);
  system("clear");

  Movement mov(0, 0, O);
  Conditions co;
  co.row_size = 3;
  co.win_rate = 6;
  co.player0 = X;
  co.player1 = O;
  desk.display();
  MM_tree_node tree;
  tree.calc_best_move(desk, co, co.player0, 1);
  //mov = ask();

  while(!tree.game_over(co)){
    if(mov.cell() == co.player1){
      mov = ask();
    }
    else{
      mov = tree.calc_best_move(desk, co, co.player1, 100);
    }
    desk.do_move(mov);
    desk.display();
  }

  std::cout << "\n V: " << tree.value;
  std::cin.get();

  return 0;
}
