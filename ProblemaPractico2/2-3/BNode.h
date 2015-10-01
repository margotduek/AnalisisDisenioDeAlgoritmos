#define BinaryTree_BNode_h

#include <iostream>


template <class T, int R>
class BNode {
  private:
    int count;
    T data [R - 1];
    BNode<T,R> * children[R];

    int key;
    unsigned char height;

    T info;

public:

  BNode();
  virtual ~BNode();

  int getCount(){return count;};
  T & getData(const int position);
  BNode<T,R> * getChildren(const int position);

  void setCount(const int count){ this->count = count; };
  void setData(const int position, T record);
  void setChildren(const int position, BNode<T,R> * node);

  void incrementCount() {count ++;}
  void decrementCount() {count --;}

  /* Constructores *
  BNode() { }
  BNode(int k) { key = k; left = right = 0; height = 1;}
  /*BNode(const T & _info) : info (_info) { }
  BNode(const BNode<T> & );

  /* Destructor *
  virtual ~BNode();

  T getInfo() const { return info; }
  void setInfo(const T & value) { info = value; }

  BNode<T> * getLeft() const { return left; }
  void setLeft(BNode<T> * value) { left = value; }

  BNode<T> * getRight() const { return right; }
  void setRight(BNode<T> * value) { right = value; }

  BNode<T> * getParent() const { return parent; }
  void setParent(BNode<T> * value) { parent = value; }
  */

  template <typename Tn, int n>
  friend std::ostream & operator << (std::ostream & os, const BNode<Tn, n>  & node);
};

template <class T, int R>
BNode<T, R>::~BNode(){
  for(int i = 0; i < R ; ++i){
    if(children[i]){
      delete children[i];
    }
  }
}


template <class T, int R>
BNode<T, R>::BNode(){
  this->count = 0;
  for (int i = 0; i < R; i++){
    children[i] = nullptr;
  }
}

template <class T, int R>
BNode<T, R> * BNode<T, R>::getChildren(const int position){
  if (position < R  && position >= 0)
    return this->children[position];
}

template <class T, int R>
T & BNode<T, R>::getData(const int position){
  if (position < R - 1 && position >= 0)
    return this->data[position];
}

template <class T, int R>
void BNode<T, R>::setData(const int position, T record){
  if (position < R - 1 && position >= 0)
    this->data[position] = record;
}

template <class T, int R>
void BNode<T, R>::setChildren(const int position, BNode<T, R> * node){
  if (position < R && position >= 0)
    this->children[position] = node;
}



template <class T, int R>
std::ostream & operator << (std::ostream & os, const BNode<T,R>  & node){
  for (int i = 0; i < R - 1; i++){
    if (i < node.getCount())
      os << node.getData(i) << " ";
    }
  return os;
}
