#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int masa_1;
  std::cin >> masa_1;

  if (n == 1) {
    std::cout << masa_1 << "\n";
  } else {
    int masa_2;
    std::cin >> masa_2;
    if (masa_2 < masa_1) std::swap(masa_1, masa_2);
    std::cout << std::max(masa_1, masa_2 - masa_1) << "\n";
  }
}
