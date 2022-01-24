#include <iostream>

int main() {
  // Leemos n
  int n;
  std::cin >> n;
  // Declaramos variables que nos ayudarán con el problema
  int ganador = 0;  // Aquí guardaremos el índice de la cobaya que ganó
  int mejor = 0;    // Guardamos la mejor puja
  int segunda = 0;  // Guardamos la segunda mejor puja
  // Iteramos por cada evento de la subasta
  for (int i = 1; i <= n; i++) {
    // Leemos la puja de la cobaya
    int puja;
    std::cin >> puja;
    if (puja >= mejor + segunda) {
      // Si la puja es mayor o igual a la suma, entonces esta se vuelve la mejor
      // puja y desplaza la mejor puja a la segunda mejor
      segunda = mejor;
      mejor = puja;
      ganador = i;
    }
  }
  // Imprimimos el ganador
  std::cout << ganador << std::endl;
  return 0;
}