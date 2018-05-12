#ifndef TABLEMSORT_H
#define TABLEMSORT_H
#include <iostream>
using namespace std;

template <typename T>
class tableMSort{
public:
  T ** table;
  int size;

  tableMSort();
  tableMSort(int size);
  tableMSort(int size, T ** in);
  ~tableMSort();
  void sortMerge();
  void split(tableMSort * a, tableMSort * b);
  void merge(tableMSort * a, tableMSort * b);
};

#endif
