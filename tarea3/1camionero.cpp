/*
  Margot Duek
  A01021226
  Análisis y diseño de algoritmos
  - Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un
    camión que le permite, con el tanque de gasolina lleno, recorrer n kilómetros sin parar.
    El camionero dispone de un mapa de carreteras que le indica las distancias entre las
    gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a
    abastecer gasolina el menor número de veces posible.
    Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el
    camionero.
*/


#include <iostream>


void paro(int kmRecorridos, int n, int *gas, int gasolinerias);

int main(){
  /*int distancia = 200;
  int n = 40;
  int numeroDeGasolinerias = 8;
  int gasolinerias[numeroDeGasolinerias] = {25, 36, 55, 73, 99, 124, 159, 180};
*/

  int distancia = 15;
  int n = 3;
  int numeroDeGasolinerias = 8;
  int gasolinerias[numeroDeGasolinerias] = {1, 2, 4, 6, 8, 10, 12, 13};
/*
int distancia = 20;
int n = 5;
int numeroDeGasolinerias = 8;
int gasolinerias[numeroDeGasolinerias] = {1, 2, 3, 5, 7, 11, 15, 19};
*/
  paro(0, n, gasolinerias, numeroDeGasolinerias);

  return 0;
}

void paro(int kmRecorridos, int n, int *gas, int gasolinerias){
  int i = 0;
  int kmRecorridost = 0;
  while(gasolinerias > i){
    if(n-kmRecorridos == (gas[i+1] - gas[i])|| n-1 == (gas[i+1] - gas[i])){
      std::cout << "Pon gasolina en la gas #" << gas[i] << std::endl;
      kmRecorridos = 0;

    }else{
      std::cout << "aguantas una gas más" << std::endl;

    }
    i++;
    kmRecorridos++;
    kmRecorridost++;

  }

}
