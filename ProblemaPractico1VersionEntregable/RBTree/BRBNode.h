#include <iostream>

template <class T> class BRBNode;
template <class T>
std::ostream& operator<<(std::ostream&, BRBNode<T>&);

template <class T>
class BRBNode {
    T info;
    BRBNode<T> * derecho;
    BRBNode<T> * izquierdo;
    BRBNode<T> * padre;

    int bfactor = 0;
    int niv;

    std::string color;

public:
    BRBNode();
    BRBNode(T info);
    ~BRBNode();

    T getInfo();
    void setInfo(T value);

    BRBNode<T> * getDerecho();
    void setDerecho(BRBNode<T> * value);

    BRBNode<T> * getIzquierdo();
    void setIzquierdo(BRBNode<T> * value);

    BRBNode<T> * getPadre();
    void setPadre(BRBNode<T> * value);

    friend std::ostream& operator<< <>(std::ostream&, BRBNode<T>&);

    void setNivel(int n);
    void setBFactor(int b);

    int getNivel();
    int getBFactor();

    void setColor(std::string color);
    std::string getColor();
};

template <class T>
BRBNode<T>::BRBNode() {
    this->izquierdo = this->derecho = this->padre = nullptr;
}

template <class T>
BRBNode<T>::BRBNode(T info) : info(info) {
    this->derecho = this->izquierdo = this->padre = nullptr;
}

template <class T>
BRBNode<T>::~BRBNode() {
    izquierdo = derecho = padre = nullptr;
}

template <class T>
T BRBNode<T>::getInfo() {
    return info;
}

template <class T>
void BRBNode<T>::setInfo(T value) {
    info = value;
}

template <class T>
BRBNode<T> * BRBNode<T>::getDerecho() {
    return derecho;
}

template <class T>
void BRBNode<T>::setDerecho(BRBNode<T> * value) {
    derecho = value;
}

template <class T>
BRBNode<T> * BRBNode<T>::getIzquierdo() {
    return izquierdo;
}

template <class T>
void BRBNode<T>::setIzquierdo(BRBNode<T> * value) {
    izquierdo = value;
}

template <class T>
BRBNode<T> * BRBNode<T>::getPadre() {
    return padre;
}

template <class T>
void BRBNode<T>::setPadre(BRBNode<T> * value) {
    padre = value;
}

template <class T>
std::ostream& operator <<(std::ostream& os, BRBNode<T>& BRBNode) {
    os << BRBNode.info;
    return os;
}

template <class T>
void BRBNode<T>::setNivel(int n)
{
    niv = n;
}

template <class T>
int BRBNode<T>::getNivel()
{
    return niv;
}

template <class T>
void BRBNode<T>::setBFactor(int b)
{
    bfactor = b;
}

template <class T>
int BRBNode<T>::getBFactor()
{
    return bfactor;
}

template <class T>
void BRBNode<T>::setColor(std::string color)
{
    this->color = color;
}

template <class T>
std::string BRBNode<T>::getColor()
{
    return color;
}
