#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Table.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  Table <int> *h = new Table <int>(100000000);
  int t = 10000000;

  cin >> t;
  for(int i = 0; i < t; i++)
  {
    h->add(i);
  }
  cout << "step 1\n";
  cin >> t;
  for(int i = 0; i < t; i++)
  {
//    h->removeLast();
    // cout << h->get(i) << " ";
  }
  cout << "step 2\n";
  cin >> t;
  delete h;
  cout << "step 3\n";
  cin >> t;

  cout << "end\n";
  return 0;
}
