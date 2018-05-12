#include "../inc/tableMSort.h"
#include "../inc/Table.h"

template <typename T>
void Table<T>::reverse()
{
  T * tmp;
  for (int i = 0; i < amount/2; i++)
  {
    tmp = table[i];
    table[i] = table[amount - i -1];
    table[amount - i -1] = tmp;
  }
}

template <typename T>
void Table<T>::swap(int a, int b)
{
  if((a > size) || (b > size)) return;
//  cout << "\nswap: a: " << table[a] << " b: " << table[b];
  T * tmp;
  tmp = table[a];
  table[a] = table[b];
  table[b] = tmp;
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


template class Table<int>;
template class Table<float>;
template class Table<long>;
template class Table<char>;
template class Table<double>;
template class Table<string>;
