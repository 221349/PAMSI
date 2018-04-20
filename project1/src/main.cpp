#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.cpp"

using namespace std;

void add(AVLTree <int> * a);
void remove(AVLTree <int> * a);
void addRandom(AVLTree <int> * a);
void removeRandom(AVLTree <int> * a);
void find(AVLTree <int> * a);
void help();


int main(int argc, char *argv[]){
  AVLTree <int> a;
  srand (time(NULL));
  int c = -1;
  while(c != 0)
  {
    if(c == 1)
    {
      add(&a);
    }
    if(c == 2)
    {
      remove(&a);
    }
    if(c == 3)
    {
      addRandom(&a);
    }
    if(c == 4)
    {
      removeRandom(&a);
    }
    if(c == 5)
    {
      find(&a);
    }
    if(c == 6)
    {
      a.display();
    }
    if(c == 7)
    {
      a.preOrder();
    }
    if(c == 8)
    {
      a.inOrder();
    }
    if(c == 9)
    {
      a.postOrder();
    }
    if(c == -1)
    {
      help();
    }
    cout << "\n> ";
    cin >> c;
  }
  return 0;
}


void add(AVLTree <int> * a)
{
  int tmp = 0;
  cout << "Add value: ";
  cin >> tmp;
  if(!a->add(tmp))
  {
    cout << "Done.\n";
  }
  else
  {
    cout << "Error. Node exist.\n";
  }
}
void remove(AVLTree <int> * a)
{
  int tmp = 0;
  cout << "Remove value: ";
  cin >> tmp;
  if(!a->remove(tmp))
  {
    cout << "Done.\n";
  }
  else
  {
    cout << "Error. Not found.\n";
  }
}
void addRandom(AVLTree <int> * a)
{
  int n = 0;
  cout << "Add random values.\nSet level: ";
  cin >> n;
  int buf = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp = 1;
    for(int j = 0; j < i; j++)
    {
      tmp *=2;
    }
    buf += tmp;
  }

  for (int i = 0; i < buf*10 ; i++)
  {
    int tmp = 0;
    if((rand() % 2) == 1)
    {
      tmp = rand() % (buf+1)/2;
    }
    else
    {
      tmp = -rand() % (buf+1)/2;
    }
    a->add(tmp);
  }
}
void removeRandom(AVLTree <int> * a)
{
  int n = 0;
  cout << "Remove random values.\nSet level: ";
  cin >> n;
  int buf = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp = 1;
    for(int j = 0; j < i; j++)
    {
      tmp *=2;
    }
    buf += tmp;
  }

  for (int i = 0; i < buf / 3; i++)
  {
    int tmp = 0;
    if((rand() % 2) == 1)
    {
      tmp = rand() % (buf+1)/2;
    }
    else
    {
      tmp = -rand() % (buf+1)/2;
    }
    a->remove(tmp);
  }
}
void find(AVLTree <int> * a)
{
  int * tmp = new int(0);
  cout << "Find value: ";
  cin >> *tmp;
  if(!a->find(tmp))
  {
    cout << "Found: " << *tmp << endl;
  }
  else
  {
    cout << "Not found: " << *tmp << endl;
  }
}

void help()
{
  cout << "1 - add single value\n"
  << "2 - remove single value\n"
  << "3 - add some random values\n"
  << "4 - remove some random values\n"
  << "5 - find\n"
  << "6 - display\n"
  << "7 - Pre-Order\n"
  << "8 - In-Order\n"
  << "9 - Post-Order\n"
  << "-1 - display this help\n"
  << "0 - exit.\n";
}
