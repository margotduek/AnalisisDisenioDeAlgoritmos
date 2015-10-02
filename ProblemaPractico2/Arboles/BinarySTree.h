//
//  BinarySTree.h
//  BinaryTree
//
//  Created by Krikor Bisdikian G. on 5/9/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#ifndef BinarySTree_h
#define BinarySTree_h

#include "BinaryTree.h"

template <class T>
class BinarySTree: public BinaryTree<T> {
    
    
public:
    BinarySTree();
    ~BinarySTree();
    
    BNode<T> * search(const T value) const;
    BNode<T> * search(const T value, BNode<T> * node) const;
};

template <class T>
BinarySTree<T>::BinarySTree() : BinaryTree<T>(){}

template <class T>
BinarySTree<T>::~BinarySTree()
{
    
}

template <class T>
BNode<T> * BinarySTree<T>::search(const T value) const{
    return search(value, this->root);

}

template <class T>
BNode<T> * BinarySTree<T>::search(const T value, BNode<T> * node)const {
    if (node == nullptr)
    {
        return nullptr;
    }
    else {
        T value2 = node->getInfo();
        if (value == value2)
        {
            return node;
        }
        else if (value < value2)
        {
            return search(value, node->getLeft());
        }
        else {
            return search(value, node->getRight());
        }
    }
}





#endif /* BinarySTree_h */
