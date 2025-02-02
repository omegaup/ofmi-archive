#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  // Leemos los N numeros
  std::vector<int> pares, impares;
  for (int i = 0; i < N; ++i) {
    int numero;
    std::cin >> numero;

    // Separamos entre pares e impares
    if (numero % 2 == 0) {
      // Es par
      pares.push_back(numero);
    } else {
      // Es impar
      impares.push_back(numero);
    }
  }

  // Ordenamos las listas
  std::sort(pares.begin(), pares.end());
  std::sort(impares.begin(), impares.end());

  // Imprimimos primero los pares y luego impares
  for (int i = 0; i < pares.size(); ++i) {
    std::cout << pares[i] << " ";
  }
  for (int i = 0; i < impares.size(); ++i) {
    std::cout << impares[i] << " ";
  }
}
