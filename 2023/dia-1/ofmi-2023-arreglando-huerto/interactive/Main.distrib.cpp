#include <iostream>

#include "arreglos.h"

bool valido = true;
int llamadas = 0;
int iguales = 0;

int n;
int A[1000001];
int B[1000001];

void imprime(int arr[]) {
  for (int i = 0; i < n; i++) {
    std::cerr << arr[i] << ' ';
  }
  std::cerr << std::endl;
}

bool mueve(int indice, int cantidad, int direccion) {
  std::cerr << "mueve(" << indice << ", " << cantidad << ", " << direccion
            << ")" << std::endl;

  llamadas++;

  if (indice + direccion < 0 || indice + direccion >= n) {
    valido = false;
    return false;
  }

  int antes = (A[indice] == B[indice]) +
              (A[indice + direccion] == B[indice + direccion]);

  A[indice] -= cantidad;
  A[indice + direccion] += cantidad;

  int despues = (A[indice] == B[indice]) +
                (A[indice + direccion] == B[indice + direccion]);

  iguales += despues - antes;

  std::cerr << "Nuevo valor de A[" << indice << "]: " << A[indice] << std::endl;
  std::cerr << "Nuevo valor de A[" << indice + direccion
            << "]: " << A[indice + direccion] << std::endl;

  if (A[indice] < 0 || A[indice + direccion] < 0) {
    valido = false;
    std::cerr << "Se detecto un elemento negativo" << std::endl;
    std::cout << 0;
    exit(0);
  }

  if (iguales == n) {
    std::cerr << "Los arreglos son iguales" << std::endl;
  } else {
    std::cerr << "Los arreglos no son iguales" << std::endl;
  }

  return iguales == n;
}

int main() {
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> B[i];
    iguales = +A[i] == B[i];
  }

  std::cerr << "n: " << n << std::endl;
  std::cerr << "A: ";
  for (int i = 0; i < n; i++) {
    std::cerr << A[i] << ' ';
  }
  std::cerr << std::endl << "B: ";
  for (int i = 0; i < n; i++) {
    std::cerr << B[i] << ' ';
  }
  std::cerr << std::endl;

  bool imposible = arregla(n, A, B);

  std::cerr << "Resultado de arregla: " << imposible << std::endl;

  std::cerr << "Llamadas: " << llamadas << std::endl
            << "Valido: " << valido << std::endl;

  std::cerr << "A: ";
  imprime(A);
  std::cerr << "B: ";
  imprime(B);
  if (iguales == n) {
    std::cerr << "Los arreglos son iguales :)" << std::endl;
  } else {
    std::cerr << "Los arreglos no son iguales :(" << std::endl;
  }
  std::cout << (int)(valido && iguales == n) << std::endl;
  return 0;
}
