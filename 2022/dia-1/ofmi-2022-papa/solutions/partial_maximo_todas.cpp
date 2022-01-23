#include <algorithm>
#include <iostream>

int main() {
  int maeva, lorena, ramona;
  std::cin >> maeva >> lorena >> ramona;

  int maxima = std::max(maeva, std::max(lorena, ramona));

  if (maeva == maxima) {
    std::cout << "Maeva\n";
  }
  if (lorena == maxima) {
    std::cout << "Lorena\n";
  }
  if (ramona == maxima) {
    std::cout << "Ramona\n";
  }
}