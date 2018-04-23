#include "Node.h"

/*
  Constructors
*/
template <typename V>
Node<V>::Node(V in)
{
  value = new V;
  *value = in;
  left = 0;
  right = 0;
}
template <typename V>
Node<V>::Node()
{
  value = new V;
  left = 0;
  right = 0;
}
template <typename V>
Node<V>::~Node()
{
  delete value;
  delete left;
  delete right;
  value = 0;
  left = 0;
  right = 0;
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
int Node<V>::add(V in)
{
  if(in == *value) // check if same node exis
  {
    return 1;
  }
  // add to left branch
  if(in < *value)
  {
    if(!left)
    {
      left = new Node(in);
      return 0;
    }
    return left->add(in);
  }
  // add to right branch
  if(in > *value)
  {
    if(!right)
    {
      right = new Node(in);
      return 0;
    }
    return right->add(in);
  }
  return 1;
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
Node<V> * Node<V>::remove(V in, int * rm_flag)
{
  if(in == *value) // check if same node exis
  {
    if(right)
    {
      if(right->left)
      {
        Node<V> * tmp = right->removeMin();
        tmp->left = left;
        tmp->right = right;
        left = 0;
        right = 0;
        *rm_flag = 1;
        return tmp;
      }
      Node<V> * tmp = right;
      tmp->left = left;
      left = 0;
      right = 0;
      *rm_flag = 1;
      return tmp;
    }
    if(left)
    {
      return left;
      left = 0;
      right = 0;
      *rm_flag = 1;
    }
    *rm_flag = 1;
    return 0;
  }
    // remove from left branch
  if(in < *value)
  {
    if(left)
    {
      int * check = new int(0);
      Node<V> * tmp;
      tmp = left->remove(in, check);
      if(*check)
      {
        delete left;
        left = tmp;
      }
      delete check;
      return this;
    }
  }
    // remove from right branch
  if(in > *value)
  {
    if(right)
    {
      int * check = new int(0);
      Node<V> * tmp;
      tmp = right->remove(in, check);
      if(*check)
      {
        delete right;
        right = tmp;
      }
      delete check;
      return this;
    }
  }
  return this;
}

template <typename V>
int Node<V>::find(V * buf)
{
  if(*buf == *value)
  {
    buf = value;
    return 0;
  }
  // search in left branch
  if(*buf < *value)
  {
    if(!left)
    {
      return 1;
    }
    return left->find(buf);
  }
  // search in right branch
  if(*buf > *value)
  {
    if(!right)
    {
      return 1;
    }
    return right->find(buf);
  }
  return 1;
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
  cout << *value << endl;
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
int Node<V>::preOrder(int level)
{
  cout << *value << " ";
  int out = 1;
  if(left)
  {
    out += left->preOrder(level + 1);
  }
  if(right)
  {
    out += right->preOrder(level + 1);
  }
  return out;
}

template <typename V>
int Node<V>::inOrder(int level)
{
  int out = 1;
  if(left)
  {
    out += left->inOrder(level + 1);
  }
  cout << *value << " ";
  if(right)
  {
    out += right->inOrder(level + 1);
  }
  return out;
}

template <typename V>
int Node<V>::postOrder(int level)
{
  int out = 1;
  if(left)
  {
    out += left->postOrder(level + 1);
  }
  if(right)
  {
    out += right->postOrder(level + 1);
  }
  cout << *value << " ";
  return out;
}
