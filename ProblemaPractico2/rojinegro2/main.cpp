#include <iostream>
#include "Rojinegro.h"

// This function tests the example at Kruse's textbook.
// Makes a BTree of order 5 representation of the English alphabet.
int main(int argc, const char * argv[]){
  Rojinegro<int> * tree = new Rojinegro<int>();

  tree->RBinsert(1);
  tree->RBinsert(5);
  tree->RBinsert(6);
  tree->RBinsert(8);
  tree->RBinsert(11);
  tree->RBinsert(51);
  tree->RBinsert(61);
  tree->RBinsert(81);

  tree->prettyPrint(tree->getRaiz(), 0);



  return 0;
  delete tree;

  return 0;
}
