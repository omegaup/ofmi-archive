// Subtarea 1: Los tulipanes aparecen a lo mas dos veces.
//
// Para esta subtarea, el tener dos tulipanes de un mismo color nos ayuda a
// definir las esquinas del rectangulo que vamos a cultivar. Por eso, hacemos
// 1. Guardar la posicion donde encontramos un [tulipan].
// 2. Si nos lo volvemos a encontrar, entonces ya podemos formar el rectangulo.
// 3. Si nunca volvimos a repetir tulipanes, entonces todos son distintos,
//    y nos convendra cultivar cualquier rectangulo de 1x1.
#include <iostream>

const int MaxN = 1e3 + 5;
const int MaxColores = MaxN * MaxN;

// Cuando veamos un color, guardamos su informacion
bool visto[MaxColores];
int x_ultimo[MaxColores];
int y_ultimo[MaxColores];

int main() {
  int n, m;
  std::cin >> n >> m;

  bool respuesta_actualizada = false;
  int respuesta = 100000;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int tulipan;
      std::cin >> tulipan;

      if (visto[tulipan]) {
        int ancho = std::abs(x_ultimo[tulipan] - i) + 1;
        int alto = std::abs(y_ultimo[tulipan] - j) + 1;
        int area = ancho * alto;
        if (respuesta > area - 2) {
          respuesta_actualizada = true;
          respuesta = area - 2;
        }
      }
      visto[tulipan] = true;
      x_ultimo[tulipan] = i;
      y_ultimo[tulipan] = j;
    }
  }
  if (respuesta_actualizada) {
    std::cout << respuesta << "\n";
  } else {
    // Si no se actualizo la respuesta, todos los
    // tulipanes son diferentes, y podemos elegir un cuadrado
    // de 1x1
    std::cout << "0\n";
  }
}
