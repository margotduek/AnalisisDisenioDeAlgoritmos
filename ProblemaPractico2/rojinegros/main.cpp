#include <iostream>
#include "Rojinegro.h"
#include <iomanip>
void inorder_r(struct node *root);
void prettyPrint(node* p, int indent);



int main(){

  //node *root = make_node(9);
  //root->red = 0;
  //node *nodo;
  //tree *arbol;

  tree *arbol;

  //std::cout << nodo->red << std::endl;

  insert(arbol, 3);
  for(int i = 0; i< 10; i++){
    int h = rand() % 30;
    //insert(arbol, h);
  }


//inorder_r(root);(
//prettyPrint(root,0);

  //std::cout << nodo->red << std::endl;

  return 0;
}
void inorder_r(struct node *root){
  if (root != NULL){
    inorder_r(root->link[0]);
    printf("%d\n", root->data);
    inorder_r(root->link[1]);
  }
}


void prettyPrint(node* p, int indent){
    if (p != nullptr)
    {
          if (p->link[1]) {
              prettyPrint(p->link[1], indent + 4);
          }
          if (indent) {
              std::cout << std::setw(indent) << ' ';
          }
          if (p->link[1]) std::cout << " /\n" << std::setw(indent) << ' ';
          std::cout << p->data << "|" << p->red << "\n ";
          if (p->link[0]) {
              std::cout << std::setw(indent) << ' ' << " \\\n";
              prettyPrint(p->link[0], indent + 4);
          }
        }
}
