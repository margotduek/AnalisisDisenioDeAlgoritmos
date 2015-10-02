#include <iostream>
#include "DosTres.h"

// This function tests the example at Kruse's textbook.
// Makes a BTree of order 5 representation of the English alphabet.
int main(int argc, const char * argv[]){
  DosTres<int> * tree = new DosTres<int>();

  tree->insert(1);
  tree->insert(5);
  tree->insert(6);
  tree->insert(8);
  tree->insert(11);
  tree->insert(51);
  tree->insert(61);
  tree->insert(81);

  tree->printAscending();
  tree->printDescending();



  return 0;
  delete tree;

  return 0;
}
