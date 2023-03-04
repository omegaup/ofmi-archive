#include <iostream>

int main() {
  int n, d;
  std::cin >> n >> d;         // Sabemos d = 1 para esta subtarea
  long long int escudos = 0;  // Aquí guardaremos la respuesta
  for (int i = 0; i < n; i++) {
    int zombie;
    std::cin >> zombie;
    escudos += (zombie - 1);
  }
  std::cout << escudos << std::endl;
  return 0;
}
