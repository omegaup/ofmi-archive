#include <iostream>

int main() {
  int N, B, R, L;
  std::cin >> N >> B >> R >> L;
  // Asumimos que solo un animal comprara hongo
  int D;
  std::cin >> D;
  // Restamos los boletos reservados
  B -= R;
  // Vendemos la mayor cantidad posible
  std::cout << std::min(B, D) << "\n";
  return 0;
}
