#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> degree(n);
  std::vector<int> indice(n, 1);

  std::cin >> degree[0];
  for (int i = 1; i < n; ++i) {
    std::cin >> degree[i];
    indice[i] = i + 1;
    if (degree[0] != degree[i]) return 0;
  }

  std::cout << (degree[0] * n) / 2 << "\n";

  for (int i = 0; i < degree.size();) {
    int degree_actual = degree[i];
    for (int j = i + 1; j <= i + degree_actual; ++j) {
      std::cout << indice[i] << " " << indice[j] << "\n";
      if (degree[j] > 1) {
        degree.push_back(degree[j] - 1);
        indice.push_back(indice[j]);
      }
    }
    i += degree_actual + 1;
  }
}
