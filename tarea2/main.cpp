/*
Margot Duek
Tarea 2
Analisis y diseño de algoritmos
*/

#include <iostream>
#include <chrono>
#include <vector>
#include <ctime>
#include <cstring>
#include <climits>

void swap( int& a, int& b );
void findMinMax( int* arr, int len, int& mi, int& mx );
void mismoArreglo(int a[], int b[], int n);

void burbuja(int v[], int n);
void cocktail(int arr[], int n);
void insercion(int v[], int n);
void bucket(int v[], const int n);
void counting(int arr[],int len);
void mergeSort(int v[], int l, int n, int N);
void seleccion(int v[], int n);
void quicksort(int v[], int primero, int ultimo);
void heap(int a[], int n);
  void BUILD_MAX_HEAP(int a[], int n);
  void MAX_HEAPIFY(int a[], int i, int n);
void radix(int v[], int N);
  int getMax(int v[], int N);
  void countSort(int v[], int N, int exp);
void shell(int v[], int N);
void binarySort(int a[], int N);

int main(){
  int n =  10000;
  int A[n] , B[n];
  for(int i = 0; i < n; ++i){
    A[i] = rand() % 100;
    B[i] = A[i];
  }

  //Burbuja
  auto start = std::chrono::high_resolution_clock::now();
  burbuja(A, n);
  auto end = std::chrono::high_resolution_clock::now();
  auto burbjaCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Burbuja:  " << burbjaCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Cocktail
  start = std::chrono::high_resolution_clock::now();
  cocktail(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto coctailCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Cocktail:  " << coctailCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Insercion
  start = std::chrono::high_resolution_clock::now();
  insercion(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto incersionCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Insercion:  " << incersionCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //counting
  start = std::chrono::high_resolution_clock::now();
  counting(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto countingCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Counting:  " << countingCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Bucket
  start = std::chrono::high_resolution_clock::now();
  bucket(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto bucketCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Bucket:  " << bucketCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Merge
  start = std::chrono::high_resolution_clock::now();
  mergeSort(A, 0, n-1, n);
  end = std::chrono::high_resolution_clock::now();
  auto mergeCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Merge:  " << mergeCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Selection
  start = std::chrono::high_resolution_clock::now();
  seleccion(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto selCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Selection:  " << selCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //quick
  start = std::chrono::high_resolution_clock::now();
  quicksort(A, 0, n-1);
  end = std::chrono::high_resolution_clock::now();
  auto qCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Quick:  " << qCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //heap
  start = std::chrono::high_resolution_clock::now();
  heap(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto heapCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Heap:  " << heapCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Radix
  start = std::chrono::high_resolution_clock::now();
  radix(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto radixCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Radix:  " << radixCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Shell
  start = std::chrono::high_resolution_clock::now();
  shell(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto shellCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Shell:  " << shellCount.count() << std::endl;
  mismoArreglo(A, B, n);

  //Binary
  start = std::chrono::high_resolution_clock::now();
  binarySort(A, n);
  end = std::chrono::high_resolution_clock::now();
  auto bTCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Binary:  " << bTCount.count() << std::endl;
  mismoArreglo(A, B, n);

  /*
  for(int i = 0; i < n; ++i){
    std::cout << A[i] << std::endl;
  }
  */

  return 0;
}

/*
bubble sort es un algoritmo en el que recorre toda la lista y compara uno con el
  siguiente hasta que esta acomodada la lista
*/
void burbuja(int v[], int n){
  for (int i = 0; i < n; i++){
    for (int j = n-1; j > i; j--){
      if (v[j-1] > v[j]){
        swap(v[j-1], v[j]);
      }
    }
  }
}

/*
Cocktail sort o burbuja vidireccional hace lo mismo que el de burbuja pero para
  atrás y para adelante, para que en la primer ronda, no solo el primer elemento
  esté acomodado, sino primero y ultimo, aunque su complejudad teorica sigue
  siendo O(n²) su tiempo de ejecucion es menor.
*/
void cocktail(int arr[], int len){
  bool notSorted = true;
  	while( notSorted ){
	    notSorted = false;
	    for( int i = 0; i < len - 1; i++ ){
  		    if( arr[i] > arr[i + 1] ){
    		    swap( arr[i], arr[i + 1] );
    		    notSorted = true;
  		    }
  	   }

  	   if( !notSorted ) break;
  	    notSorted = false;

  	   for( int i = len - 1; i > 0; i-- ){
    	    if( arr[i - 1] > arr[i] ){
    		    swap( arr[i], arr[i - 1] );
    		    notSorted = true;
          }
  	   }
  	}
}

/*
Insercion lo que hace es tomar un elemento y buscar si posicion exacta comparando
  con cada uno de los elemntos de la lista
*/
void insercion(int v[], int n){
  int index;
  for (int i = 1; i < n; i++){
    index = v[i];
    int j = i-1;
    while (j >= 0 && v[j] > index){
      v[j + 1] = v[j];
      j--;
    }
    v[j+1] = index;
  }
}

/*
El ordenamiento por casilleros lo que hace es dividir la lista en cajitas con
  diferentes intervalos de numeros y cada cajita la puedes ordenar como quieras,
  est ealgoritmo tiene un acomplejidad de O(n)
*/
void bucket(int v[], const int n){
  int m = 1001;
  int cas[m];
  for(int i = 0; i < m ; i++){
    cas[i] = 0;
  }
  for(int i = 0; i < n ; ++i){
    ++cas[v[i]];
  }
  for (int i = 0, j = 0; j < m; ++j){
    for (int k = cas[j]; k > 0; --k){
      v[i++] = j;
    }
  }
}

/*
Counting Sort busca el numero mayor y el menor y cuenta cuanos elementos existen
de cada numero
*/
void counting(int arr[],int len){
  int mi, mx, z = 0;
  findMinMax( arr, len, mi, mx );
  int nlen = ( mx - mi ) + 1;
  int* temp = new int[nlen];
  memset( temp, 0, nlen * sizeof( int ));
  for( int i = 0; i < len; i++ ) temp[arr[i] - mi]++;
  for( int i = mi; i <= mx; i++ ){
    while( temp[i - mi] ){
      arr[z++] = i;
      temp[i - mi]--;
    }
  }
  delete [] temp;
}

/*
Merge Sort va dividiendo en mitades los arreglos recursivamente
*/
void merge(int v[], int l, int m, int n, int N){
    int i, j, k;
    int aux[N];   //Vector auxiliar
    for(i=m+1;i>l;i--)
        aux[i-1] = v[i-1];
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    for(k=l;k<=n;k++)       //Mezcla
        if (!(aux[i]> aux[j])) // <
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}
void mergeSort(int v[], int l, int n, int N){
    int m = (n+l)/2;
    if (n > l){
        mergeSort (v, l, m, N);
        mergeSort (v, m+1, n, N);
        merge (v, l, m, n, N);
    }
}

/*
Binary tree Sort
*/
struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int n) {
      val = n;
      left = right = nullptr;
  }

  static void destroy(Node* node) {
      if (node) {
          destroy(node->left);
          destroy(node->right);
          delete node;
      }
  }
};
void insert(Node*& node, int val){
  if (!node)
      node = new Node(val);
  else if (val < node->val)
      insert(node->left, val);
  else
      insert(node->right, val);
}
void inOrder(Node* node, std::vector<int>& a){
  if (node) {
      inOrder(node->left, a);
      a.push_back(node->val);
      inOrder(node->right, a);
  }
}
void binarySort(int a[], int N){
  Node* root = nullptr;
  for (int i = 0; i < N; ++i)
      insert(root, a[i]);

  std::vector<int> aux;
  inOrder(root, aux);

  Node::destroy(root);

  for (int i = 0; i < aux.size(); ++i)
      a[i] = aux[i];
}

/*
Radix Sort ordena de atras para adelante y en numeros binarios, osea si esta el
  25 primero revisa el 5 y luego el 2, entonces el 25 lo pone en la casilla del
  5 y luego revisa el 2
*/
int getMax(int v[], int N){
  int max = v[0];
  for(int i=1; i<N; i++){
    if(v[i]>max){
      max = v[i];
    }
  }
  return max;
}
void countSort(int v[], int N, int exp){
  int output[N];
  int count[10] = {0};
  for(int i=0; i<N; i++){
    count[(v[i]/exp)%10]++;
  }
  for(int i=1; i<10;i++){
    count[i]+=count[i-1];
  }
  for (int i = N-1; i>=0; i--){
    output[count[( v[i]/exp ) %10 ] -1] = v[i];
    count[(v[i]/exp)%10]--;
  }
  for(int i=0;i<N; i++){
    v[i]=output[i];
  }
}
void radix(int v[], int N){
  int m = getMax(v, N);
  for(int exp = 1; m/exp>0; exp*=10){
      countSort(v, N, exp);
  }
}

/*
Shell Sort, el metodo es muy similar al ordenamiento por insercion, pero en vez
  de ordenar todos al mismo tiempo, lo vivide en columnas y ordena cada una
*/
void shell(int v[], int N){
  int temp;
  for(int gap= N/2; gap>0; gap/=2){
    for(int i=gap; i<N; i++){
      for(int j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
        temp = v[j];
        v[j]= v[j+gap];
        v[j+gap] = temp;
      }
    }
  }
}

/*
Selection Sort busca el minimo de la lista y lo compara con el primero
*/
void seleccion(int v[], int n){
    int minimo = 0;
    int temp;

    for(int i = 0; i < n-1; i++){
        minimo = i;
        for(int j = i + 1; j < n; j++){
            if (v[minimo] > v[j])
                minimo = j;
        }
        temp = v[minimo];
        v[minimo] = v[i];
        v[i] = temp;
    }
}

/*
Heap Sort se basa en montículos(Monticulo es un arbol en el que todos los hijos
  de un nodo son menores a el) y va sacando nodo por nodo para que quede ordenado
*/
void MAX_HEAPIFY(int a[], int i, int n){
  int l,r,largest,loc;
  l=2*i;
  r=(2*i+1);
  if((l<=n)&&a[l]>a[i])
    largest=l;
  else
   largest=i;
  if((r<=n)&&(a[r]>a[largest]))
   largest=r;
  if(largest!=i){
   loc=a[i];
   a[i]=a[largest];
   a[largest]=loc;
   MAX_HEAPIFY(a, largest,n);
  }
}
void BUILD_MAX_HEAP(int a[], int n){
  for(int k = n/2; k >= 1; k--){
    MAX_HEAPIFY(a, k, n);
  }
}
void heap(int a[], int n){
  BUILD_MAX_HEAP(a,n);
  int i, temp;
  for (i = n; i >= 2; i--){
      temp = a[i];
      a[i] = a[1];
      a[1] = temp;
      MAX_HEAPIFY(a, 1, i - 1);
  }
}

/*
Quick Sort divide el arreglo en 2 y pone un valor en medio llamado el pivote
  y de ahi ya empezamos a ordenar en base a ese pivotey vaos subdividiendo las
  listas de manera recursiva
*/
void quicksort(int v[], int primero, int ultimo){
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    //Se selecciona pivote
    int pivote = v[primero];

    if ( primero < ultimo){ // Paso base
        // particion
        while ( izquierdo < derecho){
            while ( (izquierdo < derecho) && !(v[izquierdo] > pivote)) izquierdo++; // <=
            while ( v[derecho] > pivote ) derecho--; // >
            if ( izquierdo < derecho){ // se intercambian los contenidos
                temp = v[derecho];
                v[derecho] = v[izquierdo];
                v[izquierdo] = temp;
            }
        }
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = v[derecho];
        v[derecho] = v[primero];
        v[primero] = temp;

        // Paso recursivo
        quicksort ( v, primero, derecho-1);
        quicksort ( v, izquierdo, ultimo);
    }
}


void findMinMax( int* arr, int len, int& mi, int& mx ){
  mi = INT_MAX; mx = 0;
  for( int i = 0; i < len; i++ ){
    if( arr[i] > mx ) mx = arr[i];
    if( arr[i] < mi ) mi = arr[i];
  }
}

/*
Agiliza movimientos
*/
void swap( int& a, int& b ){
  int t = a;
  a = b;
  b = t;
}

void mismoArreglo(int a[], int b[], int n){
  for(int i = 0; i < n; i++){
    a[i] = b[i];
  }
}
/*
Bibliografía
  cocktail --> http://rosettacode.org/wiki/Sorting_algorithms/Cocktail_sort#C.2B.2B
  heap --> http://www.coders-hub.com/2015/02/heap-sort-using-c.html#.VecDhK3Il4s
*/
