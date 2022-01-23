#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> candidata(3);
  std::vector<int> copia(3);
  std::cin >> candidata[0] >> candidata[1] >> candidata[2];

  copia = candidata;

  std::sort(copia.begin(), copia.end());

  int medio = copia[1];

  if (candidata[0] == medio) {
    std::cout << "Maeva\n";
  }

  if (candidata[1] == medio) {
    std::cout << "Lorena\n";
  }

  if (candidata[2] == medio) {
    std::cout << "Ramona\n";
  }
}