#include <iostream>

const int MODULO = 1e9 + 7;

int main() {
  // Para rapida lectura de datos
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Leemos la cantidad de cobayas
  int N;
  std::cin >> N;
  if (N > 100) {
    // No es subtask 1
    return 0;
  }

  // Leemos los tiempos de las cobayas
  int a[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // Leemos Q y X
  int Q, X;
  std::cin >> Q >> X;
  if (X > 100 && Q > 10000) {
    // No es subtask 1
    return 0;
  }

  int suma_respuestas = 0;
  for (int i = 1; i <= Q; ++i) {
    // Buscamos hacer iX saltos
    int saltos = 0;
    int tiempo = 0;
    while (saltos < i * X) {
      ++tiempo;
      for (int j = 0; j < N; ++j) {
        if (tiempo % a[j] == 0) {
          ++saltos;  // La cobaya j-esima salta
        }
      }
    }
    suma_respuestas += tiempo;
    suma_respuestas %= MODULO;
  }
  std::cout << suma_respuestas << std::endl;
}
