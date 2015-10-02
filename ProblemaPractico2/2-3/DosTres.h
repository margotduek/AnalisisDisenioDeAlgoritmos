#include <iostream>
#include "BTree.h"

template <class T>
class DosTres{
private:
  BTree<T, 3> * tree;

public:
  DosTres();
  ~DosTres();

  void insert(const T & newEntry);
  bool remove(const T & target);
  bool search(const T & target);

  void printAscending();
  void printDescending();

  bool isTwoThreeTree(){return true;};
};

template <class T>
DosTres<T>::DosTres()
{
  tree = new BTree<T, 3>();
}

template <class T>
DosTres<T>::~DosTres()
{
  if (tree)
    delete tree;
}

template <class T>
void DosTres<T>::insert(const T & newEntry)
{
  tree->insert(newEntry);
}

template <class T>
bool DosTres<T>::remove(const T & target)
{
  return tree->remove(target);
}

template <class T>
bool DosTres<T>::search(const T & target)
{
  return tree->search(target);
}

template <class T>
void DosTres<T>::printAscending()
{
  tree->printAscending();
}

template <class T>
void DosTres<T>::printDescending()
{
  tree->printDescending();
}
