#include <iostream>
#include "BRBNode.h"

template <class T>
class BiTree{
    BRBNode<T> * raiz = nullptr;
    std::ostream& imprime(std::ostream& os, BRBNode<T> * nodo);

public:
    BiTree();
    BiTree(BRBNode<T> * info);

    ~BiTree();
    void clear();
    void clear(BRBNode<T> * nodo);

    bool empty();
    BRBNode<T> * getRaiz();
    void setRaiz(BRBNode<T> * nodo)
    {
        raiz = nodo;
    }
    bool insert(T value, BRBNode<T> * padre);

    void preOrden();
    void preOrden(BRBNode<T> * nodo);
    void preOrden(BRBNode<T> * nodo, T info);

    void inOrden();
    void inOrden(BRBNode<T> * nodo);

    void postOrden();
    void postOrden(BRBNode<T> * nodo);

    template <typename Tn>
    friend std::ostream& operator<<(std::ostream& os, BiTree<Tn> &arbol);

    int nivel(BRBNode<T> * nodo);

    BRBNode<T> * suma_ineficiente();
    BRBNode<T> * suma_ineficiente(BRBNode<T> * nodo);
    T suma();
    T suma_eficiente(BRBNode<T> * nodo);
    void suma_eficiente(BRBNode<T> * nodo, BRBNode<T> * acumulador);
    T suma(BRBNode<T> * nodo);

    BRBNode<T> * getPadre(T info);
    void hermanos(BRBNode<T> * n1);
    bool sonHermanos(T n1, T n2);
    bool sonHermanos(BRBNode<T> * n1, BRBNode<T> * n2);

    void primosHermanos(BRBNode<T> * nodo, BRBNode<T> * raiz);
    void ancestros(BRBNode<T> *nodo);

    BRBNode<T> * buscar (T info);
    BRBNode<T> * buscar (T info, BRBNode<T> * nodo);
};

template <class T>
BiTree<T>::BiTree() { }

template <class T>
BiTree<T>::BiTree(BRBNode<T> * info) {
    raiz = info;
}

template <class T>
BiTree<T>::~BiTree() {
    clear(raiz);
}

template <class T>
void BiTree<T>::clear() {
    clear(raiz);
}

template <class T>
void BiTree<T>::clear(BRBNode<T> * nodo) {
    if (nodo) {
        clear(nodo->getIzquierdo());
        clear(nodo->getDerecho());

        // Liberar el nodo
        delete nodo;
    }
}

template <class T>
bool BiTree<T>::empty() {
    return (raiz == nullptr);
}

template <class T>
BRBNode<T> * BiTree<T>::getRaiz() {
    return raiz;
}

template <class T>
bool BiTree<T>::insert(T value, BRBNode<T> * padre) {
    // Insertar la raiz
    if (!padre)
        raiz = new BRBNode<T>(value);
    else {
        if (!padre->getIzquierdo()) {
            BRBNode<T> * nuevo = new BRBNode<T>(value);
            nuevo->setPadre(padre);
            padre->setIzquierdo(nuevo);
        }
        else if (!padre->getDerecho()) {
            BRBNode<T> * nuevo = new BRBNode<T>(value);
            nuevo->setPadre(padre);
            padre->setDerecho(nuevo);
        }
        else
            return false;
    }
    return true;
}

template <class T>
void BiTree<T>::preOrden() {
    preOrden(raiz);
}
//this used to be
template <class T>
void BiTree<T>::preOrden(BRBNode<T> * nodo) {
    if (nodo) {
        std::cout << *nodo << std::endl;
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }
}

template <class T>
void BiTree<T>::preOrden(BRBNode<T> * nodo, T info) {
    if (nodo) {
        if (!(nodo->getInfo() == info))
            std::cout << *nodo->getInfo() << std::endl;
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }
}

template <class T>
void BiTree<T>::inOrden() {
    inOrden(raiz);
}

template <class T>
void BiTree<T>::inOrden(BRBNode<T> * nodo) {
    if (nodo) {
        inOrden(nodo->getIzquierdo());
        std::cout << *nodo << " " <<nodo->getColor()<<" ";
        inOrden(nodo->getDerecho());
    }
}

template <class T>
void BiTree<T>::postOrden() {
    postOrden(raiz);
}

template <class T>
void BiTree<T>::postOrden(BRBNode<T> * nodo) {
    if (nodo) {
        postOrden(nodo->getIzquierdo());
        postOrden(nodo->getDerecho());
        std::cout << *nodo << " ";
    }
}

template <class T>
int BiTree<T>::nivel(BRBNode<T> *nodo) {
    if (nodo == nullptr)
        return 0;

    BRBNode<T> * aux = nodo;
    int nivel = 1;
    while (aux->getPadre()) {
        ++nivel;
        aux = aux->getPadre();
    }
    return nivel;
}


template <class T>
BRBNode<T> * BiTree<T>::buscar(T info)
{
    return buscar(info, raiz);
}

template <class T>
BRBNode<T> * BiTree<T>::buscar(T info, BRBNode<T> * node)
{
//    BRBNode<T> * encontrado = nullptr;
//
//    if (nodo) {
//        if (nodo->getInfo() == info) {
//            if(nodo->getDerecho() != nullptr)
//                if(nodo->getDerecho()->getInfo()==info)
//                    return nodo->getDerecho();
//            if(nodo->getIzquierdo() != nullptr)
//                if(nodo->getIzquierdo()->getInfo()==info)
//                    return nodo->getIzquierdo();
//            return nodo;
//        }
//        else {
//            encontrado = buscar(info, nodo->getIzquierdo());
//
//            if (encontrado) {
//                return encontrado;
//            }
//
//            return buscar(info, nodo->getDerecho());
//        }
//    }
//
//    return encontrado;
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (info == node->getInfo())
        {
            return node;
        }
        else if (info < node->getInfo())
        {
            return buscar(info, node->getIzquierdo());
        }
        else {
            return buscar(info, node->getDerecho());
        }
    }
}

template <class T>
BRBNode<T> * BiTree<T>::getPadre(T info) {
    BRBNode<T> * nodo = buscar(info);
    return nodo->getPadre();
}

template <class T>
void BiTree<T>::hermanos(BRBNode<T> * nodo) {
    BRBNode<T> * izquierdo = nodo->getPadre()->getIzquierdo();
    BRBNode<T> * derercho = nodo->getPadre()->getDerecho();
    if (izquierdo && izquierdo != nodo)
        std::cout << *izquierdo->getInfo();
    if (derercho && derercho != nodo)
        std::cout << *derercho->getInfo();
}

template <class T>
bool BiTree<T>::sonHermanos(T n1, T n2) {
    return sonHermanos(buscar(n1), buscar(n2));
}

template <class T>
bool BiTree<T>::sonHermanos(BRBNode<T> * n1, BRBNode<T> * n2) {
    if (n1 == nullptr || n2 == nullptr || n1 == n2)
        return false;
    return (n1->getPadre() == n2->getPadre());
}

template <class T>
void BiTree<T>::primosHermanos(BRBNode<T> *nodo, BRBNode<T> *raiz) {
    if (raiz) {
        if (nivel(nodo) == nivel(raiz) && sonHermanos(nodo->getPadre(), raiz->getPadre())) {
            std::cout << *raiz->getInfo() << std::endl;
        }
        primosHermanos(nodo, raiz->getIzquierdo());
        primosHermanos(nodo, raiz->getDerecho());
    }
}

template <class T>
void BiTree<T>::ancestros(BRBNode<T> *nodo) {
    BRBNode<T> * padre = nodo->getPadre();
    while (padre) {
        std::cout << *padre->getInfo() << std::endl;
        padre = padre->getPadre();
    }
}

template <class T>
BRBNode<T> * BiTree<T>::suma_ineficiente() {
    return suma_ineficiente(raiz);
}

template <class T>
BRBNode<T> * BiTree<T>::suma_ineficiente(BRBNode<T> * nodo) {
    T valor;
    if (nodo) {
        valor = nodo->getInfo();
        BRBNode<T> * suma_ineficiente_izq = suma_ineficiente(nodo->getIzquierdo());
        if (suma_ineficiente_izq) {
            valor += suma_ineficiente_izq->getInfo();
            delete suma_ineficiente_izq;
        }

        BRBNode<T> * suma_ineficiente_der = suma_ineficiente(nodo->getDerecho());
        if (suma_ineficiente_der) {
            valor += suma_ineficiente_der->getInfo();
            delete suma_ineficiente_der;
        }
        return new BRBNode<T>(valor);
    }
    return nullptr;
}

template <class T>
T BiTree<T>::suma_eficiente(BRBNode<T> * nodo) {
    BRBNode<T> * acumulador = new BRBNode<T>(0);
    suma_eficiente(nodo, acumulador);
    T valor = acumulador->getInfo();
    delete acumulador;
    return valor;
}

template <class T>
void BiTree<T>::suma_eficiente(BRBNode<T> * nodo, BRBNode<T> * acumulador) {
    if (nodo) {
        acumulador->setInfo(acumulador->getInfo() + nodo->getInfo());
        suma_eficiente(nodo->getIzquierdo(), acumulador);
        suma_eficiente(nodo->getDerecho(), acumulador);
    }
}

template <class T>
T BiTree<T>::suma() {
    return suma(raiz);
}

template <class T>
T BiTree<T>::suma(BRBNode<T> *nodo) {
    static T valor;
    if (nodo) {
        valor += nodo->getInfo();
        suma(nodo->getIzquierdo());
        suma(nodo->getDerecho());
    }
    return valor;
}

template <class T>
std::ostream& BiTree<T>::imprime(std::ostream& os, BRBNode<T> * nodo) {
    if (nodo) {
        os << *nodo;
        imprime(os, nodo->getIzquierdo());
        imprime(os, nodo->getDerecho());
    }
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, BiTree<T> &arbol) {
    return arbol.imprime(os, arbol.raiz);
}
