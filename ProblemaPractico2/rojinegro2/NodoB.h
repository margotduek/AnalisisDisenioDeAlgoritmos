
#include <iostream>

template <class T> class NodoB;
template <class T>
std::ostream& operator<<(std::ostream&, NodoB<T>&);

template <class T>
class NodoB {
    T info;
    NodoB<T> * derecho;
    NodoB<T> * izquierdo;
    NodoB<T> * padre;

    int bfactor = 0;
    int niv;

    std::string color;

public:
    NodoB();
    NodoB(T info);
    ~NodoB();

    T getInfo();
    void setInfo(T value);

    NodoB<T> * getDerecho();
    void setDerecho(NodoB<T> * value);

    NodoB<T> * getIzquierdo();
    void setIzquierdo(NodoB<T> * value);

    NodoB<T> * getPadre();
    void setPadre(NodoB<T> * value);

    friend std::ostream& operator<< <>(std::ostream&, NodoB<T>&);

    void setNivel(int n);
    void setBFactor(int b);

    int getNivel();
    int getBFactor();

    void setColor(std::string color);
    std::string getColor();
};

template <class T>
NodoB<T>::NodoB() {
    this->izquierdo = this->derecho = this->padre = nullptr;
}

template <class T>
NodoB<T>::NodoB(T info) : info(info) {
    this->derecho = this->izquierdo = this->padre = nullptr;
}

template <class T>
NodoB<T>::~NodoB() {
    izquierdo = derecho = padre = nullptr;
}

template <class T>
T NodoB<T>::getInfo() {
    return info;
}

template <class T>
void NodoB<T>::setInfo(T value) {
    info = value;
}

template <class T>
NodoB<T> * NodoB<T>::getDerecho() {
    return derecho;
}

template <class T>
void NodoB<T>::setDerecho(NodoB<T> * value) {
    derecho = value;
}

template <class T>
NodoB<T> * NodoB<T>::getIzquierdo() {
    return izquierdo;
}

template <class T>
void NodoB<T>::setIzquierdo(NodoB<T> * value) {
    izquierdo = value;
}

template <class T>
NodoB<T> * NodoB<T>::getPadre() {
    return padre;
}

template <class T>
void NodoB<T>::setPadre(NodoB<T> * value) {
    padre = value;
}

template <class T>
std::ostream& operator <<(std::ostream& os, NodoB<T>& NodoB) {
    os << NodoB.info;
    return os;
}

template <class T>
void NodoB<T>::setNivel(int n)
{
    niv = n;
}

template <class T>
int NodoB<T>::getNivel()
{
    return niv;
}

template <class T>
void NodoB<T>::setBFactor(int b)
{
    bfactor = b;
}

template <class T>
int NodoB<T>::getBFactor()
{
    return bfactor;
}

template <class T>
void NodoB<T>::setColor(std::string color)
{
    this->color = color;
}

template <class T>
std::string NodoB<T>::getColor()
{
    return color;
}
