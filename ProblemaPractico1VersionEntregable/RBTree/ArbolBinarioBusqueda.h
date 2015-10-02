#include <iostream>
#include "BiTree.h"

template<class T>
class ArbolBinarioBusqueda : public BiTree<T>{
public:
    ArbolBinarioBusqueda();
    virtual BRBNode<T>* insertar(T valor);
    void removeNodo(T valor);
    void print();
};

template<class T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda() : BiTree<T>(){

}

template<class T>
BRBNode<T>* ArbolBinarioBusqueda<T>::insertar(T valor){
    BRBNode<T> * nodo = new BRBNode<T>(valor);
    BRBNode<T> * padre;

    nodo->setDerecho(nullptr);
    nodo->setIzquierdo(nullptr);

    padre = nodo->getPadre();

    if(this->empty()){
        //BRBNode<T> * raiz = this->getRaiz();
        this->setRaiz(nodo);
    }
    else{
        BRBNode<T> * actual = new BRBNode<T>();

        actual = this->getRaiz();

        while (actual){
            padre = actual;

            if(nodo->getInfo() >= actual->getInfo()){
                actual = actual->getDerecho();
            }
            else{
                actual = actual->getIzquierdo();
            }
        }

        if(nodo->getInfo() >= padre->getInfo()){
            padre->setDerecho(nodo);
            nodo->setPadre(padre);
        }
        else{
            padre->setIzquierdo(nodo);
            nodo->setPadre(padre);
        }
    }
    return nodo;
}

template<class T>
void ArbolBinarioBusqueda<T>::removeNodo(T valor){
    BRBNode<T> * root = this->getRaiz();

    if(this->empty()){
        return;
    }

    BRBNode<T> * actual = root;
    BRBNode<T> * parent;

    // root to leaf search (top-down)
    while(actual){
        if(actual->getInfo() == valor){
            break;
        }
        else{
            parent = actual;
            actual = valor > actual->getInfo() ? actual->getDerecho() : actual->getIzquierdo();
        }
    }

    if(actual == nullptr){
        return;
    }


    if( actual->getIzquierdo() == nullptr and actual->getDerecho() == nullptr) {
        if(parent->getIzquierdo() == actual)
            parent->setIzquierdo(nullptr);
        else
            parent->setDerecho(nullptr);

        delete actual;

        return;
    }

    if((actual->getIzquierdo() == nullptr and actual->getDerecho() != nullptr) or (actual->getIzquierdo() != nullptr and actual->getDerecho() == nullptr)) {
        if(actual->getIzquierdo() == nullptr and actual->getDerecho() != nullptr) {
            if(parent->getIzquierdo() == actual) {
                parent->setIzquierdo(actual->getDerecho());
            } else {
                parent->setDerecho(actual->getDerecho());
            }
        } else {
            if(parent->getIzquierdo() == actual) {
                parent->setIzquierdo(actual->getIzquierdo());
            } else {
                parent->setDerecho(actual->getIzquierdo());
            }
        }
        delete actual;

        return;
    }

    if (actual->getIzquierdo() != nullptr and actual->getDerecho() != nullptr) {
        BRBNode<T> *actual_right = actual->getDerecho();
        if(actual_right->getIzquierdo() == nullptr and actual_right->getDerecho() == nullptr) {
            actual->setInfo(actual_right->getInfo());
            delete actual_right;
            actual->setDerecho(nullptr);
        } else {
            if((actual->getDerecho())->getIzquierdo() != nullptr) {
                BRBNode<T>* lactual;
                BRBNode<T>* lactual_parent;
                lactual_parent = actual->getDerecho();
                lactual = (actual->getDerecho())->getIzquierdo();
                while(lactual->getIzquierdo() != nullptr) {
                    lactual_parent = lactual;
                    lactual = lactual->getIzquierdo();
                }
                actual->setInfo(lactual->getInfo());
                delete lactual;
                lactual_parent->setIzquierdo(nullptr);
            } else { // (actual->right)->right != nullptr
                BRBNode<T> *tmp = actual->getDerecho();
                actual->setInfo(tmp->getInfo());
                actual->setDerecho(tmp->getDerecho());
                delete tmp;
            }
        }

    }

}

template<class T>
void ArbolBinarioBusqueda<T>::print(){
    std::cout<<*this;
}
