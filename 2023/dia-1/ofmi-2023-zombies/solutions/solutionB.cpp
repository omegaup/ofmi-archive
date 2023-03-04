#include <iostream>

int main() {
  int n, d;
  std::cin >> n >> d;
  long long int escudos = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    escudos += (x - 1) / d;
  }
  std::cout << escudos << std::endl;
  return 0;
}