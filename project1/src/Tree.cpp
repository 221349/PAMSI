#include "Tree.h"

template <typename V>
Node<V>::Node(V in)
{
  value = in;
  left = 0;
  right = 0;
}
template <typename V>
Node<V>::Node()
{
  left = 0;
  right = 0;
}

template <typename V>
V Node<V>::getValue()
{
  return value;
}

template <typename V>
Node<V> * Node<V>::getLeft()
{
  return left;
}
template <typename V>
Node<V> * Node<V>::getRight()
{
  return right;
}

template <typename V>
int Node<V>::maxHeight()
{
  int out = 0;
  int tmp = 0;
  if(left)
  {
    out += left->maxHeight();
  }
  if(right)
  {
    tmp = right->maxHeight();
    if(out < tmp)
    {
      out = tmp;
    }
  }
  out++;
  return out;
}
