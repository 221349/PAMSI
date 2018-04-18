#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

template <typename V>
class Node
{
private:
  V * value;
  Node<V> * left;
  Node<V> * right;
public:
  Node();
  Node(V in);
  ~Node();
  int add(V in);
  int find(V * buf);
  Node<V> * remove(V in);

  V getValue();
  Node<V> * getLeft();
  Node<V> * getRight();
  int maxHeight();
  int minHeight();
  int differenceFactor();
  int balanceFactor();

  Node<V> * removeMin();
  Node<V> * rotateRight();
  Node<V> * rotateLeft();
  Node<V> * balance();

  int display(int level);
  int preOrder(int level);
  int inOrder(int level);
  int postOrder(int level);
};

template <typename V>
class AVLTree{
private:
  Node<V> * root;
public:
  AVLTree();
  int add(V in);
  int remove(V in);
  V find(V in);
  void display();
  void preOrder();
  void inOrder();
  void postOrder();
};

#endif
