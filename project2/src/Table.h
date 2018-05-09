#ifndef TABLE_H
#define TABLE_H
#include <iostream>
using namespace std;

template <typename T>
class Table{
private:
  T ** table;
  int size, amount;

  void writeNull();
  int resize(int newSize);
  int checkSorted();
  int checkReverseSorted();
//  void reverse();
public:

  void reverse();
  Table();
  Table(int amount);
  ~Table();
  void add(T in);
  int removeLast();

  T get(int num);
  int getAmount();
  int sort();
  void sortMerge();
};

#endif
