#include <iostream>

typedef long long int lli;

const int MODULO = 1e9 + 7;

int main() {
  // Para rapida lectura de datos
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Leemos la cantidad de cobayas
  int N;
  std::cin >> N;

  // Leemos los tiempos de las cobayas
  int a[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // Leemos Q y X
  lli Q, X;
  std::cin >> Q >> X;

  lli tiempo = 0;           // El segundo actual
  lli saltos = 0;           // Cuantos saltos llevamos
  lli pregunta_actual = 1;  // Cuantas preguntas hemos respondido
  lli suma_respuestas = 0;  // La suma de los s_i
  while (saltos < Q * X) {
    ++tiempo;  // Transcurre un segundo
    for (int i = 0; i < N; ++i) {
      if (tiempo % a[i] == 0) {
        // La i-esima cobaya salto
        ++saltos;
      }
    }
    while (pregunta_actual <= Q && pregunta_actual * X <= saltos) {
      suma_respuestas += tiempo;  // Pudimos responder una pregunta mas
      suma_respuestas %= MODULO;
      ++pregunta_actual;
    }
  }
  std::cout << suma_respuestas << std::endl;
}
