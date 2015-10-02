//
//  BTNode.h
//  Arboles
//
//  Created by Krikor Bisdikian on 9/30/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#include <fstream>
#include <iostream>
#ifndef BTNode_h
#define BTNode_h

template <class T, int orden>
class BTNode {
    int count;
    std::string fileName;
    static int id;
    T data[orden-1];
    std::string children[orden];

public:
    BTNode();
    BTNode(int count, T * data, std::string * children, std::string fileName);
    virtual ~BTNode();

    int getCount(){
        return count;
    }
    T & getData(int pos);

    std::string getChildren(int pos);
    std::string getFileName(){
        return fileName;
    }

    void setCount(int count);
    void setData(int pos, T data);
    void setChildren(int pos, std::string node);

    void incrementCount(){
        setCount(count + 1);
    }
    void decrementCount(){
        setCount(count - 1);
    }

    void write();

    template <typename C, int n>
    friend std::ostream & operator << (std::ostream & os, BTNode<C, n>  & node);

};

template<class T, int orden>
int BTNode<T, orden>::id = 0;

template <class T, int orden>
BTNode<T, orden>::BTNode()
{
    fileName = ".node" + std::to_string(++id);
    count = 0;

    for (int i = 0; i < orden; i++)
        data[i] = 0;

    for (int i = 0; i < orden + 1; i++)
        children[i] = "NaN";

    write();
}

template <class T, int orden>
BTNode<T, orden>::BTNode(int count, T * data, std::string * children, std::string fileName){
    this->fileName = fileName;
    this->count = count;
    for (int i = 0; i < orden - 1; i++)
        this->data[i] = data[i];
    for (int i = 0; i < orden; i++)
        this->children[i] = children[i];
}

template <class T, int orden>
BTNode<T, orden>::~BTNode(){

}

template <class T, int orden>
std::string BTNode<T, orden>::getChildren(int pos){
    if (pos < orden  && pos >= 0)
        return this->children[pos];
    else
        return "";
}


template <class T, int orden>
T & BTNode<T, orden>::getData(int pos){
    T hola;
    if (pos < orden - 1 && pos >= 0)
        return data[pos];
    else
        return hola;
}

template <class T, int orden>
void BTNode<T, orden>::setCount(const int count){
    this->count = count;
    write();
}


template <class T, int orden>
void BTNode<T, orden>::setData(const int pos, T t)
{
    if (pos < orden - 1 && pos >= 0)
    {
        this->data[pos] = t;
        write();
    }
    else
        std::cout<<"Error\n";
}

template <class T, int orden>
void BTNode<T, orden>::setChildren(int pos, std::string name)
{
    if (pos < orden && pos >= 0)
    {
        this->children[pos] = name;
        write();
    }
    else
        std::cout<<"Error\n";
}

template <class T, int orden>
void BTNode<T, orden>::write()
{
    std::ofstream nodeFile;
    nodeFile.open(fileName, std::ofstream::out | std::ofstream::trunc);

    nodeFile << count << " ";
    for (int i = 0; i < orden - 1; i++)
    {
        if (data[i] == 0)
        {
            nodeFile << "0 ";
        }
        else
        {
            nodeFile << data[i] << " ";
        }
    }
    for (int i = 0; i < orden; i++)
    {
        nodeFile << children[i] << " ";
    }
    nodeFile.close();
}

template <class T, int orden>
std::ostream & operator << (std::ostream & os, BTNode<T, orden>  & node)
{
    for (int i = 0; i < orden - 1; i++)
    {
        if (i < node.getCount())
            os << node.getData(i) << " ";
    }
    return os;
}


#endif /* BTNode_h */
