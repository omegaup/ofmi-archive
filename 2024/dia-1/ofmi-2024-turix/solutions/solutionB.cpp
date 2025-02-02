#include <iostream>

const int MaxH = 1e5 + 10;
int cantidad_de_alturas[MaxH];

int main() {
  int t, h;
  std::cin >> t >> h;

  for (int i = 0; i < t; ++i) {
    int altura;
    std::cin >> altura;
    cantidad_de_alturas[altura]++;
  }

  int pretzels_total = 0;
  for (int i = 0; i < h; ++i) {
    int pretzels;
    std::cin >> pretzels;
    pretzels_total += pretzels * cantidad_de_alturas[i + 1];
  }

  std::cout << pretzels_total << "\n";
}
