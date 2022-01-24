#include <iostream>
// En lugar de checar contra las dos ultimas pujas validas, checa contra las dos
// ultimas pujas

int main() {
  int n;
  std::cin >> n;
  int actual, anterior = 0, anterior2 = 0, respuesta = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> actual;
    if (actual >= anterior + anterior2) {
      respuesta = i + 1;
    }
    anterior2 = anterior;
    anterior = actual;
  }
  std::cout << respuesta;
}