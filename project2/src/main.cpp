#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "../inc/Table.h"
#include "../inc/tableMSort.h"
#include "../inc/heap.h"

using namespace std;

void addRandom(Table <int> *in, int size, int interval);
void addSorted(Table <int> *in, int size);

int main(int argc, char *argv[])
{
  if(argc < 4){
        cout << "There is " << argc - 1 << " arguments. Need 3\n";
        return 1;
  }

  int size = std::stoi(argv[2]);
  float sorted = std::stoi(argv[3]);

  auto tstart = chrono::steady_clock::now();
  auto tend = chrono::steady_clock::now();
  Table <int> *dummy = new Table <int>;

  if(sorted > 0)
  {
    addSorted(dummy, size * (sorted / 100));
    addRandom(dummy, size - size * (sorted / 100), size*2);
  }
  if(sorted <= 0)
  {
    addSorted(dummy, size * (sorted / -100));
    dummy->reverse();
    addRandom(dummy, size - size * (sorted / -100), size*2);
  }
//  for(int i = 0; i < size; i++) cout << dummy->get(i) << " ";

  if(argv[1][0] == 'm')
  {
    tstart = chrono::steady_clock::now();
    dummy->mergeSort();
    tend = chrono::steady_clock::now();
  }
  if(argv[1][0] == 'q')
  {
    tstart = chrono::steady_clock::now();
    dummy->quickSort();
    tend = chrono::steady_clock::now();
  }
  if(argv[1][0] == 'h')
  {
    tstart = chrono::steady_clock::now();
    dummy->heapSort();
    tend = chrono::steady_clock::now();
  }
  if(argv[1][0] == 'i')
  {
    tstart = chrono::steady_clock::now();
    dummy->introSort();
    tend = chrono::steady_clock::now();
  }

  auto tDelta = tend - tstart;
  cout << chrono::duration <double, milli> (tDelta).count() << endl;
  delete dummy;
  return 0;
}


void addRandom(Table <int> *in, int size, int interval){
  srand (time(NULL));
  for(int i = 0; i < size; i++)
  {
    int tmp = 0;
    if((rand() % 2) == 1)
    {
      tmp = rand() % (interval / 2);
    }
    else
    {
      tmp = -rand() % (interval / 2);
    }
    in->add(tmp);
  }
}
void addSorted(Table <int> *in, int size){
  for(int i = 0; i < size; i++) in->add(i - size/2);
}
