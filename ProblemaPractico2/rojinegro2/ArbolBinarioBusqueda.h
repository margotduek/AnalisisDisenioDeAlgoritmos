
#include <iostream>

#include "ArbolBinario.h"

template<class T>
class ArbolBinarioBusqueda : public ArbolBinario<T>
{
public:
    ArbolBinarioBusqueda();
    virtual NodoB<T>* insertar(T valor);
    void removeNodo(T valor);
    void print();
};

template<class T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda() : ArbolBinario<T>()
{

}

template<class T>
NodoB<T>* ArbolBinarioBusqueda<T>::insertar(T valor)
{
    NodoB<T> * nodo = new NodoB<T>(valor);
    NodoB<T> * padre;

    nodo->setDerecho(nullptr);
    nodo->setIzquierdo(nullptr);

    padre = nodo->getPadre();

    if(this->empty())
    {
        //NodoB<T> * raiz = this->getRaiz();
        this->setRaiz(nodo);
    }
    else
    {
        NodoB<T> * actual = new NodoB<T>();

        actual = this->getRaiz();

        while (actual)
        {
            padre = actual;

            if(nodo->getInfo() >= actual->getInfo())
            {
                actual = actual->getDerecho();
            }
            else
            {
                actual = actual->getIzquierdo();
            }
        }

        if(nodo->getInfo() >= padre->getInfo())
        {
            padre->setDerecho(nodo);
            nodo->setPadre(padre);
        }
        else
        {
            padre->setIzquierdo(nodo);
            nodo->setPadre(padre);
        }
    }
    return nodo;


}

template<class T>
void ArbolBinarioBusqueda<T>::removeNodo(T valor)
{
    NodoB<T> * root = this->getRaiz();

    if(this->empty())
    {
        return;
    }

    NodoB<T> * actual = root;
    NodoB<T> * parent;

    // root to leaf search (top-down)
    while(actual)
    {
        if(actual->getInfo() == valor)
        {
            break;
        }
        else
        {
            parent = actual;
            actual = valor > actual->getInfo() ? actual->getDerecho() : actual->getIzquierdo();
        }
    }

    if(actual == nullptr)
    {
        return;
    }


    // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children


    //We're looking at a leaf node
    if( actual->getIzquierdo() == nullptr and actual->getDerecho() == nullptr) {
        if(parent->getIzquierdo() == actual)
            parent->setIzquierdo(nullptr);
        else
            parent->setDerecho(nullptr);

        delete actual;

        return;
    }

    // Node with single child
    if((actual->getIzquierdo() == nullptr and actual->getDerecho() != nullptr) or (actual->getIzquierdo() != nullptr and actual->getDerecho() == nullptr)) {
        if(actual->getIzquierdo() == nullptr and actual->getDerecho() != nullptr) {
            if(parent->getIzquierdo() == actual) {
                parent->setIzquierdo(actual->getDerecho());
            } else {
                parent->setDerecho(actual->getDerecho());
            }
        } else { // getIzquierdo child present, no right child
            if(parent->getIzquierdo() == actual) {
                parent->setIzquierdo(actual->getIzquierdo());
            } else {
                parent->setDerecho(actual->getIzquierdo());
            }
        }
        delete actual;

        return;
    }

    // Node with 2 children
    // replace node with smallest value in right subtree
    if (actual->getIzquierdo() != nullptr and actual->getDerecho() != nullptr) {
        NodoB<T> *actual_right = actual->getDerecho();
        if(actual_right->getIzquierdo() == nullptr and actual_right->getDerecho() == nullptr) {
            actual->setInfo(actual_right->getInfo());
            delete actual_right;
            actual->setDerecho(nullptr);
        } else { // right child has children
            //if the node's right child has a getIzquierdo child
            // Move all the way down getIzquierdo to locate smallest element

            if((actual->getDerecho())->getIzquierdo() != nullptr) {
                NodoB<T>* lactual;
                NodoB<T>* lactual_parent;
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
                NodoB<T> *tmp = actual->getDerecho();
                actual->setInfo(tmp->getInfo());
                actual->setDerecho(tmp->getDerecho());
                delete tmp;
            }
        }

    }

}

template<class T>
void ArbolBinarioBusqueda<T>::print()
{
    std::cout<<*this;
}
