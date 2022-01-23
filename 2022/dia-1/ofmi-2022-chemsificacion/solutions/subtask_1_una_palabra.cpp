// Primera subtarea donde N = 1
#include <iostream>

bool esVocal(char w) {
  return w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u';
}

int main() {
  int n;
  std::cin >> n;

  // Ya que N = 1, solo recibimos una palabra
  std::string palabra;
  std::cin >> palabra;

  // Recorremos toda la palabra
  for (int i = 0; i < palabra.size(); i++) {
    // Imprimir el mismo caracter
    std::cout << palabra[i];

    // Si es una silaba, ver si acaba en exactamente una vocal
    // O si 1es el último caracter
    if ((i % 3 == 2) || (i == palabra.size() - 1)) {
      if (esVocal(palabra[i])) {
        // Si la silaba tiene mas de una letra,
        // hay que asegurarnos que la letra anterior no sea vocal
        if (i % 3 == 0 || !esVocal(palabra[i - 1])) {
          // Chemsificamos la palabra imprimiendo una m al final de la silaba
          std::cout << 'm';
        }
      }
    }
  }
  std::cout << std::endl;
  return 0;
}