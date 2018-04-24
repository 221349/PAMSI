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
public:
  Table();
  Table(int amount);
  ~Table();
  void add(T in);
  int removeLast();

  T get(int num);
};

#endif
