/*
  Margot Duek
  A01021226
  Análisis y diseño de algoritmos
  - Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia
    de X (siendo k ≤ m) si existe una secuencia creciente {i1 i2 ... ik} de índices de X tales
    que para todo j = 1, 2, ..., k tenemos xij = zj.
    Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es
    subsecuencia de X y subsecuencia de Y.
    Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima
    común a dos secuencias.
*/

#include <string>
#include <iostream>


std::string boyerymio(std::string texto, int n , std::string segundo, int m);
int revisaHastaFrenar(std::string texto, int i, std::string segundo, int j);
std::string textoenIhastaJ(std::string texto, int i, std::string segundo, int j);




int main(){
  std::string nombre = "mi nombre mar es margot";
  std::string secuencia = "margot";
  std:: cout << boyerymio(nombre, nombre.length(), secuencia, secuencia.length()) << std::endl;

  return 0;
}

std::string boyerymio(std::string texto, int n , std::string segundo, int m){
  int j;
  std::string max;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(texto[i] == segundo[j]){
        if(revisaHastaFrenar(texto, i, segundo, j) >= max.length()){
          max = textoenIhastaJ(texto, i, segundo, j);
        }
      }
    }
  }
  if (max == ""){
    return "ninguna coincicencia";
  }else{
    return max;
  }
}

int revisaHastaFrenar(std::string texto, int i, std::string segundo, int j){
  int max = 0;
  while(texto[i] == segundo[j]){
    ++i;
    ++j;
    max++;
  }
  return max;
}

std::string textoenIhastaJ(std::string texto, int i, std::string segundo, int j){
  std::string max = " ";
  while(texto[i] == segundo[j]){
    max += texto[i];
    ++i;
    ++j;
  }
  return max;
}


/*
Input:    Text with n characters and Pattern with m characters
Output: Index of the first substring of T matching P

std::string boyerymoore(std::string T, int n, std::string p, int m ){
  int i = m-1;
  int j = m-1;
  while( i < n-1 ){
    if(p[j] == T[i]){
      if(j==0){
        return i;
      }else{
        i--;
        j--;
      }
    }else{
      i = i + m - min(j, 1 + last[T[i]]);
      j = m - 1;
    }
  }
  return "no match";
}
*/
