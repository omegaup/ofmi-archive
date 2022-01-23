#include <iostream>

bool esVocal(char w) {
  return w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u';
}

int main() {
  int n;
  std::cin >> n;
  if (n == 1) {
    // Subtask 1
    std::string palabra;
    std::cin >> palabra;
    for (int i = 0; i < palabra.size(); i++) {
      std::cout << palabra[i];
      if ((i % 3 == 2) || (i == palabra.size() - 1)) {
        if (esVocal(palabra[i])) {
          if (i % 3 == 0 || !esVocal(palabra[i - 1])) {
            std::cout << 'm';
          }
        }
      }
    }
  } else {
    // Subtask 3
    for (int i = 0; i < n; i++) {
      std::string s;
      std::cin >> s;
      for (int j = 0; j < s.size(); j++) {
        std::cout << s[j];
        if ((j % 3 == 2) || (j == s.size() - 1)) {
          if (esVocal(s[j])) {
            std::cout << 'm';
          }
        }
      }
      if (i < n - 1) {
        std::cout << ' ';
      }
    }
  }
  std::cout << std::endl;
  return 0;
}
