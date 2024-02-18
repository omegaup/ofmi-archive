#include <iostream>

const int MAX_N = 1000000;

int n;
int A[MAX_N];
int T[MAX_N];

long long res[MAX_N];

// Devuelve el valor de la suma contigua en el rango [i, j],
// o 0 si [i, j] no es un rango continuo.
long long sumaRango(int i, int j) {
  long long sum = 0;
  for (; i <= j; i++) {
    if (A[i] == -1) return 0;
    sum += (long long)A[i];
  }
  return sum;
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> T[i];
  }

  // Procesamos todas los clavados
  for (int k = 0; k < n; k++) {
    // Se echa un clavado la persona correspondiente
    A[T[k]] = -1;
    long long maxContSum = 0;

    // Buscamos la suma contigua máxima iterando sobre todos los
    // posibles rangos.
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        maxContSum = std::max(maxContSum, sumaRango(i, j));
      }
    }

    std::cout << maxContSum << "\n";
  }
  return 0;
}
