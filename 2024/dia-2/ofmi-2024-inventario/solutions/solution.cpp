#include <iostream>

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;

  // Cubeta para contar las veces que se encontró cada tipo de flor.
  // Nosotros vamos a indexar a los tipos de flor del 0 al m - 1.
  int encontradas[m];
  for (int i = 0; i < m; ++i) encontradas[i] = 0;

  // Para cada día...
  for (int i = 0; i < n; ++i) {
    int t;
    std::cin >> t;

    // Para cada tipo de flor que se encontró este día...
    for (int j = 0; j < t; ++j) {
      int codigo_flor;
      std::cin >> codigo_flor;

      // Incrementamos las encontradas del tipo de flor con este código
      // (menos uno porque nuestra cubeta esta indexada desde 0).
      ++encontradas[codigo_flor - 1];
    }
  }

  // En esta segunda cubeta, la k-esima posición nos va a indicar cuantos
  // tipos de flor se encontraron al menos k veces.
  int encontraron_al_menos[n + 1];
  for (int i = 0; i <= n; ++i) encontraron_al_menos[i] = 0;

  // Para empezar, sabemos que el tipo de flor con código i se encontró
  // exactamente encontradas[i] veces.
  for (int i = 0; i < m; ++i) ++encontraron_al_menos[encontradas[i]];

  // Si un tipo de flor se encontró al menos k veces, entonces también se
  // encontró al menos k - 1 veces. De este modo vamos a acumular cuantos tipos
  // se encontraron al menos k veces iterando en reversa la cubeta
  // encontraron_al_menos.
  for (int i = n; i > 0; --i)
    encontraron_al_menos[i - 1] += encontraron_al_menos[i];

  for (int i = 0; i < q; ++i) {
    int k;
    std::cin >> k;
    std::cout << encontraron_al_menos[k] << '\n';
  }
  return 0;
}
