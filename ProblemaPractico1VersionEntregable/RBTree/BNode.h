#include <iostream>

template <class T> class BNode;
template <class T>
std::ostream& operator<<(std::ostream&, BNode<T>&);

template <class T>
class BNode {
    T info;
    BNode<T> * derecho;
    BNode<T> * izquierdo;
    BNode<T> * padre;

    int bfactor = 0;
    int niv;

    std::string color;

public:
    BNode();
    BNode(T info);
    ~BNode();

    T getInfo();
    void setInfo(T value);

    BNode<T> * getDerecho();
    void setDerecho(BNode<T> * value);

    BNode<T> * getIzquierdo();
    void setIzquierdo(BNode<T> * value);

    BNode<T> * getPadre();
    void setPadre(BNode<T> * value);

    friend std::ostream& operator<< <>(std::ostream&, BNode<T>&);

    void setNivel(int n);
    void setBFactor(int b);

    int getNivel();
    int getBFactor();

    void setColor(std::string color);
    std::string getColor();
};

template <class T>
BNode<T>::BNode() {
    this->izquierdo = this->derecho = this->padre = nullptr;
}

template <class T>
BNode<T>::BNode(T info) : info(info) {
    this->derecho = this->izquierdo = this->padre = nullptr;
}

template <class T>
BNode<T>::~BNode() {
    izquierdo = derecho = padre = nullptr;
}

template <class T>
T BNode<T>::getInfo() {
    return info;
}

template <class T>
void BNode<T>::setInfo(T value) {
    info = value;
}

template <class T>
BNode<T> * BNode<T>::getDerecho() {
    return derecho;
}

template <class T>
void BNode<T>::setDerecho(BNode<T> * value) {
    derecho = value;
}

template <class T>
BNode<T> * BNode<T>::getIzquierdo() {
    return izquierdo;
}

template <class T>
void BNode<T>::setIzquierdo(BNode<T> * value) {
    izquierdo = value;
}

template <class T>
BNode<T> * BNode<T>::getPadre() {
    return padre;
}

template <class T>
void BNode<T>::setPadre(BNode<T> * value) {
    padre = value;
}

template <class T>
std::ostream& operator <<(std::ostream& os, BNode<T>& BNode) {
    os << BNode.info;
    return os;
}

template <class T>
void BNode<T>::setNivel(int n)
{
    niv = n;
}

template <class T>
int BNode<T>::getNivel()
{
    return niv;
}

template <class T>
void BNode<T>::setBFactor(int b)
{
    bfactor = b;
}

template <class T>
int BNode<T>::getBFactor()
{
    return bfactor;
}

template <class T>
void BNode<T>::setColor(std::string color)
{
    this->color = color;
}

template <class T>
std::string BNode<T>::getColor()
{
    return color;
}
