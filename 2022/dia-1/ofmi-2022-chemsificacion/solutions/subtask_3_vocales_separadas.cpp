// Subtarea 3, todas las vocales están separadas
#include <iostream>

bool esVocal(char w) {
  return w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u';
}

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
      // Si es el final de una silaba, checar si termina en vocal
      if ((j % 3 == 2) || (j == s.size() - 1)) {
        if (esVocal(s[j])) {
          // Como no hay vocales juntas, no tenemos que preocuparnos por la
          // anterior letra
          std::cout << 'm';
        }
      }
    }
    if (i < n - 1) {
      std::cout << ' ';  // Imprimimos un espacio entre cada palabra
    }
  }
  std::cout << std::endl;  // Imprimimos un salto de línea final
  return 0;
}
