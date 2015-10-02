
#include "DTNode.h"
#include <iomanip>
#include <queue>
#include <iostream>
#include <vector>
template <class T>
class DosTres {

protected:
    DTNode<T> * root = nullptr;
    std::vector<T> leafLevels;

public:
    DosTres() {}
    ~DosTres();

    bool empty();

    void clear();
    void clear(DTNode<T> * node);

    DTNode<T> * getRoot() const;
    void setRoot(const T element);
    void setRoot(DTNode<T> * node);
    bool isRoot(DTNode<T> * node);

    void insert23(T item);
    void insert23(DTNode<T> * item);
    void insert23(DTNode<T> * parent, DTNode<T> * item);
    void insert23(DTNode<T> * parent, T item);

    void printAsc(DTNode<T> * node, int level);
    void printAsc();

    void printDesc(DTNode<T> * node, int level);
    void printDesc();

    void forceRoot(DTNode<T>* root);
    bool isTT ();

    void redistributeChildren(DTNode<T>* container, DTNode<T>* n1, DTNode<T>* n2);
    void split(DTNode<T>* container);
    bool is2Node(DTNode<T>* node);
    bool is3Node(DTNode<T>* node);
    bool hasFreeChildren(DTNode<T>* node);
    bool isTT(DTNode<T>* node);
    DTNode<T>* searchForNode(const T item, DTNode<T> * node);

    DTNode<T>* findNodeToDelete(DTNode<T>*, T value);
    bool deleteNode(DTNode<T>* node);
    bool deleteNode(T value);
    void fixTree(DTNode<T>* node);
    DTNode<T>* getInorderSuccesor(DTNode<T>* node);

    void getLeafLevels(DTNode<T>* node);
    bool getNodeKeys(DTNode<T>* node);
    bool getNodeChildren(DTNode<T>* node);
    bool findNode(DTNode<T>*, T value);

    void isLeaf() ;
    bool isLeaf(DTNode<T> * node) ;

    void ancestors(DTNode<T> * node) const;

    int getHeight() const;
    int getHeight(DTNode<T> * node) const ;

    int getDepth() const;
    int getDepth(DTNode<T> * node) const;

    int getLevel() const;
    int getLevel(DTNode<T> * node) const;

    void sort(T a[], int N);
    DTNode<T>* searchForNode(const T value);
};


template <class T>
DosTres<T>::~DosTres(){
    clear();
}

template <class T>
bool DosTres<T>::empty(){
    return root == nullptr;
}

template <class T>
void DosTres<T>::clear(){
    clear(root);
}

template <class T>
void DosTres<T>::clear(DTNode<T> * node){
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

template <class T>
DTNode<T> * DosTres<T>::getRoot() const{
    return root;
}

template <class T>
void DosTres<T>::setRoot(const T element){
    DTNode<T> * node = new DTNode<T>(element);
    setRoot(node);
}

template <class T>
void DosTres<T>::setRoot(DTNode<T> * node){
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
bool DosTres<T>::isRoot(DTNode<T> * node){
    return node == this->root;
}

template <class T>
void DosTres<T>::insert23(T item){
    insert23(this->root, item);
}

template <class T>
void DosTres<T>::insert23(DTNode<T> * item){
    insert23(this->root, item);
}

template <class T>
void DosTres<T>::forceRoot(DTNode<T>* node){
    root = node;
}

template <class T>
void DosTres<T>::redistributeChildren(DTNode<T>* container, DTNode<T>* n1, DTNode<T>* n2){
    n1->setLeft(container->getLeft());
    n1->setRight(container->getMiddle());
    n2->setLeft(container->getTempChild());
    n2->setRight(container->getRight());
    n1->getLeft()->setParent(n1);
    n1->getRight()->setParent(n1);
    n2->getLeft()->setParent(n2);
    n2->getRight()->setParent(n2);
}

template <class T>
void DosTres<T>::split(DTNode<T>* container){
    if(isRoot(container)){
        DTNode<T>* newRoot = new DTNode<T>(container->getTempMiddle());
        forceRoot(newRoot);
        DTNode<T>* n1 = new DTNode<T>(container->getLower());
        DTNode<T>* n2 = new DTNode<T>(container->getHigher());
        if(container->getTempChild()!=nullptr)
            redistributeChildren(container, n1, n2);
        newRoot->setLeft(n1);
        newRoot->setRight(n2);
        newRoot->getLeft()->setParent(newRoot);
        newRoot->getRight()->setParent(newRoot);
        delete container;
    }
    else if(container->getParent() != nullptr){
        DTNode<T>* parent = container->getParent();
        if(parent->isFull()){
            parent->setMiddleValue(container->getTempMiddle());
            if(parent->getRight() == container){
                DTNode<T>* n1 = new DTNode<T>(container->getLower());
                DTNode<T>* n2 = new DTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setRight(n2);
                parent->setTempChild(n1);
                parent->getRight()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
            }
            else if(parent->getLeft() == container){
                DTNode<T>* n1 = new DTNode<T>(container->getLower());
                DTNode<T>* n2 = new DTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setLeft(n1);
                parent->setTempChild(parent->getMiddle());
                parent->setMiddle(n2);
                parent->getLeft()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;

            }
            else{
                DTNode<T>* n1 = new DTNode<T>(container->getLower());
                DTNode<T>* n2 = new DTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setMiddle(n1);
                parent->setTempChild(n2);
                parent->getMiddle()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
            }
            split(parent);
        }
        else{
            parent->setValue(container->getTempMiddle());
            if(parent->getRight() == container){
                DTNode<T>* n1 = new DTNode<T>(container->getLower());
                DTNode<T>* n2 = new DTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setRight(n2);
                parent->setMiddle(n1);
                parent->getRight()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                delete container;
            }
            else if(parent->getLeft() == container){
                DTNode<T>* n1 = new DTNode<T>(container->getLower());
                DTNode<T>* n2 = new DTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setLeft(n1);
                parent->setMiddle(n2);
                parent->getLeft()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                delete container;
            }
            if(parent->has3Keys())
                split(parent);
        }
    }
}

template <class T>
bool DosTres<T>:: is2Node(DTNode<T>* node){
    if((node->hasLower() && !node->hasHigher()) || (!node->hasLower() && node->hasHigher()))
        return true;
    else
        return false;
}

template <class T>
bool DosTres<T>:: is3Node(DTNode<T>* node){
    if(node->hasLower() && node->hasHigher())
        return true;
    else
        return false;
}

template <class T>
bool DosTres<T>::hasFreeChildren(DTNode<T>* node){
    if(node->getLeft() == nullptr || node->getMiddle() == nullptr || node->getRight() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void DosTres<T>::insert23(DTNode<T> * parent, T item){
    DTNode<T>* container = new DTNode<T>();
    if(root == nullptr){
        forceRoot(new DTNode<T>(item));
        return;
    }
    container = searchForNode(item, root);
    if(is2Node(container)){
        container->setValue(item);
        container->deleteTempMiddle();
    }
    else if(is3Node(container)){
        container->setMiddleValue(item);
        split(container);
    }
}

template <class T>
DTNode<T>* DosTres<T>::searchForNode(const T value){
    return searchForNode(value, root);

}

template <class T>
DTNode<T>* DosTres<T>::searchForNode(const T value, DTNode<T> * node){
    if(node == nullptr)
        return nullptr;
    if(isLeaf(node))
        return node;
    else if(is2Node(node)){
        if(value <= node->getLower())
            return searchForNode(value, node->getLeft());
        else
            return searchForNode(value, node->getRight());
    }
    else if(is3Node(node)){
        if(value <= node->getLower())
            return searchForNode(value, node->getLeft());
        else if(value > node->getHigher())
            return searchForNode(value, node->getRight());
        else
            return searchForNode(value, node->getMiddle());
    }
    return node;
}

template <class T>
void DosTres<T>::printAsc(){
    printAsc(root, 0);
    std::cout << std::endl;
}

template <class T>
void DosTres<T>::printAsc(DTNode<T> * node, int lv){
    if(node == nullptr) return;
    if(isLeaf(node)){
        if(is2Node(node)){
            std::cout << node->getLower() << " "<< std::flush;
        }
        else if(is3Node(node)){
            std::cout << node->getLower() << " " << node->getHigher();
        }
    }
    else if(is2Node(node)){
        printAsc(node->getLeft(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        printAsc(node->getRight(), lv);
    }
    else if(is3Node(node)){
        printAsc(node->getLeft(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        printAsc(node->getMiddle(), lv);
        std::cout << node->getHigher() << " "<< std::flush;
        printAsc(node->getRight(), lv);
    }
}

template <class T>
void DosTres<T>::printDesc(){
    printDesc(root, 0);
    std::cout << std::endl;
}

template <class T>
void DosTres<T>::printDesc(DTNode<T> * node, int lv){
    if(node == nullptr) return;
    if(isLeaf(node)){
        if(is2Node(node)){
            std::cout << node->getLower() << " "<< std::flush;
        }
        else if(is3Node(node)){
            std::cout << node->getHigher() << " " << node->getLower() << " ";
        }
    }
    else if(is2Node(node)){
        printDesc(node->getRight(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        printDesc(node->getLeft(), lv);
    }
    else if(is3Node(node)){
        printDesc(node->getRight(), lv);
        std::cout << node->getHigher() << " "<< std::flush;
        printDesc(node->getMiddle(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        printDesc(node->getLeft(), lv);
    }
}


template <class T>
void DosTres<T>::fixTree(DTNode<T>* node){
    if(isRoot(node)){
        forceRoot(node->getMiddle());
        delete node;
    }
    else{
        bool threeKeys = false;
        DTNode<T>* parent = node->getParent();
        if(is2Node(parent)){
            DTNode<T>* sibling = new DTNode<T>();
            if(parent->getRight() == node)
                sibling = parent->getLeft();
            else
                sibling = parent->getRight();
            if(parent->getRight() == node){
                if(is3Node(parent->getLeft())){
                    threeKeys = true;
                    T siblingLower = sibling->getLower();
                    T siblingHigher = sibling->getHigher();
                    T parentVal = parent->getLower();
                    T keys[3] = {siblingLower,siblingHigher,parentVal};
                    sort(keys,3);
                    T low = keys[0];
                    T mid = keys[1];
                    T high = keys[2];
                    node->setValue(high);
                    parent->deleteAllKeys();
                    parent->setValue(mid);
                    sibling->deleteAllKeys();
                    sibling->setValue(low);


                    if(!isLeaf(node)){
                        node->setRight(node->getMiddle());
                        node->setMiddle(nullptr);
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else{
                if(is3Node(parent->getRight())){
                    threeKeys = true;
                    T siblingLower = sibling->getLower();
                    T siblingHigher = sibling->getHigher();
                    T parentVal = parent->getLower();
                    T keys[3] = {siblingLower,siblingHigher,parentVal};
                    sort(keys,3);
                    T low = keys[0];
                    T mid = keys[1];
                    T high = keys[2];
                    node->setValue(low);
                    parent->deleteAllKeys();
                    parent->setValue(mid);
                    sibling->deleteAllKeys();
                    sibling->setValue(high);

                    if(!isLeaf(node)){
                        node->setLeft(node->getMiddle());
                        node->setMiddle(nullptr);
                        node->setRight(sibling->getLeft());
                        node->getRight()->setParent(node);
                        sibling->setLeft(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
        }
        else if(is3Node(parent)){
            DTNode<T>* sibling = new DTNode<T>();
            if(parent->getRight() == node){
                if(is3Node(parent->getMiddle())){
                    threeKeys = true;
                    sibling = parent->getMiddle();
                    node->setValue(parent->getHigher());
                    parent->setHigher(sibling->getHigher());
                    sibling->deleteHigher();
                    if(!isLeaf(node)){
                        node->setRight(node->getMiddle());
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else if(parent->getMiddle() == node){
                if(is3Node(parent->getLeft())){
                    threeKeys = true;
                    sibling = parent->getLeft();
                    node->setValue(parent->getLower());
                    parent->setLower(sibling->getHigher());
                    sibling->deleteHigher();
                    if(!isLeaf(node)){
                        node->setRight(node->getMiddle());
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else{
                if(is3Node(parent->getMiddle())){
                    threeKeys = true;
                    sibling = parent->getMiddle();
                    node->setValue(parent->getLower());
                    parent->setLower(sibling->getLower());
                    sibling->swapHigherToLower();
                    if(!isLeaf(node)){
                        node->setLeft(node->getMiddle());
                        node->setRight(sibling->getLeft());
                        node->getRight()->setParent(node);
                        sibling->setLeft(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
        }
        if(!threeKeys){
            DTNode<T>* sibling = new DTNode<T>();
            if(is2Node(parent)){
                if(parent->getRight() == node){
                    sibling = parent->getLeft();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node)){
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());
                    }
                    parent->setMiddle(sibling);
                    parent->getMiddle()->setParent(parent);
                    parent->setLeft(nullptr);
                    parent->setRight(nullptr);
                    parent->deleteAllKeys();
                    delete node;
                }
                else{
                    sibling = parent->getRight();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node)){
                        sibling->setMiddle(sibling->getLeft());
                        sibling->setLeft(node->getMiddle());
                        sibling->getLeft()->setParent(sibling);
                    }
                    parent->setMiddle(sibling);
                    parent->getMiddle()->setParent(parent);
                    parent->setLeft(nullptr);
                    parent->setRight(nullptr);
                    parent->deleteAllKeys();
                    delete node;
                }
            }
            else if(is3Node(parent)){
                if(parent->getRight() == node){
                    sibling = parent->getMiddle();
                    sibling->setValue(parent->getHigher());
                    if(!isLeaf(node)){
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());
                        sibling->getRight()->setParent(sibling);
                    }
                    parent->setRight(sibling);
                    parent->getRight()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteHigher();
                    delete node;
                }
                else if(parent->getMiddle() == node){
                    sibling = parent->getLeft();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node)){
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());
                        sibling->getRight()->setParent(sibling);
                    }
                    parent->setLeft(sibling);
                    parent->getLeft()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteLower();
                    parent->swapHigherToLower();
                    delete node;
                }
                else{
                    sibling = parent->getMiddle();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node)){
                        sibling->setMiddle(sibling->getLeft());
                        sibling->setLeft(node->getMiddle());
                        sibling->getLeft()->setParent(sibling);
                    }
                    parent->setLeft(sibling);
                    parent->getLeft()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteLower();
                    parent->swapHigherToLower();
                    delete node;
                }
            }
            if(parent->hasNoKeys()){
                sibling->setParent(parent);
                fixTree(parent);
            }
        }
    }
}

template <class T>
bool DosTres<T>::deleteNode(T value){
    DTNode<T>* node = new DTNode<T>();
    node = findNodeToDelete(root, value);
    if(node){
        DTNode<T>* leafNode = new DTNode<T>();
        if(!isLeaf(node)){
            leafNode = getInorderSuccesor(node);
            T swapVal = leafNode->getLower();
            node->setLower(swapVal);
        }
        else{
            if(node->getHigher() == value){
                node->deleteHigher();
                return true;
            }
        }
        leafNode->deleteLower();
        if(leafNode->hasNoKeys()){
            fixTree(leafNode);
        }
        return true;
    }
    else
        return false;
}

template <class T>
DTNode<T>* DosTres<T>::getInorderSuccesor(DTNode<T>* node){
    if (node){
        DTNode<T> * workingNode = node->getLeft();
        if(workingNode){
            while (workingNode->getRight() != nullptr){
                workingNode = workingNode->getRight();
            }
            return workingNode;
        }
        return nullptr;

    } else{
        return nullptr;
    }
}

template <class T>
DTNode<T>* DosTres<T>::findNodeToDelete(DTNode<T>* node, T value){
    if(node == nullptr)
        return nullptr;
    if(isLeaf(node)){
        if(is2Node(node)){
            if(node->getLower() == value){
                return node;
            }
        }
        else if(is3Node(node)){
            if(node->getLower() == value || node->getHigher() == value){
                return node;
            }
        }
        return nullptr;
    }
    else if(is2Node(node)){
        if(value == node->getLower()){
            return node;
        }

        if(value < node->getLower())
            return findNodeToDelete(node->getLeft(), value);
        else
            return findNodeToDelete( node->getRight(), value);
    }
    else if(is3Node(node)){
        if(node->getLower() == value || node->getHigher() == value){
            return node;
        }
        if(value < node->getLower())
            return findNodeToDelete(node->getLeft(), value);
        else if(value > node->getHigher())
            return findNodeToDelete(node->getRight(), value);
        else
            return findNodeToDelete(node->getMiddle(), value);
    }
    return nullptr;
}

template <class T>
bool DosTres<T>::findNode(DTNode<T>* node, T value){
    if(node == nullptr)
        return false;
    if(isLeaf(node)){
        if(is2Node(node)){
            if(node->getLower() == value){
                return true;
            }
        }
        else if(is3Node(node)){
            if(node->getLower() == value || node->getHigher() == value){
                return true;
            }
        }
        return false;
    }
    else if(is2Node(node)){
        if(value == node->getLower()){
            return true;
        }

        if(value < node->getLower())
            return findNode(node->getLeft(), value);
        else
            return findNode( node->getRight(), value);
    }
    else if(is3Node(node)){
        if(node->getLower() == value || node->getHigher() == value){
            return true;
        }
        if(value < node->getLower())
            return findNode(node->getLeft(), value);
        else if(value > node->getHigher())
            return findNode(node->getRight(), value);
        else
            return findNode(node->getMiddle(), value);
    }
    return false;
}

template <class T>
bool DosTres<T>::isTT(){
    return isTT(root);
}

template <class T>
bool DosTres<T>::isTT(DTNode<T>* node){
    leafLevels.clear();
    getLeafLevels(root);
    T cmp = leafLevels[0];
    bool leafs = true;
    for(int i=1; i<leafLevels.size(); i++){
        if(leafLevels[i] != cmp)
            leafs = false;
    }
    return leafs;
}

template <class T>
void DosTres<T>::getLeafLevels(DTNode<T>* node){
    if(node == nullptr) return;
    if(isLeaf(node)){
        leafLevels.push_back(getLevel(node));
    }
    else if(is2Node(node)){
        getLeafLevels(node->getLeft());
        getLeafLevels(node->getRight());
    }
    else if(is3Node(node)){
        getLeafLevels(node->getLeft());
        getLeafLevels(node->getMiddle());
        getLeafLevels(node->getRight());
    }
}

template <class T>
void DosTres<T>::isLeaf(){
    isLeaf(root);
}

template <class T>
bool DosTres<T>::isLeaf(DTNode<T> * node){
    if(node->getLeft() == nullptr && node->getMiddle() == nullptr && node->getRight() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void DosTres<T>::ancestors(DTNode<T> * node) const{
    if (node) {
        std::cout << *node << " -> ";
        ancestors(node->getParent());
    }
}

template <class T>
int DosTres<T>::getHeight() const{
    return getHeight(root);
}

template <class T>
int DosTres<T>::getHeight(DTNode<T> * node) const{
    if (!node) return -1;
    return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}

template <class T>
int DosTres<T>::getDepth() const{
    return getDepth(root);
}

template <class T>
int DosTres<T>::getDepth(DTNode<T> * node) const{
    if (node == nullptr){
        return 0;
    }
    else{
        return getDepth(node->getParent())+1;
    }
}

template <class T>
int DosTres<T>::getLevel() const{
    return getLevel(root);
}

template <class T>
int DosTres<T>::getLevel(DTNode<T> * node) const{
    int level = 0;
    while (node != nullptr && node->getParent() != nullptr) {
        level++;
        node = node->getParent();
    }
    return level;
}

template <class T>
void DosTres<T>::sort(T a[], int N){
        int i, j, flag = 1;
        int temp;
        int numLength = N;
        for(i = 1; (i <= numLength) && flag; i++){
            flag = 0;
            for (j=0; j < (numLength -1); j++){
                if (a[j+1] < a[j])
                    temp = a[j];
            {
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    flag = 1;
                }
            }
        }
        return;
}
