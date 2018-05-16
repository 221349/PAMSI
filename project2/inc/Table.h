#ifndef TABLE_H
#define TABLE_H
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

  void maxHeapify(int begin, int end, int i);
  void maxHeapBuild(int begin, int end);
  void heapSort(int begin, int end);

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
  void heapSort();
};

template class Table<int>;
template class Table<float>;
template class Table<long>;
template class Table<char>;
template class Table<double>;

#endif
