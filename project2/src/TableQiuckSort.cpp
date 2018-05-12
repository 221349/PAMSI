#include "../inc/Table.h"


template <typename T>
void Table<T>::quickSortPmiddleOrder(int begin, int end)
{
  int beginP = begin;
  int endP = end - 1;
  for(int i = begin; (i < end) && (endP >= beginP); i++)
  {
    if(*table[beginP] <= *table[end])
    {
      if(*table[endP] > *table[end])
      {
        endP--;
      }
      beginP++;
    }
    else
    {
      if(*table[endP] <= *table[end])
      {
        swap(beginP, endP);
        beginP++;
      }
      endP--;
    }
  }
  swap(endP+1, end);
  quickSortPmiddle(begin, endP);
  quickSortPmiddle(endP + 2, end);
}

template <typename T>
void Table<T>::quickSortPmiddle(int begin, int end)
{
  if((end - begin) < 1) return;
  swap((begin + (end - begin) / 2), end);
  quickSortPmiddleOrder(begin, end);
}


template class Table<int>;
template class Table<float>;
template class Table<long>;
template class Table<char>;
template class Table<double>;
template class Table<string>;
