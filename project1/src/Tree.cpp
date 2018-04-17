#include "Tree.h"

/*
  Constructors
*/
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

/*
  Gets
*/
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

template <typename V>
int Node<V>::minHeight()
{
  int out = 0;
  int tmp = 0;
  if(left)
  {
    out += left->minHeight();
  }
  else
  {
    return 1;
  }
  if(right)
  {
    tmp = right->minHeight();
    if(out > tmp)
    {
      out = tmp;
    }
  }
  else
  {
    return 1;
  }
  out++;
  return out;
}

template <typename V>
int Node<V>::add(V in)
{
  if(in == value) // check if same node exis
  {
    return 1;
  }
  else
  {
    // add to left branch
    if(in < value)
    {
      if(!left)
      {
        left = new Node(in);
      }
      else
      {
        if(left->add(in))
        {
          return 1;
        }
      }
      return 0;
    }
    // add to right branch
    else
    {
      if(!right)
      {
        right = new Node(in);
      }
      else
      {
        if(right->add(in))
        {
          return 1;
        }
      }
      return 0;
    }

  }
}

template <typename V>
int Node<V>::differenceFactor()
{
  return (this->maxHeight() - this->minHeight());
}

template <typename V>
int Node<V>::balanceFactor()
{
  int mright = 0;
  int mleft = 0;
  if(left)
  {
    mleft = left->maxHeight();
  }
  if(right)
  {
    mright = right->maxHeight();
  }
  return (mright - mleft);
}

template <typename V>
Node<V> * Node<V>::rotateLeft()
{
  Node<V> * tmp = right;
  right = right->left;
  tmp->left = this;
  return tmp;
}

template <typename V>
Node<V> * Node<V>::rotateRight()
{
  Node<V> * tmp = left;
  left = left->right;
  tmp->right = this;
  return tmp;
}

template <typename V>
Node<V> * Node<V>::balance()
{
  if(this->differenceFactor() > 1)
  {
    if(left)
    {
      if(left->differenceFactor() > 1)
      {
        left = left->balance();
      }
    }
    if(right)
    {
      if(right->differenceFactor() > 1)
      {
        right = right->balance();
      }
    }
    if(this->balanceFactor() > 1)
    {
      return this->rotateLeft();
    }
    if(this->balanceFactor() < -1)
    {
      return this->rotateRight();
    }
    else
    {
      return this;
    }
  }
  else
  {
    return this;
  }
}

template <typename V>
int Node<V>::display(int level)
{
  int out = 1;
  if(right)
  {
    out += right->display(level + 1);
    for(int i = 0; i < level; i++)
    {
      cout << "  ";
    }
    cout << " /\n";
  }
  for(int i = 0; i < level; i++)
  {
    cout << "  ";
  }
  cout << value << endl;
  if(left)
  {
    for(int i = 0; i < level; i++)
    {
      cout << "  ";
    }
    cout << " \\\n";
    out += left->display(level + 1);
  }
  return out;
}

template <typename V>
int AVLTree<V>::add(V in)
{
  if(!main)
  {
    main = new Node<V>(in);
    return 0;
  }
  else
  {
    if(main->add(in))
    {
      return 1;
    }
    main = main->balance();
    return 0;
  }
}

template <typename V>
void AVLTree<V>::display()
{
  if(main)
  {
    int nodes = main->display(0);
    cout << "\n\n  Nodes: " << nodes;
    cout << "\n  Height: " << main->maxHeight() << endl;
  }
  else
  {
    cout << "No tree\n";
  }
}


template <typename V>
void AVLTree<V>::tmp()
{
  main = main->rotateLeft();
}
