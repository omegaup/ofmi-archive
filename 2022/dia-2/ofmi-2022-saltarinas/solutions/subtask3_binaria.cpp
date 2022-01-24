#include <iostream>

typedef long long int lli;

const int MODULO = 1e9 + 7;
const int MaxN = 1e5 + 1;
const int MaxT = 17;

int N;        // Cantidad de cobayas
int a[MaxN];  // Saltos de las cobayas
lli Q, X;

lli contar_saltos(lli tiempo) {
  lli saltos = 0;
  for (int i = 0; i < N; ++i) {
    saltos += tiempo / a[i];
  }
  return saltos;
}

lli resolver_pregunta(lli saltos) {
  lli inicio_t = 0;           // El minimo tiempo posible
  lli final_t = 16 * saltos;  // El maximo tiempo posible
  lli medio_t;
  while (inicio_t < final_t) {
    // Punto medio
    medio_t = (inicio_t + final_t) / 2;
    if (contar_saltos(medio_t) >= saltos) {
      // Se puede en medio_t segundos
      final_t = medio_t;
    } else {
      // No se puede en medio_t
      inicio_t = medio_t + 1;
    }
  }
  return inicio_t;
}

int subtask2() {
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
  return suma_respuestas;
}

int main() {
  // Para rapida lectura de datos
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Leemos la cantidad de cobayas
  std::cin >> N;

  // Leemos los tiempos de las cobayas
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  // Leemos Q y X
  std::cin >> Q >> X;

  // Resolvemos cada una de las preguntas
  lli suma_respuestas = 0;
  if (X == 1) {
    // Resolviendo subtask 2
    suma_respuestas = subtask2();
  } else {
    for (lli i = 1; i <= Q; ++i) {
      suma_respuestas += resolver_pregunta(i * X);
      suma_respuestas %= MODULO;
    }
  }
  std::cout << suma_respuestas << std::endl;
}
