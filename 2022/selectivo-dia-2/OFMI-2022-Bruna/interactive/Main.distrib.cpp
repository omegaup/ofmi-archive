#include <iostream>

#include "bruna.h"

int main() {
  int N, Q;

  std::cin >> N >> Q;
  std::cout << "El entero N es " << N << std::endl;
  std::cout << "El entero Q es " << Q << std::endl;
  int mama[N];
  std::cout << "El arreglo de mamás es:";
  for (int i = 0; i < N; i++) {
    std::cin >> mama[i];
    std::cout << " " << mama[i];
  }
  std::cout << std::endl;

  // Inicializar en ambos lados
  std::cout << "Mandando a llamar tu función familiaBruna()" << std::endl;
  familiaBruna(N, mama);

  for (int i = 0; i < Q; i++) {
    int op, idx, X;
    std::cin >> op >> idx;
    if (op == 1) {
      // Depositar
      std::cin >> X;
      // Depositar en ambos lados
      std::cout << "Mandando a llamar tu función depositarDinero(i=" << idx
                << ", X=" << X << ")" << std::endl;
      depositarDinero(idx, X);
    } else {
      // Checar cuenta
      std::cout << "Mandando a llamar tu función checarCuenta(i=" << idx << ")"
                << std::endl;
      std::cout << "regresó: " << checarCuenta(idx) << std::endl;
    }
  }

  return 0;
}
