//
//  BTree.h
//  Arboles
//
//  Created by Krikor Bisdikian on 9/30/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#ifndef BTree_h
#define BTree_h

#include <iostream>
#include "BNode.h"

template <class T, int orden>
class BTree {
  private:
    BNode<T, orden> * root;
    BNode<T, orden> * getNode(T & target);

    bool searchTree(BNode<T,orden> * current, T target);
    bool searchNode(BNode<T,orden> * current, const T & target, int & pos);

    bool pushDown(BNode<T,orden> * current, const T & newEntry, T & median, BNode<T,orden> & rightBranch);
    void push(BNode<T,orden> * current, const T & entry, BNode<T,orden> * rightBranch, int pos);
    void splitNode(BNode<T,orden> * current, const T & extraEntry, BNode<T,orden> * extraBranch, int pos, BNode<T,orden> * &rightHalf, T & median);

    bool remove(BNode<T,orden> * current, const T & target);
    void removeData(BNode<T,orden> * current, int pos);
    void copyInPredecessor(BNode<T,orden> * current, int pos);
    void restore(BNode<T,orden> * current, int pos);
    void moveLeft(BNode<T,orden> * current, int pos);
    void moveRight(BNode<T,orden> * current, int pos);
    void combine(BNode<T,orden> * current, int pos);

    void printAscending(BNode<T,orden> * current);
    void printDescending(BNode<T,orden> * current);

public:
    BTree();
    virtual ~BTree();

    bool search(T target);
    BNode<T,orden> * getNode(BNode<T,orden> * current, T target);
    void insert(const T & newEntry);
    bool remove(const T & target);

    void printAscending();
    void printDescending();

    bool isBTree(){
        return true;
    }
};

template <class T, int orden>
BTree<T, orden>::BTree(){
  this->root = new BNode<T, orden>();
}

template <class T, int orden>
BTree<T, orden>::~BTree(){
    if (root){
        delete root;
    }
}

template <class T, int orden>
bool BTree<T, orden>::search(T target){
    return searchTree(root, target);
}

template <class T, int orden>
bool BTree<T, orden>::searchTree(BNode<T,orden> * current, T target){
  BNode<T,orden> * output;
    output = getNode(target);
    if (output){
        return true;
    }
    else{
        return false;
    }
}

template <class T, int orden>
BNode<T, orden> * BTree<T, orden>::getNode(T & target)
{
  return getNode(root, target);
}



template <class T, int orden>
BNode<T,orden> * BTree<T, orden>::getNode(BNode<T,orden> * current, T target){
    bool isPresent = false;
    int pos;

    while (current){
        isPresent = searchNode(current, target, pos);
        if (!isPresent){
            current = current->getChildren(pos);
        }
        else{
            break;
        }
    }

    return current;
}




template <class T, int orden>
bool BTree<T, orden>::searchNode(BNode<T,orden> * current, const T & target, int & pos){
    pos = 0;
    while(pos < current->getCount() && target > current->getData(pos)){
        pos++;
    }

    bool found = pos < current->getCount() && target == current->getData(pos);
    return found;
}



template <class T, int orden>
void BTree<T, orden>::insert(const T & newEntry){
    T median;
    BNode<T,orden> * rightBranch = nullptr;

    if(pushDown(root, newEntry, median, rightBranch)){

    }else{
        BNode<T, orden> * newRoot = new BNode<T, orden>();
        newRoot->setCount(1);
        newRoot->setData(0, median);
        newRoot->setChildren(0, root);
        newRoot->setChildren(1, rightBranch);
        this->root = newRoot;
    }
}

template <class T, int orden>
bool BTree<T, orden>::pushDown(BNode<T,orden> * current, const T & newEntry, T & median, BNode<T,orden> & rightBranch){
    int pos;
    if (current == nullptr){
        median = newEntry;
        rightBranch = nullptr;
        return false;
    }
    else{
        if (!searchNode(current, newEntry, pos)){
            T extraEntry;
            BNode<T,orden> * extraBranch = nullptr;

            if(pushDown(current->getChildren(pos), newEntry, extraEntry, extraBranch)){
               std::cout << "done" << std::endl;
            }else {
                if (current->getCount() < orden - 1){
                    push(current, extraEntry, extraBranch, pos);
                }
                else{
                    splitNode(current, extraEntry, extraBranch, pos, rightBranch, median);
                    return false;
                }
            }
        }
    }
    return true;
}



template <class T, int orden>
void BTree<T, orden>::push(BNode<T,orden> * current, const T & entry, BNode<T,orden> * rightBranch, int pos){
    for (int i = current->getCount(); i > pos; i--){
        current->setData(i, current->getData(i - 1));
        current->setChildren(i + 1, current->getChildren(i));
    }

    current->setData(pos, entry);
    current->setChildren(pos + 1, rightBranch);
    current->incrementCount();
}




template <class T, int orden>
void BTree<T, orden>::splitNode(BNode<T,orden> * current, const T & extraEntry, BNode<T,orden> * extraBranch,int pos,BNode<T,orden> * &rightHalf, T & median){
    rightHalf = new BNode<T,orden>();
    int mid = orden / 2;

    if (pos <= mid){
        for (int i = mid; i < orden -1; i++){
            rightHalf->setData(i - mid, current->getData(i));
            rightHalf->setChildren(i - mid + 1, current->getChildren(i+1));
        }
        current->setCount(mid);
        rightHalf->setCount(orden - 1 - mid);
        push(extraEntry, extraEntry, extraBranch, pos);
    }
    else{
        mid++;
        for (int i = mid; i < orden -1; i++){
            rightHalf->setData(i - mid, current->getData(i));
            rightHalf->setChildren(i - mid + 1, current->getChildren(i+1));
        }
        current->setCount(mid);
        rightHalf->setCount(orden - 1 - mid);
        push(rightHalf, extraEntry, extraBranch, pos - mid);
    }

    median = current->getData(current->getCount() - 1);
    rightHalf->setChildren(0, current->getChildren(current->getCount()));
    current->decrementCount();
}



template <class T, int orden>
bool BTree<T, orden>::remove(const T & target){
    bool output = remove(root, target);

    if (root && root->getCount() == 0){
        BNode<T,orden> * oldRoot = root;
        root = root->getChildren(0);
        oldRoot->setChildren(0, nullptr);
    }
    return output;
}



template <class T, int orden>
bool BTree<T, orden>::remove(BNode<T,orden> * current, const T & target){
    int pos;
    bool result = false;

    if (current == nullptr){
        return false;
    }
    else{
        if (searchNode(current, target, pos)){
            result = true;
            if (current->getChildren(pos)){
                copyInPredecessor(current, pos);
                remove(current->getChildren(pos), current->getData(pos));
            }
            else{
                removeData(current, pos);
            }
        }
        else{
            result = remove(current->getChildren(pos), target);
        }

        if (current->getChildren(pos)){
            if (current->getChildren(pos)->getCount() < (orden - 1)/2){
                restore(current, pos);
            }
        }
    }

    return result;
}


template <class T, int orden>
void BTree<T, orden>::removeData(BNode<T,orden> * current, int pos){
    for (int i = pos; i < current->getCount() - 1; i++){
        current->setData(i, current->getData(i + 1));
    }
    current->decrementCount();
}


template <class T, int orden>
void BTree<T, orden>::copyInPredecessor(BNode<T,orden> * current,int pos){
    BNode<T,orden> * leaf = current->getChildren(pos);

    while (leaf->getChildren(leaf->getCount())){
      leaf = leaf->getChildren(leaf->getCount());
    }

    current->setData(pos, leaf->getData(leaf->getCount() - 1));
}


template <class T, int orden>
void BTree<T, orden>::restore( BNode<T,orden> * current,int pos){
    if (pos == 0){
        if (current->getChildren(1)->getCount() > (orden - 1) / 2)
            moveLeft(current, 1);
        else
            combine(current, 1);
    }
    else if (pos == current->getCount()){
        if (current->getChildren(pos - 1)->getCount() > (orden - 1) / 2)
            moveRight(current, pos - 1);
        else
            combine(current, pos);
    }
    else{
        if (current->getChildren(pos - 1)->getCount() > (orden - 1) / 2)
             moveRight(current, pos - 1);
        else if (current->getChildren(pos + 1)->getCount() > (orden - 1) / 2)
            moveLeft(current, pos + 1);
        else
            combine(current, pos);
    }
}

template <class T, int orden>
void BTree<T, orden>::moveLeft( BNode<T,orden> * current, int pos){
    load(current);
    BNode<T,orden> * leftBranch = current->getChildren(pos - 1);
    BNode<T,orden> * rightBranch = current->getChildren(pos);

    leftBranch->setData(leftBranch->getCount(), current->getData(pos - 1));
    leftBranch->incrementCount();
    leftBranch->setChildren(leftBranch->getCount(), rightBranch->getChildren(0));

    current->setData(pos - 1, rightBranch->getData(0));
    rightBranch->decrementCount();

    // move entries to fill hole
    for (int i = 0; i < rightBranch->getCount(); i++){
      rightBranch->setData(i, rightBranch->getData(i + 1));
      rightBranch->setChildren(i, rightBranch->getChildren(i + 1));
    }

    rightBranch->setChildren(rightBranch->getCount(),
       rightBranch->getChildren(rightBranch->getCount() + 1));
}




template <class T, int orden>
void BTree<T, orden>::moveRight(BNode<T, orden> * current, int pos){
    BNode<T, orden> * leftBranch = new BNode<T, orden>();
    BNode<T, orden> * rightBranch = new BNode<T, orden>();

    rightBranch->setChildren(rightBranch->getCount() + 1,
        rightBranch->getChildren(rightBranch->getCount()));

    // move entries to fill hole
    for (int i = rightBranch->getCount(); i > 0 ; i--)
    {
      rightBranch->setData(i, rightBranch->getData(i - 1));
      rightBranch->setChildren(i, rightBranch->getChildren(i - 1));
    }

    rightBranch->incrementCount();
    rightBranch->setData(0, current->getData(pos));

    rightBranch->setChildren(0, leftBranch->getChildren(leftBranch->getCount()));
    leftBranch->decrementCount();

    current->setData(pos, leftBranch->getData(leftBranch->getCount()));
}


template <class T, int orden>
void BTree<T, orden>::combine(BNode<T, orden> * current, int pos){
    BNode<T, orden> * leftBranch = current->getChildren(pos - 1);
    BNode<T, orden> * rightBranch = current->getChildren(pos);

    leftBranch->setData(leftBranch->getCount(), current->getData(pos - 1));
    leftBranch->incrementCount();
    leftBranch->setChildren(leftBranch->getCount(), rightBranch->getChildren(0));

    for (int i = 0; i < rightBranch->getCount(); i++){
      leftBranch->setData(leftBranch->getCount(), rightBranch->getData(i));
      leftBranch->incrementCount();
      leftBranch->setChildren(leftBranch->getCount(), rightBranch->getChildren(i + 1));
    }

    current->decrementCount();

    for (int i = pos - 1; i < current->getCount(); i++){
      current->setData(i, current->getData(i + 1));
      current->setChildren(i + 1, current->getChildren(i +  2));
    }
}


template <class T, int orden>
void BTree<T, orden>::printAscending(){
    printAscending(root);
    std::cout << std::endl;
}

template <class T, int orden>
void BTree<T, orden>::printDescending(){
    printDescending(root);
    std::cout << std::endl;
}



template <class T, int orden>
void BTree<T, orden>::printAscending(BNode<T, orden> * current){
    if (current){
        for (int i = 0; i < orden - 1; i++){
            printAscending(current->getChildren(i));
            if (i < current->getCount())
                std::cout << current->getData(i) << " ";
        }
        printAscending(current->getChildren(orden - 1));
    }
}


template <class T, int orden>
void BTree<T, orden>::printDescending(BNode<T, orden> * current){
    if (current){
        printDescending(current->getChildren(orden - 1));
        for (int i = orden - 2; i >= 0; i--){
          if (i < current->getCount())
            std::cout << current->getData(i) << " ";
          printDescending(current->getChildren(i));
        }
    }
}

#endif /* BTree_h */
