#include <iostream>

int main() {
  int N, B, R, L;
  std::cin >> N >> B >> R >> L;
  // Restamos los reservados
  B -= R;
  for (int i = 0; i < N; ++i) {
    int Di;
    std::cin >> Di;
    // Imprimimos la mayor cantidad de boletos
    // No nos preocupamos por el limite L
    if (Di > B) {
      std::cout << B << "\n";
      B = 0;
    } else {
      std::cout << Di << "\n";
      B -= Di;
    }
  }
  return 0;
}
