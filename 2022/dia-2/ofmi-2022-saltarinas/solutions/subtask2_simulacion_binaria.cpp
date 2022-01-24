#include <iostream>
#include <vector>

typedef long long int lli;

const int MODULO = 1e9 + 7;
const int MaxN = 1e5 + 1;

int N;        // Cantidad de cobayas
int a[MaxN];  // Saltos de las cobayas

std::vector<int> saltos_guardados;

void calcular_saltos(int saltos_maximos) {
  saltos_guardados.push_back(0);
  int tiempo = 0;  // El segundo actual
  int saltos = 0;  // Cuantos saltos llevamos
  while (saltos < saltos_maximos) {
    ++tiempo;  // Transcurre un segundo
    for (int i = 0; i < N; ++i) {
      if (tiempo % a[i] == 0) {
        // La i-esima cobaya salto
        ++saltos;
      }
    }
    // Guardamos la cantidad de saltos
    // para el segundo actual
    saltos_guardados.push_back(saltos);
  }
}

lli resolver_pregunta(lli saltos) {
  lli inicio_t = 0;                           // El minimo tiempo posible
  lli final_t = saltos_guardados.size() - 1;  // El maximo tiempo posible
  lli medio_t;
  while (inicio_t < final_t) {
    // Punto medio
    medio_t = (inicio_t + final_t) / 2;
    if (saltos_guardados[medio_t] >= saltos) {
      // Se puede en medio_t segundos
      final_t = medio_t;
    } else {
      // No se puede en medio_t
      inicio_t = medio_t + 1;
    }
  }
  return inicio_t;
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
  lli Q, X;
  std::cin >> Q >> X;

  // Calculamos los saltos para cada segundo hasta tener Q * X
  calcular_saltos(Q * X);

  // Respondemos las Q preguntas
  lli suma_respuestas = 0;
  for (int i = 1; i <= Q; ++i) {
    suma_respuestas += resolver_pregunta(i * X);
    suma_respuestas %= MODULO;
  }
  std::cout << suma_respuestas << std::endl;
}
