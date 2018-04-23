#ifndef TABLE_H
#define TABLE_H

using namespace std;

template <typename T>
class Table{
private:
  T ** table;
  int size, amount;
//  int allocate(int amount);
  void writeNull();
  void grow(int newSize);
public:
  Table();
  Table(int amount);
  ~Table();
  int add(T in);
  int remove(T in);

};

#endif
