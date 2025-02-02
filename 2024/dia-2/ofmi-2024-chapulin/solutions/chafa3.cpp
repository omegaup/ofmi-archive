#include <iostream>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;

  int suma = 0;

  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;

    if (i % s == 0) {
      suma += num;
    }
    std::cout << suma << "\n";
  }
}
