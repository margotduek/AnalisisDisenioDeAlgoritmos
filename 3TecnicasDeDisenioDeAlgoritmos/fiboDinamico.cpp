#include <iostream>
#include <chrono>


int fiboRecursivo(int n);
int fiboNormal(int n);


int main(){
  auto start = std::chrono::high_resolution_clock::now();
  fiboRecursivo(100);
  auto end = std::chrono::high_resolution_clock::now();
  auto e = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Recursivo:  " << e.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  fiboNormal(100);
  end = std::chrono::high_resolution_clock::now();
  auto x = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
  std::cout << "Recursivo:  " << x.count() << std::endl;

  return 0;
}


int fiboNormal(int n){
  int suma, x, y;
  if(n <= 1){
    return 1;
  }
  else{
    x = 1;
    y = 1;
    for(int i = 2; i < n; ++i){
      suma = x + y;
      y = x;
      x = suma;
    }
    return suma;
  }
}

int fiboRecursivo(int n){
  if(n <= 0){
    return 0;
  }if(n == 1){
    return n;
  }else{
    return fiboRecursivo(n - 1) + fiboRecursivo(n - 2);
  }
}
