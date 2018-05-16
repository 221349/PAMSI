#ifndef TABLE_H
#define TABLE_H
using namespace std;
#include <iostream>

template <typename T>
class Table{
private:
  T ** table;
  int size, amount;

  void writeNull();
  int resize(int newSize);

  inline void swap(int a, int b){
    //if((a > size) || (b > size)) return;
//    cout << "s";
    T * tmp;
    tmp = table[a];
    table[a] = table[b];
    table[b] = tmp;
  }

  void maxHeapify(int begin, int end, int i);
  void maxHeapBuild(int begin, int end);
  void heapSort(int begin, int end);

  void quickSortPmiddle(int begin, int end);
  void quickSortPmiddlePivot(int begin, int end);
  int  quickSortPmiddleOrder(int begin, int end);

  void introSortPmiddle(int begin, int end, int maxdepth);
  void introSortPmiddlePivot(int begin, int end, int maxdepth);
public:
  Table();
  Table(int amount);
  ~Table();
  void add(T in);
  int removeLast();
  void reverse();

  T get(int num);
  int getAmount();
  void mergeSort();
  void quickSort();
  void heapSort();
  void introSort();
  int checkSorted();
};

template class Table<int>;
template class Table<float>;
template class Table<long>;
template class Table<char>;
template class Table<double>;

#endif
