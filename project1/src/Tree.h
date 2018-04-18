#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Node.cpp"

using namespace std;


template <typename V>
class AVLTree{
private:
  Node<V> * root;
public:
  AVLTree();
  int add(V in);
  int remove(V in);
  int find(V * buf);
  void display();
  void preOrder();
  void inOrder();
  void postOrder();
};

#endif
