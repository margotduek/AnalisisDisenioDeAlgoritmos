/*
Margot Duek
Tarea 2
Analisis y diseño de algoritmos
*/

#include <iostream>
#include <chrono>
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


int main(){
  int n =  100;
  int A[n] , B[n];
  for(int i = 0; i < n; ++i){
    A[i] = rand() % 10000;
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

  //Merge
  start = std::chrono::high_resolution_clock::now();
  //void mergeSort(int A[], int l, int n, int N);
  end = std::chrono::high_resolution_clock::now();
  auto mergeCount = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Merge:  " << mergeCount.count() << std::endl;
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
  int m = 101;
  int cas[m];
  for(int i = 0; i < m ; i++){
    cas[i] = 0;
  }
  for(int i = 0; i < n ; i++){
    ++cas[v[i]];
  }
  for (int i = 0, j = 0; j < m; ++j){
    for (int k = cas[j]; k > 0; --k){
      v[i++] = j;
    }
  }
  for(int i = 0; i < n; ++i){
    std::cout << v[i] << std::endl;
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
*/

/*
Binary tree Sort
*/

/*
Radix Sort
*/

/*
Shell Sort
*/

/*
Selection Sort
*/

/*
Heap Sort
*/

/*
Quick Sort
*/

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

*/
