#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> degree(n);
  std::vector<int> indice(n, 1);

  int m = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> degree[i];
    indice[i] = i + 1;
    m += degree[i];
  }

  std::cout << m / 2 << "\n";

  while (n) {
    // Ordenar los degrees.
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        if (degree[j] > degree[j - 1]) {
          std::swap(degree[j], degree[j - 1]);
          std::swap(indice[j], indice[j - 1]);
        }
      }
    }

    for (int i = degree[0]; i; --i) {
      std::cout << indice[0] << " " << indice[i] << "\n";

      if (!--degree[i]) {
        std::swap(degree[i], degree[n - 1]);
        std::swap(indice[i], indice[--n]);
      }
    }

    std::swap(degree[0], degree[n - 1]);
    std::swap(indice[0], indice[--n]);
  }
}
