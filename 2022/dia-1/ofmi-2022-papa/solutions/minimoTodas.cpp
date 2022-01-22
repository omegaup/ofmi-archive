#include <algorithm>
#include <iostream>

int main() {
  int maeva, lorena, ramona;
  std::cin >> maeva >> lorena >> ramona;

  int minima = std::min(maeva, std::min(lorena, ramona));

  if (maeva == minima) {
    std::cout << "Maeva\n";
  }
  if (lorena == minima) {
    std::cout << "Lorena\n";
  }
  if (ramona == minima) {
    std::cout << "Ramona\n";
  }
}