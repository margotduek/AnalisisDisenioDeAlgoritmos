//
//  BTree.h
//  Arboles
//
//  Created by Krikor Bisdikian on 9/30/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#ifndef BTree_h
#define BTree_h

#include "BTNode.h"

template <class T, int orden>
class BTree {
    BTNode<T, orden> * _current;
    std::string rootName;
    
    std::string getNode(T target);
    
    bool searchTree(std::string currentId, T target);
    bool searchNode(const T & target, int & pos);
    
    bool pushDown(std::string currentId, const T & newEntry, T & median, std::string & rightBranch);
    void push(const T & entry, std::string rightBranch, int pos);
    void push(BTNode<T, orden> * &current, const T & entry, std::string rightBranch, int pos);
    void splitNode(std::string currentId, const T & extraEntry, std::string extraBranch, int pos, std::string & rightHalf, T & median);
    
    bool remove(std::string currentId, const T & target);
    void removeData(int pos);
    void copyInPredecessor(std::string currentId, int pos);
    void restore(std::string currentId, int pos);
    void moveLeft(std::string currentId, int pos);
    void moveRight(std::string currentId, int pos);
    void combine(int pos);
    
    void printAscending(std::string currentId);
    void printDescending(std::string currentId);
    
    void load(std::string nodeId);
    void load(BTNode<T, orden> * & current, std::string nodeId);
    
public:
    BTree();
    virtual ~BTree();
    
    bool search(T target);
    std::string getNode(std::string currentFile, T target);
    void insert(const T & newEntry);
    bool remove(const T & target);
    
    void load();
    
    void printAscending();
    void printDescending();
    
    bool isBTree(){
        return true;
    }
};

template <class T, int orden>
BTree<T, orden>::BTree(){
    _current = nullptr;
    rootName = "NaN";
}

template <class T, int orden>
BTree<T, orden>::~BTree(){
    if (_current){
        delete _current;
    }
}

template <class T, int orden>
bool BTree<T, orden>::search(T target){
    return searchTree(rootName, target);
}

template <class T, int orden>
bool BTree<T, orden>::searchTree(std::string currentId, T target){
    std::string outputFile;
    outputFile = getNode(target);
    if (outputFile != "NaN"){
        return true;
    }
    else{
        return false;
    }
}

template <class T, int orden>
std::string BTree<T, orden>::getNode(T target){
    return getNode(rootName, target);
}

template <class T, int orden>
std::string BTree<T, orden>::getNode(std::string currentId, T target){
    bool isPresent = false;
    int pos;
    
    while (currentId != "NaN"){
        load(currentId);
        isPresent = searchNode(target, pos);
        if (!isPresent){
            currentId = _current->getChildren(pos);
        }
        else{
            break;
        }
    }
    
    return currentId;
}

template <class T, int orden>
bool BTree<T, orden>::searchNode(const T & target, int & pos){
    pos = 0;
    while(pos < _current->getCount() && target > _current->getData(pos)){
        pos++;
    }
    
    bool found = pos < _current->getCount() && target == _current->getData(pos);
    return found;
}


template <class T, int orden>
void BTree<T, orden>::insert(const T & newEntry){
    T median;
    std::string rightBranch = "NaN";
    
    if(pushDown(rootName, newEntry, median, rightBranch)){
        
    }else{
        BTNode<T, orden> * newRoot = new BTNode<T, orden>();
        newRoot->setCount(1);
        newRoot->setData(0, median);
        newRoot->setChildren(0, rootName);
        newRoot->setChildren(1, rightBranch);
        this->rootName = newRoot->getFileName();
        delete newRoot;
    }
}

template <class T, int orden>
bool BTree<T, orden>::pushDown(std::string currentId, const T & newEntry, T & median, std::string & rightBranch)
{
    int pos;
    if (currentId == "NaN")
    {
        median = newEntry;
        rightBranch = "NaN";
        return false;
    }
    else
    {
        load(currentId);
        if (!searchNode(newEntry, pos) && newEntry != 0)
        {
            T extraEntry;
            std::string extraBranch = "NaN";
            
            if(pushDown(_current->getChildren(pos), newEntry, extraEntry, extraBranch)){
                load(currentId);
            }else {
                load(currentId);
                if (_current->getCount() < orden - 1)
                {
                    push(extraEntry, extraBranch, pos);
                }
                else{
                    splitNode(currentId, extraEntry, extraBranch, pos, rightBranch, median);
                    return false;
                }
            }
        }
    }
    return true;
}

template <class T, int orden>
void BTree<T, orden>::push(const T & entry,std::string rightBranch, int pos){
    push(_current, entry, rightBranch, pos);
}


template <class T, int orden>
void BTree<T, orden>::push(BTNode<T, orden> * & current, const T & entry, std::string rightBranch, int pos){
    for (int i = current->getCount(); i > pos; i--){
        current->setData(i, _current->getData(i - 1));
        current->setChildren(i + 1, _current->getChildren(i));
    }
    
    current->setData(pos, entry);
    current->setChildren(pos + 1, rightBranch);
    current->incrementCount();
}

template <class T, int orden>
void BTree<T, orden>::splitNode(std::string currentId, const T & extraEntry, std::string extraBranch,int pos,std::string & rightName, T & median){
    load(currentId);
    BTNode<T, orden> * rightHalf = new BTNode<T, orden>();
    rightName = rightHalf->getFileName();
    int mid = orden / 2;
    
    if (pos <= mid){
        for (int i = mid; i < orden -1; i++){
            rightHalf->setData(i - mid, _current->getData(i));
            rightHalf->setChildren(i - mid + 1, _current->getChildren(i+1));
        }
        _current->setCount(mid);
        rightHalf->setCount(orden - 1 - mid);
        push(extraEntry, extraBranch, pos);
    }
    else{
        mid++;
        for (int i = mid; i < orden -1; i++){
            rightHalf->setData(i - mid, _current->getData(i));
            rightHalf->setChildren(i - mid + 1, _current->getChildren(i+1));
        }
        _current->setCount(mid);
        rightHalf->setCount(orden - 1 - mid);
        push(rightHalf, extraEntry, extraBranch, pos - mid);
    }
    
    median = _current->getData(_current->getCount() - 1);
    rightHalf->setChildren(0, _current->getChildren(_current->getCount()));
    _current->decrementCount();
    
}

template <class T, int orden>
bool BTree<T, orden>::remove(const T & target){
    bool output = remove(rootName, target);
    
    load(rootName);
    if (_current && _current->getCount() == 0){
        std::string oldRoot = rootName;
        rootName = _current->getChildren(0);
        load();
        _current->setChildren(0, "NaN");
    }
    
    return output;
}

template <class T, int orden>
bool BTree<T, orden>::remove(std::string currentId, const T & target){
    load(currentId);
    int pos;
    bool result = false;
    
    if (_current == nullptr){
        return false;
    }
    else{
        if (searchNode(target, pos)){
            result = true;
            if (_current->getChildren(pos) != "NaN"){
                copyInPredecessor(currentId, pos);
                remove(_current->getChildren(pos), _current->getData(pos));
                load(currentId);
            }
            else{
                removeData(pos);
            }
        }
        else{
            result = remove(_current->getChildren(pos), target);
            load(currentId);
        }
        
        if (_current->getChildren(pos) != "NaN"){
            load(_current->getChildren(pos));
            if (_current->getCount() < (orden - 1)/2){
                restore(currentId, pos);
            }
            load(currentId);
        }
    }
    
    return result;
}


template <class T, int orden>
void BTree<T, orden>::removeData(int pos){
    for (int i = pos; i < _current->getCount() - 1; i++){
        _current->setData(i, _current->getData(i + 1));
    }
    _current->decrementCount();
}


template <class T, int orden>
void BTree<T, orden>::copyInPredecessor(std::string currentId,int pos){
    load(_current->getChildren(pos));
    
    while (_current->getChildren(_current->getCount()) != "NaN"){
        load(_current->getChildren(_current->getCount()));
    }
    
    T data = _current->getData(_current->getCount() - 1);
    
    load(currentId);
    _current->setData(pos, data);
}


template <class T, int orden>
void BTree<T, orden>::restore(std::string currentId,int pos){
    load(currentId);
    load(_current->getChildren(1));
    int count = _current->getCount();
    load(currentId);
    
    if (pos == 0){
        if (count > (orden - 1) / 2)
            moveLeft(currentId, 1);
        else
            combine(1);
    }
    else if (pos == count){
        load(_current->getChildren(pos - 1));
        count = _current->getCount();
        load(currentId);
        if (count > (orden - 1) / 2)
            moveRight(currentId, pos - 1);
        else
            combine(pos);
    }
    else{
        load(_current->getChildren(pos - 1));
        count = _current->getCount();
        load(currentId);
        
        if (count > (orden - 1) / 2)
            return moveRight(currentId, pos - 1);
        
        load(_current->getChildren(pos + 1));
        count = _current->getCount();
        load(currentId);
        
        if (count > (orden - 1) / 2)
            moveLeft(currentId, pos + 1);
        else
            combine(pos);
    }
}

template <class T, int orden>
void BTree<T, orden>::moveLeft(std::string currentId, int pos){
    load(currentId);
    std::string leftBranch = _current->getChildren(pos - 1);
    std::string rightBranch = _current->getChildren(pos);
    T lastItem = _current->getData(pos - 1);
    
    load(leftBranch);
    _current->setData(_current->getCount(), lastItem);
    _current->incrementCount();
    int leftCount = _current->getCount();
    
    load(rightBranch);
    std::string rightFirstChild = _current->getChildren(0);
    T rightFirstData = _current->getData(0);
    _current->decrementCount();
    
    load(currentId);
    _current->setChildren(leftCount, rightFirstChild);
    _current->setData(pos - 1, rightFirstData);
    
    
    load(rightBranch);
    for (int i = 0; i < _current->getCount(); i++){
        _current->setData(i, _current->getData(i + 1));
        _current->setChildren(i, _current->getChildren(i + 1));
    }
    
    _current->setChildren(_current->getCount(),_current->getChildren(_current->getCount() + 1));
}

template <class T, int orden>
void BTree<T, orden>::moveRight(std::string currentId, int pos){
    load(currentId);
    BTNode<T, orden> * leftBranch = new BTNode<T, orden>();
    BTNode<T, orden> * rightBranch = new BTNode<T, orden>();
    
    load(leftBranch, _current->getChildren(pos));
    load(leftBranch, _current->getChildren(pos + 1));
    
    rightBranch->setChildren(rightBranch->getCount() + 1, rightBranch->getChildren(rightBranch->getCount()));
    
    for (int i = rightBranch->getCount(); i > 0 ; i--){
        rightBranch->setData(i, rightBranch->getData(i - 1));
        rightBranch->setChildren(i, rightBranch->getChildren(i - 1));
    }
    
    rightBranch->incrementCount();
    rightBranch->setData(0, _current->getData(pos));
    
    rightBranch->setChildren(0, leftBranch->getChildren(leftBranch->getCount()));
    leftBranch->decrementCount();
    
    _current->setData(pos, leftBranch->getData(leftBranch->getCount()));
}

template <class T, int orden>
void BTree<T, orden>::combine(int pos){
    BTNode<T, orden> * leftBranch;
    BTNode<T, orden> * rightBranch;
    
    load(leftBranch, _current->getChildren(pos - 1));
    load(rightBranch, _current->getChildren(pos));
    
    leftBranch->setData(leftBranch->getCount(), _current->getData(pos - 1));
    leftBranch->incrementCount();
    leftBranch->setChildren(leftBranch->getCount(), rightBranch->getChildren(0));
    
    for (int i = 0; i < rightBranch->getCount(); i++){
        leftBranch->setData(leftBranch->getCount(), rightBranch->getData(i));
        leftBranch->incrementCount();
        leftBranch->setChildren(leftBranch->getCount(), rightBranch->getChildren(i + 1));
    }
    
    _current->decrementCount();
    
    for (int i = pos - 1; i < _current->getCount(); i++){
        _current->setData(i, _current->getData(i + 1));
        _current->setChildren(i + 1, _current->getChildren(i +  2));
    }
    
    delete rightBranch;
    delete leftBranch;
}

template <class T, int orden>
void BTree<T, orden>::load(){
    return load(this->rootName);
}

template <class T, int orden>
void BTree<T, orden>::load(BTNode<T, orden> * &node,std::string fileName)
{
    if (fileName == "NaN"){
        node = nullptr;
        return;
    }
    
    std::ifstream currentFile(fileName);
    int count;
    T data[orden - 1];
    std::string children[orden];
    
    currentFile >> count;
    
    for (int i = 0; i < orden - 1; i++)
        currentFile >> data[i];
    
    for (int i = 0; i < orden; i++)
        currentFile >> children[i];
    
    currentFile.close();
    
    node = new BTNode<T, orden>(count, data, children, fileName);
}

template <class T, int orden>
void BTree<T, orden>::load(std::string fileName){
    load(_current, fileName);
}

template <class T, int orden>
void BTree<T, orden>::printAscending(){
    printAscending(rootName);
    std::cout << std::endl;
}

template <class T, int orden>
void BTree<T, orden>::printDescending(){
    printDescending(rootName);
    std::cout << std::endl;
}

template <class T, int orden>
void BTree<T, orden>::printAscending(std::string currentId){
    BTNode<T, orden> * temp;
    load(temp, currentId);
    
    if (temp){
        for (int i = 0; i < orden - 1; i++){
            printAscending(temp->getChildren(i));
            if (i < temp->getCount())
                std::cout << temp->getData(i) << " ";
        }
    }
    delete temp;
}

template <class T, int orden>
void BTree<T, orden>::printDescending(std::string currentId){
    
    BTNode<T, orden> * temp;
    load(temp, currentId);
    
    if (temp){
        for (int i = orden - 1; i >= 0; i--){
            printDescending(temp->getChildren(i));
            if (i < temp->getCount())
                std::cout << temp->getData(i) << " ";
        }
    }
    delete temp;
}



#endif /* BTree_h */
