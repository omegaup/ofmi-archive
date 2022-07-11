#include <iostream>

#include "waves.h"

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << "El entero n es " << n << std::endl;
  std::cout << "El entero k es " << k << std::endl;
  int A[n];
  std::cout << "El arreglo A es:";
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
    std::cout << " " << A[i];
  }
  std::cout << std::endl;
  std::cout << "Tu programa obtuvo " << waves(n, k, A)
            << " caidas en el arreglo.\n";
}
