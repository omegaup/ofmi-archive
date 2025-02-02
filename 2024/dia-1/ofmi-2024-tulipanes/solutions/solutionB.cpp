#include <iostream>

const int MaxN = 1001;
const int MaxColores = MaxN * MaxN;

int conteo[MaxColores];
int izquierda[MaxColores];
int derecha[MaxColores];
int arriba[MaxColores];
int abajo[MaxColores];

int main() {
  for (int i = 0; i < MaxColores; ++i) {
    izquierda[i] = MaxN;
    abajo[i] = MaxN;
  }

  int N, M;
  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int tulipan;
      std::cin >> tulipan;
      // En una cubeta, contamos cuantas veces se repite cada [tulipan]
      ++conteo[tulipan];
      // Actualizamos para [tulipan], la posicion mas a la izquierda, derecha
      // arriba, o abajo de cada una
      izquierda[tulipan] = std::min(i, izquierda[tulipan]);
      derecha[tulipan] = std::max(i, derecha[tulipan]);
      arriba[tulipan] = std::max(j, arriba[tulipan]);
      abajo[tulipan] = std::min(j, abajo[tulipan]);
    }
  }

  int maxima_frequencia = 0;
  int respuesta = 0;
  for (int i = 0; i < MaxColores; ++i) {
    // Si el conteo es igual o mejor, actualizamos la respuesta
    if (maxima_frequencia <= conteo[i]) {
      // Calculamos primero el area formada por el rectangulo formado por
      // los tulipanes con color [i]
      int ancho = derecha[i] - izquierda[i] + 1;
      int altura = arriba[i] - abajo[i] + 1;
      int area = ancho * altura;
      // Los demas tulipanes van a ser desperdiciados
      int desperdicio = area - conteo[i];

      // Actualizamos la respuesta
      if (maxima_frequencia < conteo[i] || desperdicio < respuesta) {
        maxima_frequencia = conteo[i];
        respuesta = desperdicio;
      }
    }
  }

  // Imprimimos la respuesta
  std::cout << respuesta << "\n";
  return 0;
}