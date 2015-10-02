
#include <iostream>
#include "NodoB.h"

template <class T>
class ArbolBinario
{
    NodoB<T> * raiz = nullptr;

    std::ostream& imprime(std::ostream& os, NodoB<T> * nodo);

public:
    ArbolBinario();
    ArbolBinario(NodoB<T> * info);

    ~ArbolBinario();
    void clear();
    void clear(NodoB<T> * nodo);

    bool empty();
    NodoB<T> * getRaiz();
    void setRaiz(NodoB<T> * nodo)
    {
        raiz = nodo;
    }
    bool insert(T value, NodoB<T> * padre);

    void preOrden();
    void preOrden(NodoB<T> * nodo);
    void preOrden(NodoB<T> * nodo, T info);

    void inOrden();
    void inOrden(NodoB<T> * nodo);

    void postOrden();
    void postOrden(NodoB<T> * nodo);

    template <typename Tn>
    friend std::ostream& operator<<(std::ostream& os, ArbolBinario<Tn> &arbol);

    int nivel(NodoB<T> * nodo);

    NodoB<T> * suma_ineficiente();
    NodoB<T> * suma_ineficiente(NodoB<T> * nodo);
    T suma();
    T suma_eficiente(NodoB<T> * nodo);
    void suma_eficiente(NodoB<T> * nodo, NodoB<T> * acumulador);
    T suma(NodoB<T> * nodo);

    NodoB<T> * getPadre(T info);
    void hermanos(NodoB<T> * n1);
    bool sonHermanos(T n1, T n2);
    bool sonHermanos(NodoB<T> * n1, NodoB<T> * n2);

    void primosHermanos(NodoB<T> * nodo, NodoB<T> * raiz);
    void ancestros(NodoB<T> *nodo);

    NodoB<T> * buscar (T info);
    NodoB<T> * buscar (T info, NodoB<T> * nodo);
};

template <class T>
ArbolBinario<T>::ArbolBinario() { }

template <class T>
ArbolBinario<T>::ArbolBinario(NodoB<T> * info) {
    raiz = info;
}

template <class T>
ArbolBinario<T>::~ArbolBinario() {
    clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear() {
    clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear(NodoB<T> * nodo) {
    if (nodo) {
        clear(nodo->getIzquierdo());
        clear(nodo->getDerecho());

        // Liberar el nodo
        delete nodo;
    }
}

template <class T>
bool ArbolBinario<T>::empty() {
    return (raiz == nullptr);
}

template <class T>
NodoB<T> * ArbolBinario<T>::getRaiz() {
    return raiz;
}

template <class T>
bool ArbolBinario<T>::insert(T value, NodoB<T> * padre) {
    // Insertar la raiz
    if (!padre)
        raiz = new NodoB<T>(value);
    else {
        if (!padre->getIzquierdo()) {
            NodoB<T> * nuevo = new NodoB<T>(value);
            nuevo->setPadre(padre);
            padre->setIzquierdo(nuevo);
        }
        else if (!padre->getDerecho()) {
            NodoB<T> * nuevo = new NodoB<T>(value);
            nuevo->setPadre(padre);
            padre->setDerecho(nuevo);
        }
        else
            return false;
    }
    return true;
}

template <class T>
void ArbolBinario<T>::preOrden() {
    preOrden(raiz);
}
//this used to be
template <class T>
void ArbolBinario<T>::preOrden(NodoB<T> * nodo) {
    if (nodo) {
        std::cout << *nodo << std::endl;
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::preOrden(NodoB<T> * nodo, T info) {
    if (nodo) {
        if (!(nodo->getInfo() == info))
            std::cout << *nodo->getInfo() << std::endl;
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::inOrden() {
    inOrden(raiz);
}

template <class T>
void ArbolBinario<T>::inOrden(NodoB<T> * nodo) {
    if (nodo) {
        inOrden(nodo->getIzquierdo());
        std::cout << *nodo << " " <<nodo->getColor()<<" ";
        inOrden(nodo->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::postOrden() {
    postOrden(raiz);
}

template <class T>
void ArbolBinario<T>::postOrden(NodoB<T> * nodo) {
    if (nodo) {
        postOrden(nodo->getIzquierdo());
        postOrden(nodo->getDerecho());
        std::cout << *nodo << " ";
    }
}

template <class T>
int ArbolBinario<T>::nivel(NodoB<T> *nodo) {
    if (nodo == nullptr)
        return 0;

    NodoB<T> * aux = nodo;
    int nivel = 1;
    while (aux->getPadre()) {
        ++nivel;
        aux = aux->getPadre();
    }
    return nivel;
}


template <class T>
NodoB<T> * ArbolBinario<T>::buscar(T info)
{
    return buscar(info, raiz);
}

template <class T>
NodoB<T> * ArbolBinario<T>::buscar(T info, NodoB<T> * node)
{
//    NodoB<T> * encontrado = nullptr;
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
NodoB<T> * ArbolBinario<T>::getPadre(T info) {
    NodoB<T> * nodo = buscar(info);
    return nodo->getPadre();
}

template <class T>
void ArbolBinario<T>::hermanos(NodoB<T> * nodo) {
    NodoB<T> * izquierdo = nodo->getPadre()->getIzquierdo();
    NodoB<T> * derercho = nodo->getPadre()->getDerecho();
    if (izquierdo && izquierdo != nodo)
        std::cout << *izquierdo->getInfo();
    if (derercho && derercho != nodo)
        std::cout << *derercho->getInfo();
}

template <class T>
bool ArbolBinario<T>::sonHermanos(T n1, T n2) {
    return sonHermanos(buscar(n1), buscar(n2));
}

template <class T>
bool ArbolBinario<T>::sonHermanos(NodoB<T> * n1, NodoB<T> * n2) {
    if (n1 == nullptr || n2 == nullptr || n1 == n2)
        return false;
    return (n1->getPadre() == n2->getPadre());
}

template <class T>
void ArbolBinario<T>::primosHermanos(NodoB<T> *nodo, NodoB<T> *raiz) {
    if (raiz) {
        if (nivel(nodo) == nivel(raiz) && sonHermanos(nodo->getPadre(), raiz->getPadre())) {
            std::cout << *raiz->getInfo() << std::endl;
        }
        primosHermanos(nodo, raiz->getIzquierdo());
        primosHermanos(nodo, raiz->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::ancestros(NodoB<T> *nodo) {
    NodoB<T> * padre = nodo->getPadre();
    while (padre) {
        std::cout << *padre->getInfo() << std::endl;
        padre = padre->getPadre();
    }
}

template <class T>
NodoB<T> * ArbolBinario<T>::suma_ineficiente() {
    return suma_ineficiente(raiz);
}

template <class T>
NodoB<T> * ArbolBinario<T>::suma_ineficiente(NodoB<T> * nodo) {
    T valor;
    if (nodo) {
        valor = nodo->getInfo();
        NodoB<T> * suma_ineficiente_izq = suma_ineficiente(nodo->getIzquierdo());
        if (suma_ineficiente_izq) {
            valor += suma_ineficiente_izq->getInfo();
            delete suma_ineficiente_izq;
        }

        NodoB<T> * suma_ineficiente_der = suma_ineficiente(nodo->getDerecho());
        if (suma_ineficiente_der) {
            valor += suma_ineficiente_der->getInfo();
            delete suma_ineficiente_der;
        }
        return new NodoB<T>(valor);
    }
    return nullptr;
}

template <class T>
T ArbolBinario<T>::suma_eficiente(NodoB<T> * nodo) {
    NodoB<T> * acumulador = new NodoB<T>(0);
    suma_eficiente(nodo, acumulador);
    T valor = acumulador->getInfo();
    delete acumulador;
    return valor;
}

template <class T>
void ArbolBinario<T>::suma_eficiente(NodoB<T> * nodo, NodoB<T> * acumulador) {
    if (nodo) {
        acumulador->setInfo(acumulador->getInfo() + nodo->getInfo());
        suma_eficiente(nodo->getIzquierdo(), acumulador);
        suma_eficiente(nodo->getDerecho(), acumulador);
    }
}

template <class T>
T ArbolBinario<T>::suma() {
    return suma(raiz);
}

template <class T>
T ArbolBinario<T>::suma(NodoB<T> *nodo) {
    static T valor;
    if (nodo) {
        valor += nodo->getInfo();
        suma(nodo->getIzquierdo());
        suma(nodo->getDerecho());
    }
    return valor;
}

template <class T>
std::ostream& ArbolBinario<T>::imprime(std::ostream& os, NodoB<T> * nodo) {
    if (nodo) {
        os << *nodo;
        imprime(os, nodo->getIzquierdo());
        imprime(os, nodo->getDerecho());
    }
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, ArbolBinario<T> &arbol) {
    return arbol.imprime(os, arbol.raiz);
}
