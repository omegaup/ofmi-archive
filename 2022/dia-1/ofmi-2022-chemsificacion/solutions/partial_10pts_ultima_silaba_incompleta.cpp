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
      std::cout << s[j];  // Imprimimos el mismo caracter
      // Si es una silaba checar si acaba en exactamente una vocal
      if ((j % 3 == 2) || (j == s.size() - 1)) {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
            s[j] == 'u') {
          // Hay que asegurarnos que la letra anterior no sea vocal
          if (j == 0 ||
              (s[j - 1] != 'a' && s[j - 1] != 'e' && s[j - 1] != 'i' &&
               s[j - 1] != 'o' && s[j - 1] != 'u')) {
            // Chemsificamos la palabra imprimiendo una m
            std::cout << "m";
          }
        }
      }
    }
    if (i < n - 1) {
      std::cout << " ";  // Imprimimos un espacio entre cada palabra
    }
  }
  std::cout << std::endl;  // Imprimimos un salto de línea final
  return 0;
}
