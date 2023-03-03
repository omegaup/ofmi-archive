// Esta parcial no hace la división correcta
#include <iostream>

int main() {
  int n, d;
  std::cin >> n >> d;
  long long int escudos = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    escudos += x / d;
  }
  std::cout << escudos << std::endl;
  return 0;
}