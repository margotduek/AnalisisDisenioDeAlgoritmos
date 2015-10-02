
#include "ArbolBinarioBusqueda.h"
#include <assert.h>
#include <iomanip>

template<class T>
class Rojinegro : public ArbolBinarioBusqueda<T>{
public:
    Rojinegro();

    NodoB<T> * grandparent(NodoB<T> * nodo);
    NodoB<T> * uncle(NodoB<T> * nodo);
    NodoB<T> * sibling(NodoB<T> * nodo);

    NodoB<T> * maximum_node(NodoB<T> * nodo);

    void verifyProperties(Rojinegro * arbol);
    void revisaa(NodoB<T> * nodo);
    void resab(NodoB<T> * nodo);
    void revisac(NodoB<T> * nodo);
    void revisad(NodoB<T> * root);
    void verifyProperty4Helper(NodoB<T> * nodo, int contNegros, int& blackPath);

    std::string color(NodoB<T> * nodo);

    void rotateLeft(Rojinegro * arbol, NodoB<T> * nodo);
    void rotateRight(Rojinegro * arbol, NodoB<T> * nodo);

    void RBinsert(T valor);
    void insertCase1(Rojinegro * arbol, NodoB<T> * nodo);
    void insertCase2(Rojinegro * arbol, NodoB<T> * nodo);
    void insertCase3(Rojinegro * arbol, NodoB<T> * nodo);
    void insertCase4(Rojinegro * arbol, NodoB<T> * nodo);
    void insertCase5(Rojinegro * arbol, NodoB<T> * nodo);

    void RBdelete(T valor);
    void deleteCase1(Rojinegro * arbol, NodoB<T> * nodo);
    void deleteCase2(Rojinegro * arbol, NodoB<T> * nodo);
    void deleteCase3(Rojinegro * arbol, NodoB<T> * nodo);
    void deleteCase4(Rojinegro * arbol, NodoB<T> * nodo);
    void deleteCase5(Rojinegro * arbol, NodoB<T> * nodo);
    void deleteCase6(Rojinegro * arbol, NodoB<T> * nodo);

    void prettyPrint(NodoB<T>* p, int indent);

    void verificarArbol(Rojinegro<T> * arbol);
};

template<class T>
Rojinegro<T>::Rojinegro() : ArbolBinarioBusqueda<T>() {}

template<class T>
NodoB<T> * Rojinegro<T>::grandparent(NodoB<T> * nodo)
{
    if(nodo != nullptr && nodo->getPadre() != nullptr)
        return nodo->getPadre()->getPadre();
    else
        return nullptr;
}

template<class T>
NodoB<T> * Rojinegro<T>::uncle(NodoB<T> * nodo)
{
    NodoB<T> * abuelo = grandparent(nodo);

    if(abuelo == nullptr)
        return nullptr;
    else if(nodo->getPadre() == abuelo->getIzquierdo())
        return abuelo->getDerecho();
    else
        return abuelo->getIzquierdo();
}

template<class T>
NodoB<T> * Rojinegro<T>::sibling(NodoB<T> * nodo)
{
    if(nodo != nullptr && nodo->getPadre() != nullptr)
    {
        if(nodo == nodo->getPadre()->getIzquierdo())
            return nodo->getPadre()->getDerecho();
        else
            return nodo->getPadre()->getIzquierdo();
    }
    else
        return nullptr;
}

template<class T>
NodoB<T> * Rojinegro<T>::maximum_node(NodoB<T> * nodo)
{
    assert(nodo != nullptr);
    while(nodo->getDerecho() != nullptr)
    {
        nodo = nodo->getDerecho();
    }
    return nodo;
}

template<class T>
void Rojinegro<T>::verifyProperties(Rojinegro * arbol)
{
    revisaa(arbol->getRaiz());
    resab(arbol->getRaiz());
    revisac(arbol->getRaiz());
    revisad(arbol->getRaiz());
}

template<class T>
void Rojinegro<T>::revisaa(NodoB<T> * nodo)
{
    if(nodo == nullptr)
        return;

    assert(nodo->getColor() == "negro" || nodo->getColor() == "rojo");

    revisaa(nodo->getIzquierdo());
    revisaa(nodo->getDerecho());
}

template<class T>
void Rojinegro<T>::resab(NodoB<T> * nodo)
{
    assert(color(nodo) == "negro");
}

template<class T>
void Rojinegro<T>::revisac(NodoB<T> * nodo)
{
    if (nodo == nullptr)
        return;

    if (color(nodo) == "rojo")
    {
        assert(color(nodo->getIzquierdo()) == "negro");
        assert(color(nodo->getDerecho()) == "negro");
        assert(color(nodo->getPadre()) == "negro");
    }

    revisac(nodo->getIzquierdo());
    revisac(nodo->getDerecho());
}

template <class T>
void Rojinegro<T>::revisad(NodoB<T> * root)
{

    int blackPath = -1;
    std::string mensaje="";

    return verifyProperty4Helper(root, 0, blackPath);
}

template <class T>
void Rojinegro<T>::verifyProperty4Helper(NodoB<T> * nodo, int contNegros, int& blackPath)
{
    std::string color;


    if (nodo != nullptr) {
        color = nodo->getColor();
    }
    else{
        color = "";
    }

    if (color == "negro")
    {
        contNegros++;
    }
    if (nodo == nullptr)
    {
        if (blackPath == -1)
        {
            blackPath = contNegros;
        }
        else
        {
            //assert (contNegros == blackPath);
            if (contNegros != blackPath)
            {
                std::cout << "No es Rojinegro" << std::endl;
            }
        }
        return;
    }
    verifyProperty4Helper(nodo->getIzquierdo(),  contNegros, blackPath);
    verifyProperty4Helper(nodo->getDerecho(), contNegros, blackPath);

    return;
}

template<class T>
std::string Rojinegro<T>::color(NodoB<T> * nodo)
{
    if(nodo == nullptr)
        return "negro";
    else
        return nodo->getColor();
}

template<class T>
void Rojinegro<T>::rotateLeft(Rojinegro * arbol, NodoB<T> * nodoX)
{
    NodoB<T> * nodoY;

    if(nodoX->getDerecho() == nullptr)
    {
        return;
    }

    nodoY = nodoX->getDerecho();

    if(nodoY->getIzquierdo() != nullptr)
    {
        nodoY->getIzquierdo()->setPadre(nodoX);
        nodoX->setDerecho(nodoY->getIzquierdo());
    }

    nodoY->setPadre(nodoX->getPadre());

    if(nodoX->getPadre() == nullptr)
    {
        this->setRaiz(nodoY);
    }
    else if(nodoX == nodoX->getPadre()->getIzquierdo())
    {
        nodoX->getPadre()->setIzquierdo(nodoY);
    }
    else
    {
        nodoX->getPadre()->setDerecho(nodoY);
    }

    nodoX->setDerecho(nodoY->getIzquierdo());
    nodoY->setIzquierdo(nodoX);
    nodoX->setPadre(nodoY);//    NodoB<T> * temp = nodo->getDerecho();
    //
    //    if(nodo->getPadre() == nullptr)
    //        arbol->setRaiz(temp);
    //    else if(nodo->getPadre()->getIzquierdo() == nodo)
    //        nodo->getPadre()->setIzquierdo(temp);
    //    else
    //        nodo->getPadre()->setDerecho(temp);
    //
    //    if(temp != nullptr)
    //        temp->setPadre(nodo->getPadre());
    //
    //    nodo->setDerecho(temp->getIzquierdo());
    //
    //    if (temp->getIzquierdo() != nullptr)
    //    {
    //        temp->getIzquierdo()->setPadre(nodo);
    //    }
    //    temp->setIzquierdo(nodo);
    //    nodo->setPadre(temp);
}

template<class T>
void Rojinegro<T>::rotateRight(Rojinegro * arbol, NodoB<T> * nodoY)
{
    NodoB<T> *nodoX;

    if(nodoY->getIzquierdo() == nullptr)
    {
        return;
    }

    nodoX = nodoY->getIzquierdo();

    if(nodoX->getDerecho() != nullptr)
    {
        nodoX->getDerecho()->setPadre(nodoY);
        nodoY->setIzquierdo(nodoX->getDerecho());
    }

    nodoX->setPadre(nodoY->getPadre());

    if(nodoY->getPadre() == nullptr)
    {
        this->setRaiz(nodoX);
    }
    else if(nodoY == nodoY->getPadre()->getIzquierdo())
    {
        nodoY->getPadre()->setIzquierdo(nodoX);
    }
    else
    {
        nodoY->getPadre()->setDerecho(nodoX);
    }

    nodoY->setIzquierdo(nodoX->getDerecho());
    nodoX->setDerecho(nodoY);
    nodoY->setPadre(nodoX);

    //    NodoB<T> * temp = nodo->getIzquierdo();
    //
    //    if(nodo->getPadre() == nullptr)
    //        arbol->setRaiz(temp);
    //    else if(nodo->getPadre()->getIzquierdo() == nodo)
    //        nodo->getPadre()->setIzquierdo(temp);
    //    else
    //        nodo->getPadre()->setDerecho(temp);
    //
    //    if(temp != nullptr)
    //        temp->setPadre(nodo->getPadre());
    //
    //    nodo->setIzquierdo(temp->getDerecho());
    //    if (temp->getDerecho() != nullptr)
    //    {
    //        nodo->getDerecho()->setPadre(nodo);
    //    }
    //    temp->setDerecho(nodo);
    //    nodo->setPadre(temp);
}

template<class T>
void Rojinegro<T>::RBinsert(T valor)
{
    NodoB<T> * nodo = this->insertar(valor);
    nodo->setColor("rojo");
    insertCase1(this, nodo);
    verifyProperties(this);

}

template<class T>
void Rojinegro<T>::insertCase1(Rojinegro * arbol, NodoB<T> * nodo)
{
    if(nodo->getPadre() == nullptr)
        nodo->setColor("negro");
    else
        insertCase2(this, nodo);
}

template<class T>
void Rojinegro<T>::insertCase2(Rojinegro * arbol, NodoB<T> * nodo)
{
    if(nodo->getPadre()->getColor() == "negro")
        return;
    else
        insertCase3(this, nodo);
}

template<class T>
void Rojinegro<T>::insertCase3(Rojinegro * arbol, NodoB<T> * nodo)
{
    if(color(uncle(nodo)) == "rojo")
    {
        nodo->getPadre()->setColor("negro");
        uncle(nodo)->setColor("negro");
        grandparent(nodo)->setColor("rojo");
        insertCase1(arbol, grandparent(nodo));
    }
    else
    {
        insertCase4(arbol, nodo);
    }
}

template<class T>
void Rojinegro<T>::insertCase4(Rojinegro * arbol, NodoB<T> * nodo)
{
    if(nodo == nodo->getPadre()->getDerecho() && nodo->getPadre() == grandparent(nodo)->getIzquierdo())
    {
        rotateLeft(arbol, nodo->getPadre());
        nodo = nodo->getIzquierdo();
    }
    else if(nodo == nodo->getPadre()->getIzquierdo() && nodo->getPadre() == grandparent(nodo)->getDerecho())
    {
        rotateRight(arbol, nodo->getPadre());
        nodo = nodo->getDerecho();
    }
    insertCase5(arbol, nodo);
}

template<class T>
void Rojinegro<T>::insertCase5(Rojinegro * arbol, NodoB<T> * nodo)
{
    nodo->getPadre()->setColor("negro");
    grandparent(nodo)->setColor("rojo");
    if (nodo == nodo->getPadre()->getIzquierdo() && nodo->getPadre() == grandparent(nodo)->getIzquierdo())
    {
        rotateRight(arbol, grandparent(nodo));
    }
    else
    {
        assert(nodo == nodo->getPadre()->getDerecho() && nodo->getPadre() == grandparent(nodo)->getDerecho());
        rotateLeft(arbol, grandparent(nodo));
    }
}

template <class T>
void Rojinegro<T>::RBdelete(T valor)
{
    NodoB<T> * hijo;
    NodoB<T> * nodo;
    nodo = this->buscar(valor);
    if (nodo == nullptr)
        return;

    if (nodo->getIzquierdo() != nullptr && nodo->getDerecho() != nullptr)
    {
        NodoB<T> * pred = maximum_node(nodo->getIzquierdo());
        nodo->setInfo(pred->getInfo());
        nodo = pred;
    }
    assert(nodo->getIzquierdo() == NULL || nodo->getDerecho() == nullptr);
    hijo = nodo->getDerecho() == nullptr ? nodo->getIzquierdo()  : nodo->getDerecho();
    if (color(nodo) == "negro")
    {
        nodo->getColor() = color(hijo);
        deleteCase1(this, nodo);
    }


    if (nodo->getPadre() == nullptr)
    {
        this->setRaiz(hijo);
    }
    else
    {
        if (nodo == nodo->getPadre()->getIzquierdo())
            nodo->getPadre()->setIzquierdo(hijo);
        else
            nodo->getPadre()->setDerecho(hijo);
    }
    if (hijo != nullptr)
    {
        hijo->setPadre(nodo->getPadre());
    }
    delete nodo;
    verifyProperties(this);
}

template <class T>
void Rojinegro<T>::deleteCase1(Rojinegro * arbol, NodoB<T> * nodo)
{
    if(nodo->getPadre() == nullptr)
        return;
    else
        deleteCase2(this, nodo);
}

template <class T>
void Rojinegro<T>::deleteCase2(Rojinegro * arbol, NodoB<T> * nodo)
{
    if (color(sibling(nodo)) == "rojo")
    {
        nodo->getPadre()->setColor("rojo");
        sibling(nodo)->setColor("negro");
        if (nodo == nodo->getPadre()->getIzquierdo())
            rotateLeft(this, nodo->getPadre());
        else
            rotateRight(this, nodo->getPadre());
    }
    deleteCase3(this, nodo);
}

template <class T>
void Rojinegro<T>::deleteCase3(Rojinegro * arbol, NodoB<T> * nodo)
{
    if (color(nodo->getPadre()) == "negro" && color(sibling(nodo)) == "negro" &&
        color(sibling(nodo)->getIzquierdo()) == "negro" && color(sibling(nodo)->getDerecho()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        deleteCase1(this, nodo->getPadre());
    }
    else
        deleteCase4(this, nodo);
}

template <class T>
void Rojinegro<T>::deleteCase4(Rojinegro * arbol, NodoB<T> * nodo)
{
    if (color(nodo->getPadre()) == "rojo" && color(sibling(nodo)) == "negro" &&
        color(sibling(nodo)->getIzquierdo()) == "negro" && color(sibling(nodo)->getDerecho()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        nodo->getPadre()->setColor("negro");
    }
    else
        deleteCase5(this, nodo);
}

template<class T>
void Rojinegro<T>::deleteCase5(Rojinegro * arbol, NodoB<T> * nodo)
{
    if (nodo == nodo->getPadre()->getIzquierdo() && color(sibling(nodo)) == "negro" &&
        color(sibling(nodo)->getIzquierdo()) == "rojo" && color(sibling(nodo)->getDerecho()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        sibling(nodo)->getIzquierdo()->setColor("negro");
        rotateRight(this, sibling(nodo));
    }
    else if (nodo == nodo->getPadre()->getDerecho() && color(sibling(nodo)) == "negro" &&
             color(sibling(nodo)->getDerecho()) == "rojo" && color(sibling(nodo)->getIzquierdo()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        sibling(nodo)->getDerecho()->setColor("negro");
        rotateLeft(this, sibling(nodo));
    }
    deleteCase6(this, nodo);
}

template<class T>
void Rojinegro<T>::deleteCase6(Rojinegro * arbol, NodoB<T> * nodo)
{
    sibling(nodo)->setColor(color(nodo->getPadre()));
    nodo->getPadre()->setColor("negro");
    if (nodo == nodo->getPadre()->getIzquierdo())
    {
        assert(color(sibling(nodo)->getDerecho()) == "rojo");
        sibling(nodo)->getDerecho()->setColor("negro");
        rotateLeft(this, nodo->getPadre());
    }
    else
    {
        assert(color(sibling(nodo)->getIzquierdo()) == "rojo");
        sibling(nodo)->getIzquierdo()->setColor("negro");
        rotateRight(this, nodo->getPadre());
    }
}

template <class T>
void Rojinegro<T>::prettyPrint(NodoB<T>* p, int indent)
{
    if (p != nullptr) {
        if (p->getDerecho()) {
            prettyPrint(p->getDerecho(), indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->getDerecho()) std::cout << " /\n" << std::setw(indent) << ' ';
        std::cout << p->getInfo() << "|" << p->getColor() << "\n ";
        if (p->getIzquierdo()) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            prettyPrint(p->getIzquierdo(), indent + 4);
        }
    }
}

template<class T>
void Rojinegro<T>::verificarArbol(Rojinegro<T> * arbol)
{
    verifyProperties(arbol);
}
