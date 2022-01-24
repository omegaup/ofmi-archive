#include <iostream>

int main() {
  // Cantidad de pujas
  int n;
  std::cin >> n;

  // Leemos las pujas de las cobayas
  int a[4];
  a[0] = 0;  // Puja inicial
  std::cin >> a[1];
  if (2 <= n) {
    std::cin >> a[2];
  }
  if (3 <= n) {
    std::cin >> a[3];
  }

  // Checamos las pujas posibles
  int puja1 = 0, puja2 = 0;
  if (a[1] >= a[puja1] + a[puja2]) {
    puja2 = puja1;
    puja1 = 1;
  }
  if (2 <= n && a[2] >= a[puja1] + a[puja2]) {
    puja2 = puja1;
    puja1 = 2;
  }
  if (3 <= n && a[3] >= a[puja1] + a[puja2]) {
    puja2 = puja1;
    puja1 = 3;
  }

  // Imprimimos a la ganadora
  std::cout << puja1 << "\n";
  return 0;
}
