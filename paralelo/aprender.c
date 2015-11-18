#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>

#define N 100
int main(int argc, char const *argv[]) {

  int A[N], B[N], S[N];
  int i;

  srand(time(NULL));
  /*inicialización*/
  /* Esto se puede paralelisar */
  #pragma omp parallel private(i)
  {  //Esto fué lo unico que se le agregó para que se paralelize
                        // este for (y solo funciona cin este for)
    /*Para saber cuantos hilos tenemos se pone lo siguiente*/
    printf("Hilo %d de %d \n",
    omp_get_thread_num(),
    omp_get_num_threads());

    for ( i = 0; i < N; i++) {
      A[i] = rand() % 100;
      B[i] = rand() % 100;
      S[i] = 0;
    }
  }

  /* Computo */
  #pragma omp parallel private(i)
  {
    #pragma omp for
    for( i = 0; i < N; i++) {
      S[i] = A[i] + B[i];
    }
  }


  /* Visualizar resulatados */
  for( i = 0; i < N; i++) {
    printf("[%7d] %3d + %3d = %4d \n", i, A[i], B[i], S[i]);
  }

  return 0;
}
