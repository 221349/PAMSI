#include "tableMSort.cpp"
#include "Table.h"


template <typename T>
Table<T>::Table()
{
  size = 0;
  amount = 0;
  table = 0;
}

template <typename T>
Table<T>::Table(int size)
{
  amount = 0;
  this->size = size;
  table = new  T * [size];
  this->writeNull();
}

template <typename T>
Table<T>::~Table()
{
  for (int i = 0; i < size; i++)
  {
    delete table[i];
  }
  delete[] table;
}


template <typename T>
void Table<T>::add(T in)
{
  if(amount >= size) this->resize(size * 2 + 1);
  table[amount] = new T;
  *table[amount] = in;
  amount++;
}


template <typename T>
void Table<T>::writeNull()
{
  for (int i = 0; i < size; i++)
  {
    table[i] = 0;
  }
}

template <typename T>
int Table<T>::resize(int newSize)
{
  if(newSize <= amount) return 1;
  T ** tmp = table;
  size = newSize;
  table = new  T * [size];
  this->writeNull();
  for (int i = 0; i < amount; i++)
  {
    table[i] = tmp[i];
  }
  delete[] tmp;
  return 0;
}

template <typename T>
int Table<T>::removeLast()
{
  if(amount < 1) return 1;
  delete table[amount - 1];
  amount--;
  table[amount] = 0;
  if(amount < size / 2) this->resize(amount + 1);
  return 0;
}

template <typename T>
int Table<T>::getAmount()
{
  return amount;
}

template <typename T>
T Table<T>::get(int num)
{
  if(table[num]) return * table[num];
  else return 0;
}

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
void Table<T>::sortMerge()
{
  tableMSort <T> *tmp = new tableMSort <T> (amount, table);
  tmp->sortMerge();
  for (int i = 0; i < amount; i++)
  {
    table[i] = tmp->table[i];
  }
  delete tmp;
}
