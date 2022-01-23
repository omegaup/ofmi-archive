// Subtarea 2, cada silaba termina en exactamente una vocal
#include <iostream>

int main() {
  // Leemos el entero n
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    // Leemos cada palabra
    std::string s;
    std::cin >> s;
    // En cada palabra nos fijamos cada silaba
    for (int j = 0; j < s.size(); j++) {
      // Imprimimos el mismo caracter
      std::cout << s[j];
      // Si es el final de una silaba, agregar
      if ((j % 3 == 2) || (j == s.size() - 1)) {
        std::cout << 'm';
      }
    }
    if (i < n - 1) {
      std::cout << ' ';  // Imprimimos un espacio entre cada palabra
    }
  }
  std::cout << std::endl;  // Imprimimos un salto de línea final
  return 0;
}
