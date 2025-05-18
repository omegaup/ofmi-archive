#include <iostream>

#include "ruleta.h"

constexpr int kMaxN = 1e4;

int arreglo[kMaxN];
int n, x, llamadas_restantes;

void debug(const std::string& info) { std::cerr << info << std::endl; }

int pregunta(int posicion) {
  debug("Llamaste a pregunta(" + std::to_string(posicion) + ")");

  if (llamadas_restantes == 0) {
    debug("Se te acabaron las preguntas");
    std::cout << "0.0" << std::endl;
    std::exit(0);
  }

  --llamadas_restantes;

  if (posicion < 0 || n <= posicion) {
    debug("Preguntaste por una posicion fuera del arreglo");
    return -1;
  }

  debug("El numero en la posicion es " + std::to_string(arreglo[posicion]));
  return arreglo[posicion];
}

int main() {
  // Leemos `n` y `x`.
  std::cin >> n >> x;

  // Leemos el arreglo y obtenemos la posicion de `x`.
  int indice_x = -1;
  for (int i = 0; i < n; ++i) {
    std::cin >> arreglo[i];
    if (arreglo[i] == x) indice_x = i;
  }

  debug("La posicion del numero es " + std::to_string(indice_x));

  // Leemos el numero de llamadas que podemos hacer a `pregunta`.
  std::cin >> llamadas_restantes;

  // Checamos que la funcion de la concursante regrese lo mismo.
  int respuesta = encuentra(x, n);

  if (respuesta == indice_x) {
    debug("Encontraste el numero correctamente!");
  } else {
    debug("Tu programa respondio incorrectamente " + std::to_string(respuesta));
  }
}
