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
template <typename V>
Node<V>::~Node()
{
  if(right)
  {
    delete right;
  }
  if(left)
  {
    delete left;
  }
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

  int minleft = 0;
  int maxleft = 0;
  int minright = 0;
  int maxright = 0;
  if(left)
  {
    minleft = left->minHeight();
    maxleft = left->maxHeight();
  }
  if(right)
  {
    minright = right->minHeight();
    maxright = right->maxHeight();
  }
  if((maxright - minleft) > (maxleft - minright))
  {
    return maxright - minleft;
  }
  if((maxleft - minright) > (maxright - minleft))
  {
    return minright - maxleft;
  }
  return maxright - maxleft;
}

template <typename V>
Node<V> * Node<V>::rotateLeft()
{
  if(!right)
  {
    return this;
  }
  Node<V> * tmp = right;
  right = right->left;
  tmp->left = this;
  if(tmp->left)
  {
    tmp->left = tmp->left->balance();
  }
  if(tmp->right)
  {
    tmp->right = tmp->right->balance();
  }
  return tmp;
}

template <typename V>
Node<V> * Node<V>::rotateRight()
{
  if(!left)
  {
    return this;
  }
  Node<V> * tmp = left;
  left = left->right;
  tmp->right = this;
  if(tmp->left)
  {
    tmp->left = tmp->left->balance();
  }
  if(tmp->right)
  {
    tmp->right = tmp->right->balance();
  }
  return tmp;
}

template <typename V>
Node<V> * Node<V>::balance()
{
  /*
    Additional branches balancing
    */
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
  }
  /*
    Main balancing
    */
  if(this->balanceFactor() > 1)
  {
    if(right)
    {
      if(right->balanceFactor() == 1)
      {
        right = right->rotateRight();
      }
    }
    return this->rotateLeft();
  }
  if(this->balanceFactor() < -1)
  {
    if(left)
    {
      if(left->balanceFactor() == 1)
      {
        left = left->rotateLeft();
      }
    }
    return this->rotateRight();
  }
  return this;
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
Node<V> * Node<V>::remove(V in)
{
  if(in == value) // check if same node exis
  {
    if(right)
    {
      if(right->left)
      {
        Node<V> * tmp = right->removeMin();
        tmp->left = left;
        tmp->right = right;
        return tmp;
      }
      Node<V> * tmp = right;
      tmp->left = left;
      return tmp;
    }
    if(left)
    {
      return left;
    }
    return 0;
  }
    // remove from left branch
  if(left)
  {

    if(in < value)
    {
      left = left->remove(in);
      return this;
    }
  }
    // remove from right branch
  if(right)
  {
    {
      right = right->remove(in);
      return this;
    }
  }
  return this;
}

template <typename V>
Node<V> * Node<V>::removeMin()
{
  if(!left->left)
  {
    Node<V> * tmp = left;
    left = left->right;
    tmp->left = 0;
    tmp->right = 0;
    return tmp;
  }
  return left->removeMin();
}


template <typename V>
AVLTree<V>::AVLTree()
{
  root = 0;
}

template <typename V>
int AVLTree<V>::add(V in)
{
  if(!root)
  {
    root = new Node<V>(in);
    return 0;
  }
  else
  {
    if(root->add(in))
    {
      return 1;
    }
    root = root->balance();
    return 0;
  }
}


template <typename V>
int AVLTree<V>::remove(V in)
{
  if(!root)
  {
    return 1;
  }
  else
  {
    root = root->remove(in);
    root = root->balance();
    return 0;
  }
}

template <typename V>
void AVLTree<V>::display()
{
  if(root)
  {
    int nodes = root->display(0);
    cout << "\n  Nodes: " << nodes;
    cout << "\n  Height: " << root->maxHeight() << endl;
  }
  else
  {
    cout << "No tree\n";
  }
}
