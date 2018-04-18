#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.cpp"

using namespace std;

int main(int argc, char *argv[]){

  srand (time(NULL));
  AVLTree <int> a;
  int n = 9;
  int buf = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp = 1;
    for(int j = 0; j < i; j++)
    {
      tmp *=2;
    }
    buf += tmp;
  }
  for (int i = 0; i < buf*10 ; i++)
  {
    int tmp = 0;
    if((rand() % 2) == 1)
    {
      tmp = rand() % (buf+1)/2;
    }
    else
    {
      tmp = -rand() % (buf+1)/2;
    }
    a.add(tmp);
  }
  a.display();
  /*
  AVLTree <int> a;
  for(int i = 0; i < 511; i++)
  {
    a.add(i);
  }
  */
  a.display();
  return 0;
}
