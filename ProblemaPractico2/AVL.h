/*
El árbol binario AVL es el primer árbol binario autobalanceable
*/

#include "BinaryTree.h"

template <class T>
class AVL : public BinaryTree<T>{
  private:
    BNode<T> * root = nullptr;
  public:
    AVL() {}
    virtual ~AVL();

    void Equilibrar(BinaryTree *a, BNode nodo, int rama, int nuevo);

};

/* Equilibrar árbol AVL partiendo de un nodo*/
void Equilibrar(BinaryTree *a, BNode nodo, int rama, int nuevo) {
  int salir = FALSE;

  /* Recorrer camino inverso actualizando valores de FE: */
  while(nodo && !salir) {
    if(nuevo)
      if(rama == IZQUIERDO) nodo->FE--; /* Depende de si añadimos ... */
         else                nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; /* ... o borramos */
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = TRUE; /* La altura de las rama que
                                         empieza en nodo no ha variado,
                                         salir de Equilibrar */
      else if(nodo->FE == -2) { /* Rotar a derechas y salir: */
         if(nodo->izquierdo->FE == 1) RDD(a, nodo); /* Rotación doble  */
         else RSD(a, nodo);                         /* Rotación simple */
         salir = TRUE;
      }
      else if(nodo->FE == 2) {  /* Rotar a izquierdas y salir: */
         if(nodo->derecho->FE == -1) RDI(a, nodo); /* Rotación doble  */
         else RSI(a, nodo);                        /* Rotación simple */
         salir = TRUE;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; /* Calcular FE, siguiente nodo del camino. */
   }
}
