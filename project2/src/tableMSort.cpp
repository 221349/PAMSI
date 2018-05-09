#include "tableMSort.h"

template <typename T>
tableMSort<T>::tableMSort()
{
  size = 0;
  table = 0;
}

template <typename T>
tableMSort<T>::tableMSort(int size)
{
  this->size = size;
  table = new  T * [size];
}

template <typename T>
tableMSort<T>::tableMSort(int size, T ** in)
{
  this->size = size;
  table = new  T * [size];
  for(int i = 0; i < size; i++)
  {
    table[i] = in [i];
  }
}

template <typename T>
tableMSort<T>::~tableMSort()
{
  delete[] table;
}

template <typename T>
void tableMSort<T>::sortMerge()
{
  if(size < 2) return;
  tableMSort <T> * a = new tableMSort <T> (size - (size / 2));
  tableMSort <T> * b = new tableMSort <T> (size / 2);
  this->split(a, b);
  a->sortMerge();
  b->sortMerge();
  this->merge(a, b);
  delete a;
  delete b;
}

template <typename T>
void tableMSort<T>::split(tableMSort * a, tableMSort * b)
{
  int aSize = size - (size / 2);
  for(int i = 0; i < size; i++)
  {
    if(i < aSize)
    {
      a->table[i] = table[i];
    }
    else
    {
      b->table[i - aSize] = table[i];
    }
  }
}

template <typename T>
void tableMSort<T>::merge(tableMSort * a, tableMSort * b)
{
  int aP = 0;
  int bP = 0;
  for(int i = 0; i < size; i++)
  {
    if((aP == a->size) && (bP < b->size))
    {
      table[i] = b->table[bP];
      if(bP < (b->size)) bP++;
    }
    if((bP == b->size) && (aP < a->size))
    {
      table[i] = a->table[aP];
      if(aP < (a->size)) aP++;
    }
    if((aP < a->size) && (bP < b->size))
    {
      if(*a->table[aP] <= *b->table[bP])
      {
        table[i] = a->table[aP];
        if(aP < (a->size)) aP++;
      }
      else
      {
        table[i] = b->table[bP];
        if(bP < (b->size)) bP++;
      }
    }
  }
}
