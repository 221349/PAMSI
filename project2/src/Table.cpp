#include "Table.h"

template <typename T>
Table<T>::Table()
{
  size = 0;
  amount = 0;
  table = 0;
}

template <typename T>
Table<T>::Table(int amount)
{
  size = amount;
  this->amount = amount;
  table = new  T * [size];
  this->writeNull();
}

/* allocate
template <typename T>
void Table<T>::allocate(int amount)
{
  if(amount > size) return 1;
  for (int i = 0; i < size; i++)
  {
    table[i] = new T;
  }
  return 0;
}
*/

template <typename T>
void Table<T>::writeNull()
{
  for (int i = 0; i < size; i++)
  {
    table[i] = 0;
  }
}
