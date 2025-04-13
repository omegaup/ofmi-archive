#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::string ruleta;
  std::cin >> ruleta;

  // Barrido para calcular máximo número de premios dada una k
  int izq = 0, der = 0, max_premios = 0, premios = 0, intentos = 0;

  // Las condiciones para terminar el bucle son las siguientes:
  // a) Ya probe todos los inicios posible (i < n) y,
  // b) El final alcanzo al inicio
  while (izq < n && der < izq + n) {
    if (ruleta[der % n] == 'P') {
      ++premios;
    } else {
      ++intentos;
    }

    // Movemos nuestra ventana hasta que haya k - 1 y continuamos
    while (intentos >= k) {
      if (ruleta[izq] == 'P') {
        --premios;
      } else {
        --intentos;
      }
      ++izq;
    }

    max_premios = std::max(max_premios, premios);
    der++;
  }

  std::cout << max_premios << '\n';
  return 0;
}
