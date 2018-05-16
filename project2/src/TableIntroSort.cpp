#include "../inc/Table.h"

template <typename T>
void Table<T>::introSortPmiddlePivot(int begin, int end, int maxdepth)
{
  int endP = quickSortPmiddleOrder(begin, end);
  introSortPmiddle(begin, endP, maxdepth);
  introSortPmiddle(endP + 2, end, maxdepth);
}

template <typename T>
void Table<T>::introSortPmiddle(int begin, int end, int maxdepth)
{
  if((end - begin) < 1) return;
  if(maxdepth < 1)
  {
    heapSort(begin, end);
  }
  else
  {
    swap((begin + (end - begin) / 2), end);
    introSortPmiddlePivot(begin, end, maxdepth-1);
  }
}
