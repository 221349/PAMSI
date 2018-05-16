#include "../inc/Table.h"
#include "../inc/heap.h"

template <typename T>
void Table<T>::maxHeapify(int begin, int end, int i)
{
  int vleft = left(i);
  vleft = index(begin, vleft);
  int vright = right(i);
  vright = index(begin, vright);
  int largest = i = index(begin, i);
  if((vleft <= end) && (*table[vleft] > *table[largest]))
  {
    largest = vleft;
  }
  if((vright <= end) && (*table[vright] > *table[largest]))
  {
    largest = vright;
  }
  if(largest != i)
  {
    swap(i, largest);
    maxHeapify(begin, end, largest - begin + 1);
  }
}

template <typename T>
void Table<T>::maxHeapBuild(int begin, int end)
{
  for(int i = (end - begin + 1) / 2; i > 0; i--)
  {
    maxHeapify(begin, end, i);
  }
}

template <typename T>
void Table<T>::heapSort(int begin, int end)
{
  maxHeapBuild(begin, end);
  int first = index(begin, 1);
  int si = index(begin, end - begin + 1);
  for(int i = end - begin + 1; i > 1; i--)
  {
    swap(si, first);
    end--;
    si--;
    maxHeapify(begin, end, 1);
  }
}
