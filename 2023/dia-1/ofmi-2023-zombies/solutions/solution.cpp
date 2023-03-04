#include <iostream>

int main() {
  int n, d, zombie = 0;
  long long int escudos = 0;
  std::cin >> n >> d;
  for (int i = 0; i < n; i++) {
    std::cin >> zombie;
    escudos += (zombie - 1) / d;
  }
  std::cout << escudos << std::endl;
  return 0;
}
