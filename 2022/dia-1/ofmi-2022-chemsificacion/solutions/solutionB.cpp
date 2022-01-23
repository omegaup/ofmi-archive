#include <iostream>
#include <string>
#include <vector>

bool es_vocal(char w) {
  return w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u';
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::string palabra;
    std::cin >> palabra;

    // Nos situamos en la primera letra de cada silaba
    for (int g = 0; g < palabra.size(); g += 3) {
      std::vector<char> subpalabra;
      // Guardamos las letras de la silaba en un vector
      for (int j = 0; j < 3 && g + j < palabra.size(); j++) {
        std::cout << palabra[g + j];
        subpalabra.push_back(palabra[g + j]);
      }
      // Preguntar si el ultimo caracter de subpalabra es vocal
      if (es_vocal(subpalabra.back())) {
        // Si el tamaño de la sílaba es igual a 1, imprimimos 'm'
        // Si la penúltima letra no es vocal también, imprimimos 'm'
        if (subpalabra.size() == 1 ||
            !es_vocal(subpalabra[subpalabra.size() - 2])) {
          std::cout << 'm';
        }
      }
    }
    // Al final de la palabra, imprimimos un espacio. Menos en la ultima palabra
    if (i < n - 1) {
      std::cout << ' ';
    }
  }
  std::cout << std::endl;
}
