#include <cassert>
#include <iostream>

#include "arreglos.h"

bool valido = true;
int llamadas = 0;
int iguales = 0;

const int maxn = 1000001;
int n;
int A[maxn];
int B[maxn];

const int NUM_SUB = 3;
int getSubtask(const std::string& caseName) {
  for (int sub = 1; sub <= NUM_SUB; ++sub) {
    if (caseName.find("sub" + std::to_string(sub)) != std::string::npos) {
      return sub;
    }
  }
  return -1;
}

bool indiceFueraDeRango(int indice) { return indice < 0 || indice >= n; }

bool mueve(int indice, int cantidad, int direccion) {
  llamadas++;

  if (indiceFueraDeRango(indice) || indiceFueraDeRango(indice + direccion)) {
    valido = false;
    return iguales == n;
  }

  int antes = (A[indice] == B[indice]) +
              (A[indice + direccion] == B[indice + direccion]);

  A[indice] -= cantidad;
  A[indice + direccion] += cantidad;

  if (A[indice] < 0 || A[indice + direccion] < 0) {
    valido = false;
    return iguales == n;
  }

  int despues = (A[indice] == B[indice]) +
                (A[indice + direccion] == B[indice + direccion]);

  iguales += despues - antes;

  return iguales == n;
}

int main(int argc, char* argv[]) {
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  int subtask = getSubtask(caseName);

  std::cin >> n;
  assert(0 < n && n <= maxn);

  long long delta = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
    assert(A[i] >= 0);
    delta += A[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> B[i];
    assert(B[i] >= 0);
    delta -= B[i];
    iguales += A[i] == B[i];
  }

  const bool possible = delta == 0;
  const bool contestant_possible = arregla(n, A, B);

  const bool possible_ok = possible == contestant_possible;
  const bool array_ok = !possible || iguales == n;
  const bool calls_ok = subtask != 3 || llamadas < n;

  const bool verdict = valido && possible_ok && array_ok && calls_ok;

  std::cout << (verdict ? "1" : "0") << std::endl;

  std::cerr << "Llamadas: " << llamadas << std::endl
            << "Valido: " << valido << std::endl
            << "Iguales: " << iguales << std::endl
            << "possible_ok: " << possible_ok << std::endl
            << "array_ok: " << array_ok << std::endl
            << "calls_ok: " << calls_ok << std::endl;

  return 0;
}
