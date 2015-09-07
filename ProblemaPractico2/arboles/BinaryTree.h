#define BinaryTree_BinaryTree_h
#include "BNode.h"


template <class T>
class BinaryTree{
  private:
    BNode<T> * root = nullptr;

  public:
    BinaryTree() {}
    virtual ~BinaryTree();

    bool empty();

    void clear();
    void clear(BNode<T> * node);

    BNode<T> * getRoot() const;
    void setRoot(BNode<T> * node);

    bool insert(BNode<T> * parent, T value);
    bool insert(BNode<T> * parent, BNode<T> * value);

    void preOrder() const;
    void preOrder(BNode<T> * node) const;

    void inOrder() const;
    void inOrder(BNode<T> * node) const;

    void postOrder() const;
    void postOrder(BNode<T> * node) const;

    void isLeaf() const;
    void isLeaf(BNode<T> * node) const;

    void ancestors(BNode<T> * node) const;

    /**/
    unsigned char height(BNode<T> * p);
    int bfactor(BNode<T> * p);
    void fixheight(BNode<T> * p);
    BNode<T>* rotateright(BNode<T>* p);
};

/*Es para la altura*/
template <class T>
unsigned char BinaryTree<T>::height(BNode<T> * p){
  return p ? p->height : 0;
}

/*Calcula el factor de balance*/
template <class T>
int BinaryTree<T>::bfactor(BNode<T> * p){
    return height(p->right) - height(p->left);
}

/*Calcula la altura real de un nodo dado*/
template <class T>
void BinaryTree<T>::fixheight(BNode<T> * p){
  unsigned char hl = height(p->left);
  unsigned char hr = height(p->right);
  p->height = (hl>hr ? hl : hr) + 1;
}

/*Rotacion a la derecha*/
template <class T>
BNode<T>* BinaryTree<T>::rotateright(BNode<T>* p){ // the right rotation round p
  BNode<T>* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

/*Rotacion a la izquierda*/
template <class T>
BNode<T>* BinaryTree<T>::rotateleft(BNode<T>* q){ // the left rotation round q
  BNode<T>* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}


template <class T>
BinaryTree<T>::~BinaryTree(){
  clear();
}

template <class T>
bool BinaryTree<T>::empty(){
  return root == nullptr;
}

template <class T>
void BinaryTree<T>::clear(){
  clear(root);
}

template <class T>
void BinaryTree<T>::clear(BNode<T> * node){
  if (node) {
    clear(node->getLeft());
    clear(node->getRight());

    delete node;
  }
}

template <class T>
BNode<T> * BinaryTree<T>::getRoot() const{
  return root;
}

template <class T>
void BinaryTree<T>::setRoot(BNode<T> * node){
  if (!empty()) {
    node->setLeft(root);
    root->setParent(node);
    root = node;
  }
  else {
    root = node;
  }
}

template <class T>
bool BinaryTree<T>::insert(BNode<T> * parent, T value){
  BNode<T> * node = new BNode<T>(value);
  bool inserted = insert(parent, node);

  if (!inserted) delete node;

  return inserted;
}

template <class T>
bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value){
  bool inserted = false;

  if (empty() || !parent) {
    setRoot(value);
    inserted = true;
  }
  else {
    if (!parent->getLeft()) {
        parent->setLeft(value);
        value->setParent(parent);
        inserted = true;
    }
    else if (!parent->getRight()) {
      parent->setRight(value);
      value->setParent(parent);
      inserted = true;
    }
  }

  return inserted;
}

template <class T>
void BinaryTree<T>::preOrder() const{
  preOrder(root);
}

template <class T>
void BinaryTree<T>::preOrder(BNode<T> * node) const{
  if (node) {
    /* Procesar el nodo */
    std::cout << *node << std::endl;

    /* Invocar a los hijos */
    preOrder(node->getLeft());
    preOrder(node->getRight());

  }
}

template <class T>
void BinaryTree<T>::inOrder() const{
  inOrder(root);
}

template <class T>
void BinaryTree<T>::inOrder(BNode<T> * node) const{
  if (node) {

    /* Invocar al hijo izquierdo */
    inOrder(node->getLeft());

    /* Procesar el nodo */
    std::cout << *node << std::endl;

    /* Invocar al hijo derecho */
    inOrder(node->getRight());
  }
}

template <class T>
void BinaryTree<T>::postOrder() const{
    postOrder(root);
}

template <class T>
void BinaryTree<T>::postOrder(BNode<T> * node) const{
  if (node) {
    /* Invocar a los hijos */
    postOrder(node->getLeft());
    postOrder(node->getRight());

    /* Procesar el nodo */
    std::cout << *node << std::endl;
  }
}

template <class T>
void BinaryTree<T>::isLeaf() const{
  isLeaf(root);
}

template <class T>
void BinaryTree<T>::isLeaf(BNode<T> * node) const{
  if (node) {
    if (!node->getLeft() && !node->getRight()) {
      std::cout << *node << std::endl;
    }
    else {
      isLeaf(node->getLeft());
      isLeaf(node->getRight());
    }
  }
}

template <class T>
void BinaryTree<T>::ancestors(BNode<T> * node) const{
  if (node) {
    std::cout << *node << " -> ";
    ancestors(node->getParent());
  }
}




/*
Bibliografía
  - http://kukuruku.co/hub/cpp/avl-trees
*/
