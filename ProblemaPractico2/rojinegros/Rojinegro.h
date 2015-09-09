#include <iostream>


struct node{
  int red;
  int data;
  struct node *link[2];
};

struct tree{
  struct node *root;
};

/*Esta funcion solo crea el nodo: */
struct node *make_node(int data){
  /*Crea un nodo con malloc para poder usar memoria dinámica sin preocuparnos
  de liberar esa memoria después*/
  struct node *rn = (rn*)malloc(sizeof (*rn));
  if (rn != NULL){
    rn->data = data;
    rn->red = 1; /* 1 is red, 0 is black */
    rn->link[0] = NULL;
    rn->link[1] = NULL;
  }
  return rn;
}

/*Inserción del nodo*/
struct node *insert(struct node *root, int data){
  if (root == NULL){
    /*Si el árbol está vacio crea un nuevo nodo*/
    root = make_node(data);
  }
  else{
    /*La variable dir lo que hace es ver si el nuevo dato es mayor al nodo, si
    si es entonces dir es 1 y lo pone en el link derecho porque link es un arreglo
    donde 0 es izquierda y 1 es derecha*/
    int dir = root->data < data;
    root->link[dir] = insert(root->link[dir], data);
  }
  return root;
}

/*Una funcion simple para saber si el nodo es rojo*/
int is_red(struct node *root){
    return root != NULL && root->red == 1;
}

/*Rotacón simple*/
struct node *single(struct node *root, int dir){
    /*intercambia de pouct node *root, int dir){
    /*intercambia de posicion los valores*/
    struct node *save = root->link[!dir];
    root->link[!dir] = save->link[dir];
    save->link[dir] = root;
    /*Cambia la bandera de red*/
    root->red = 1;
    save->red = 0;
    return save;
}

struct node * rDouble(struct node *root, int dir){
    root->link[!dir] = single(root->link[!dir], !dir);
    return single(root, dir);
}



/*
Muchas veces el árbol rojinegro parece estar bien con árboles chicos o medianos,
pero generalmente cuando le metemos arreglos más grandes empiezan a existir
violaciones a las reglas de los árboles rojinegros.
Esta función no es optima, pero como solo la usaremos para probar, no pasa nada.
*/
int assert(struct node *root){
  /*Estas variables son para las funciones recursivas, para poder ver el valor
  anterior y el que arroja la función recursiva*/
  int lh, rh;
  /*Si el árbol está vacio, se sale de la función ya que estamos seguros que no
  viola ninguna regla.*/
  if (root == NULL){
    return 1;
  }
  /*ln = left node
    rn = right node*/
  else{
    struct node *ln = root->link[0];
    struct node *rn = root->link[1];

    /* Ya que un nodo rojo no puede seguir de otro nodo rojo, vamos a comprobar
    que no siga uno de otro */
    if (is_red(root)){
      if (is_red(ln) || is_red(rn)){
        puts("Red violation");
        return 0;
      }
    }

    lh = assert(ln);
    rh = assert(rn);

    /*
    Revisa que las condiciones del árbol binario sean correctas, en la primera
    condicion revisa que el nodo izquierdo no este vacio, si no esta vacio, revisa
    que sea menor que su padre, OR lo mismo pero con el nodo derecho
    */
    if ((ln != NULL && ln->data >= root->data) || (rn != NULL && rn->data <= root->data)){
      puts("Binary tree violation");
      return 0;
    }

    /* Revisa que la altura de los nodos negros sea correcta, y que su valor de
    altura (-1 , 0 , 1) este en el rango correcto */
    if (lh != 0 && rh != 0 && lh != rh){
      puts("Black violation");
      return 0;
    }

    /* Only count black links */
    if (lh != 0 && rh != 0){
      return is_red(root) ? lh : lh + 1;
    }
    else{
      return 0;
    }
  }
}


/*
  Los árboles rojinegros son un desastre:
    Si metes un nodo negro, es seguro que va a ser un error y tendrias que
      pasarte todo el algoritmo de insercion tratando de solucionar la violacion
      a la regla de los nodos negros.
    Si metes un nodo rojo existe la posibilidad de que el nodo no viole ninguna
      regla, aunque es podible que si la viole, es mayor la posibilidad de que
      el rojo sea correcto a que el negro lo sea.
  Así que en la función de inserción vamos a poner el nodo rojo y en caso de
  tener problemas lo convertiremos en negro.
*/

/*
Ahora tenemos que ver si existen problemas con los rojos para arreglarlos:
  - Si los dos hijos son rojos, cambiamos el color, el padre se vuelve rojo y los
    hijos negros.
  - Tenemos que ver si hay un rojo y otro negro se tiene que rotar, porque cada
    nodo rojo debe tener dos nodos hijos negros
*/
struct node *insert_r(struct node *root, int data){
  /*Si el árbol esta vacio, crea la raíz (como es una función recursiva, cada
  vez que la funcion se vuelve a llamar, la raíz es un hijo)*/
  if (root == NULL){
    root = make_node(data);
  }
  /*Revisa si el nuevo contenido sea diferente de la raiz*/
  else if (data != root->data){
    /*Revisa si es mayor o menor, si es mayor, da 1 si no, 0*/
    int dir = root->data < data;
    /*0 es izquierda, 1 es derecha */
    root->link[dir] = insert_r(root->link[dir], data);

    /* Ya insertado el nodo se debe rebalancear el árbol */
    if (is_red(root->link[dir])){
      if (is_red(root->link[!dir])){
        /* El primer caso: que los dos hijos sean rojos, entonces al papá le
        ponemos color rojo y a los hijos negro */
        root->red = 1;
        root->link[0]->red = 0;
        root->link[1]->red = 0;
      }else{
        /* En el segundo caso, de que hay uno negro y uno rojo*/
        if (is_red(root->link[dir]->link[dir])){
          /*si el de la derecha de la derecha es rojo, es rotación simple*/
          root = single(root, !dir);
        }else if (is_red(root->link[dir]->link[!dir])){
          /*Si el de la izquierda de la derecha es rojo, es rotacón doble*/
          root = rDouble(root, !dir);
        }
      }
    }
  }
  return root;
}

int insert(struct tree *tree, int data){
  tree->root = insert_r(tree->root, data);
  tree->root->red = 0;

  return 1;
}
