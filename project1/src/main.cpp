#include <iostream>
#include "Tree.cpp"


using namespace std;

int main(int argc, char *argv[]){
  AVLTree <int> a;
  //  cout << a.tmp() << endl ;
  a.display();
    Node <int> b(8);
  cout << a.add(7) << endl;
  cout << a.add(3) << endl;
  cout << a.add(-1) << endl;
  cout << a.add(5) << endl;
  cout << a.add(1) << endl;
  cout << a.add(2) << endl;
  cout << a.add(0) << endl;
  cout << a.add(12) << endl;
  cout << a.add(10) << endl;
  cout << a.add(9) << endl;
  cout << a.add(11) << endl;
  cout << a.add(16) << endl;
  cout << a.add(14) << endl;
  cout << a.add(29) << endl;
  a.display();
  return 0;
}
