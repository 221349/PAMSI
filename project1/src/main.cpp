#include <iostream>
#include "Tree.cpp"


using namespace std;

int main(int argc, char *argv[]){
  Node <int> a(5);
//  cout << a.tmp() << endl ;
  cout << a.getLeft() << endl;
  cout << a.maxHeight();
  return 0;
}
