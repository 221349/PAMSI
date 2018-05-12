#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../inc/Table.h"
//#include "TableSort.cpp"
//#include "TableQiuckSort.cpp"
#include "../inc/tableMSort.h"

using namespace std;

int main(int argc, char *argv[])
{

  int t = 0;
  int f;
  srand (time(NULL));
  cin >> t;
  Table <int> *h = new Table <int>(t);
  for(int i = 0; i < t; i++)
  {
    int tmp = 0;
    if((rand() % 2) == 1)
    {
      tmp = rand() % (t*3+1)/2;
    }
    else
    {
      tmp = -rand() % (t*3+1)/2;
    }
    h->add(tmp);
  }
  /*
  cin >> f;
  for(int i = 0; i < t; i++)
  {
    cout << h->get(i) << " ";
  }*/
  cout << endl;
//  cin >> f;
//  h->mergeSort();
  cin >> f;
  h->quickSort();
  cin >> f;
  /*
  for(int i = 0; i < t; i++)
  {
     //h->removeLast();
     cout << h->get(i) << " ";
  }*/
  cout << endl;

  cin >> f;
  delete h;
  cin >> f;
  return 0;
}
