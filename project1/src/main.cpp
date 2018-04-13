#include <iostream>
#include "Tree.cpp"


using namespace std;

int main(int argc, char *argv[]){
  AVLTree <int> a;
  //  cout << a.tmp() << endl ;
    Node <int> b(8);
  cout << b.add(7) << endl;
  cout << b.add(3) << endl;
  cout << b.add(-1) << endl;
  cout << b.add(5) << endl;
  cout << b.add(1) << endl;
  cout << b.add(2) << endl;
  cout << b.add(0) << endl;
  cout << b.add(7) << endl;
  cout << b.minHeight() << endl;
  return 0;
}
