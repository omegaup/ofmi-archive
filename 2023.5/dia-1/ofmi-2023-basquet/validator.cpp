#include <fstream>
#include <iostream>

int n = 5;
int m = 3;

int main() {
  // Leemos la entrada oficial
  int a[n];
  std::ifstream din("data.in", std::ifstream::in);
  for (int i = 0; i < n; i++) {
    din >> a[i];
  }

  // Checamos si existe solucion con la salida oficial
  std::ifstream dout("data.out", std::ifstream::in);
  int x;
  dout >> x;
  bool solutionExistsOfficial = (x != -1);

  // Leemos la salida del concursante
  int b[m];
  for (int i = 0; i < m; i++) {
    if (!(std::cin >> b[i])) {
      std::cerr << "Error reading contestant output\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    if (i == 0 && b[i] == -1) {
      // Contestant printed -1
      break;
    }
  }
  bool solutionExistsContestant = (b[0] != -1);

  // Validamos la salida del concursante
  if (solutionExistsOfficial != solutionExistsContestant) {
    std::cerr << "Contestant output is incorrect: solutionExists differ\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  if (solutionExistsOfficial) {
    // Checamos que sumen 100 los m elementos
    int sum = 0;
    for (int i = 0; i < m; i++) {
      sum += b[i];
    }
    if (sum != 100) {
      std::cerr << "Contestant output is incorrect: sum != 100\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    // Checamos que los m elementos sean distintos
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        if (b[i] == b[j]) {
          std::cerr << "Contestant output is incorrect: repeated elements\n";
          std::cout << 0.0 << '\n';
          return 0;
        }
      }
    }
    // Checamos que cada elemento esté en el arreglo oficial
    for (int i = 0; i < m; i++) {
      bool found = false;
      for (int j = 0; j < n; j++) {
        if (b[i] == a[j]) {
          found = true;
          break;
        }
      }
      if (!found) {
        std::cerr << "Contestant output is incorrect: element not found\n";
        std::cout << 0.0 << '\n';
        return 0;
      }
    }
  }

  // Si llegamos hasta aquí, la salida del concursante es correcta
  std::cout << 1.0 << '\n';
  return 0;
}
