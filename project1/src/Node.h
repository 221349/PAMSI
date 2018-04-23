#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename V>
class Node
{
private:
  V * value;
  Node<V> * left;
  Node<V> * right;

  Node<V> * rotateRight();
  Node<V> * rotateLeft();
  int differenceFactor();
  int balanceFactor();
  Node<V> * removeMin();
public:
  Node();
  Node(V in);
  ~Node();
  int add(V in);
  int find(V * buf);
  Node<V> * remove(V in, int * rm_flag);
  Node<V> * balance();

  int maxHeight();
  int minHeight();

  int display(int level);
  int preOrder(int level);
  int inOrder(int level);
  int postOrder(int level);
};

#endif
