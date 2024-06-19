#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  // sub1 - N = 1
  int N, C;
  std::cin >> N >> C;

  // Leemos el valor del único elemento, a.
  int a;
  std::cin >> a;

  // Si a < C, se puede subir en ese momento; de lo contrario es imposible
  // subir.
  std::cout << (a < C ? 0 : -1) << "\n";

  return 0;
}