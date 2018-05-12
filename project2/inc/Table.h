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
  void swap(int a, int b);
  void quickSortPmiddle(int begin, int end);
  void quickSortPmiddleOrder(int begin, int end);
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
  void mergeSort();
  void quickSort();
};

#endif
