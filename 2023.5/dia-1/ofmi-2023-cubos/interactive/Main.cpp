#include <math.h>

#include <iomanip>
#include <iostream>

#include "cubos.h"

const int MAX_N = 1000;
const int FRENTE = 0;  // X, Y
const int ARRIBA = 1;  // X, Z
const int LADO = 2;    // Y, Z
const bool DEBUG = false;

int n;
int llamadas;
int faltantes;

int proyecciones[3][MAX_N][MAX_N];

void imprimir_proyecciones() {
  if (!DEBUG) {
    return;
  }
  // imprime las proyecciones
  std::cerr << "frente:" << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cerr << proyecciones[FRENTE][i][j] << " ";
    }
    std::cerr << std::endl;
  }
  std::cerr << "arriba:" << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cerr << proyecciones[ARRIBA][i][j] << " ";
    }
    std::cerr << std::endl;
  }
  std::cerr << "lado:" << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cerr << proyecciones[LADO][i][j] << " ";
    }
    std::cerr << std::endl;
  }

  std::cerr << "bloques vacios en las proyecciones: " << faltantes << std::endl;
}

bool ponerBloque(int x, int y, int z) {
  llamadas++;
  if (llamadas > std::max(n * n * n, 3 * n * n)) {
    std::cerr << "Demasiadas llamadas a bloque" << std::endl;
    std::cout << 0 << std::endl;
    exit(0);
  }
  if (x < 0 || x >= n || y < 0 || y >= n || z < 0 || z >= n) {
    std::cerr << "Coordenadas invalidas" << std::endl;
    std::cout << 0 << std::endl;
    exit(0);
  }
  if (proyecciones[FRENTE][x][y] == 0) {
    proyecciones[FRENTE][x][y]++;
    faltantes--;
  }
  if (proyecciones[ARRIBA][x][z] == 0) {
    proyecciones[ARRIBA][x][z]++;
    faltantes--;
  }
  if (proyecciones[LADO][y][z] == 0) {
    proyecciones[LADO][y][z]++;
    faltantes--;
  }

  imprimir_proyecciones();

  return faltantes == 0;
}

int puntaje_lineal(int llamadas, int limite_inferior, int limite_superior,
                   int puntaje_inferior, int puntaje_superior) {
  int rango = limite_superior - limite_inferior;
  int diferencia = limite_superior - llamadas;
  float proporcion = (float)diferencia / (float)rango;

  return puntaje_inferior +
         round((puntaje_superior - puntaje_inferior) * proporcion);
}

void terminar() {
  if (faltantes != 0) {
    std::cerr << "Las proyecciones no estan llenas de bloques" << std::endl;
    std::cout << 0 << std::endl;
    exit(0);
  }

  std::cerr << "Llamadas: " << llamadas << std::endl;

  /*
        - si $c\leq n^2$ se te darán 100 puntos
        - si $n^2 < c \leq 2n^2$ se te darán mínimo 80 puntos
        - si $2n^2 < c \leq 3n^2$ se te darán mínimo 40 puntos
        - si $3n^2 < c \leq n^3$ se te darán mínimo 20 puntos
        - si c > $n^3 c$ se te darán 0 puntos
  */
  int puntos = 0;
  if (llamadas <= n * n) {
    puntos = 100;
  } else if (llamadas <= 2 * n * n) {
    puntos = puntaje_lineal(llamadas, n * n, 2 * n * n, 80, 100);
  } else if (llamadas <= 3 * n * n) {
    puntos = puntaje_lineal(llamadas, 2 * n * n, 3 * n * n, 40, 80);
  } else if (llamadas <= n * n * n) {
    puntos = puntaje_lineal(llamadas, 3 * n * n, n * n * n, 20, 40);
  }

  std::cout << std::setprecision(2);
  if (DEBUG) {
    std::cerr << "Tu puntaje para este caso es: " << puntos << std::endl;
  }

  std::cout << puntos / 100.0 << std::endl;
}

int main() {
  std::cin >> n;
  faltantes = 3 * n * n;

  cubo(n);
  terminar();

  return 0;
}