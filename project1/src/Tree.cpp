#include "Tree.h"

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
  if(root->add(in))
  {
    return 1;
  }
  root = root->balance();
  return 0;
}

template <typename V>
int AVLTree<V>::find(V * buf)
{
  if(root)
  {
    return root->find(buf);
  }
  return 1;
}

template <typename V>
int AVLTree<V>::remove(V in)
{
  if(!root)
  {
    return 1;
  }
  root = root->remove(in);
  root = root->balance();
  return 0;
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

template <typename V>
void AVLTree<V>::preOrder()
{
  if(root)
  {
    int nodes = root->preOrder(0);
    cout << "\n  Nodes: " << nodes << endl;
  }
  else
  {
    cout << "No tree\n";
  }
}

template <typename V>
void AVLTree<V>::inOrder()
{
  if(root)
  {
    int nodes = root->inOrder(0);
    cout << "\n  Nodes: " << nodes << endl;
  }
  else
  {
    cout << "No tree\n";
  }
}

template <typename V>
void AVLTree<V>::postOrder()
{
  if(root)
  {
    int nodes = root->postOrder(0);
    cout << "\n  Nodes: " << nodes << endl;
  }
  else
  {
    cout << "No tree\n";
  }
}
