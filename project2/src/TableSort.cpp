#include <cmath>

#include "../inc/tableMSort.h"
#include "../inc/Table.h"

template <typename T>
int Table<T>::checkSorted()
{
  for(int i = 0; i < amount -1; i++)
  {
    if(*table[i] > *table[i+1]) return 1;
  }
  return 0;
}


template <typename T>
void Table<T>::mergeSort()
{
  tableMSort <T> *tmp = new tableMSort <T> (amount, table);
  tmp->sortMerge();
  for (int i = 0; i < amount; i++)
  {
    table[i] = tmp->table[i];
  }
  delete tmp;
}

template <typename T>
void Table<T>::quickSort()
{
  quickSortPmiddle(0,amount-1);
}

template <typename T>
void Table<T>::heapSort()
{
  heapSort(0,amount-1);
}

template <typename T>
void Table<T>::introSort()
{
  int maxdepth = log(amount);
  introSortPmiddle(0, amount-1, maxdepth);
}
