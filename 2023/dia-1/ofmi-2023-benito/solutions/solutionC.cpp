#include <iostream>

const int maxn = 1000;

int n;
int matrix[maxn][maxn];

// Devuelve true si todos los elementos en el k-ésimo cuadrado concéntrico (de
// afuera hacia adentro) son iguales a x.
bool cuadrado_concentrico(int k, int x) {
  for (int i = k; i < n - k; ++i) {
    if (matrix[k][i] != x || matrix[n - k - 1][i] != x || matrix[i][k] != x ||
        matrix[i][n - k - 1] != x) {
      return false;
    }
  }
  return true;
}

// Verifica si la matriz es espiral. Devuelve el máximo número en caso
// afirmativo o -1 en caso contrario.
int es_espiral() {
  int max_numero = (n + 1) / 2;
  for (int k = 0; k < max_numero; ++k) {
    // Los números van 1, 2, ... de afuera hacia adentro.
    if (matrix[0][0] == 1) {
      if (!cuadrado_concentrico(k, k + 1)) {
        return -1;
      }
    }
    // Los números van 1, 2, ... de adentro hacia afuera.
    else {
      if (!cuadrado_concentrico(k, max_numero - k)) {
        return -1;
      }
    }
  }
  return max_numero;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  std::cout << es_espiral() << "\n";
  return 0;
}
