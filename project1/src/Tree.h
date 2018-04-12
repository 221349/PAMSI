#ifndef TREE_H
#define TREE_H

using namespace std;

template <typename V>
class Node{
private:
  V value;
  Node<V> * left;
  Node<V> * right;
public:
  Node();
  Node(V in);
  Node<V> * addLeft(V in);
  Node<V> * addRight(V in);

  V getValue();
  Node<V> * getLeft();
  Node<V> * getRight();
  int maxHeight();
  int minHeight();
  int check();
  int balance();

  Node<V> * rotateRight();
  Node<V> * rotateLeft();
};

template <typename V>
class AVLTree{
private:
  Node<V> * main;
public:
  int add(V in);
  int search(V in);
  int remove(V in);
  V find(V in);
  void show();
};

#endif
