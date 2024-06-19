#include <iostream>

#include "frijolitos.h"

typedef long long int lld;

const bool DEBUG = false;

lld n;
lld frijolitosTomados = 0;
bool movimientoInvalido = false;

lld tomar(lld cantidad) {
  if (DEBUG) {
    std::cerr << "Llamaste a tomar(" << cantidad << ")" << std::endl;
  }

  if (n == 0) {
    std::cerr << "Ya no puedes tomar más frijolitos" << std::endl;
    movimientoInvalido = true;
    std::cout << 0 << std::endl;
    std::exit(0);
  }

  if (cantidad < 0 || cantidad > n) {
    std::cerr << "Cantidad inválida" << std::endl;
    movimientoInvalido = true;
    std::cout << 0 << std::endl;
    std::exit(0);
  }

  const bool movimientoValido =
      cantidad == 1 || ((n & 1) == 0 && cantidad == n / 2);

  if (!movimientoValido) {
    std::cerr << "Movimiento invalido. Solo puedes tomar 1 frijolito o la "
                 "mitad de los frijolitos"
              << std::endl;
    movimientoInvalido = true;
    std::cout << 0 << std::endl;
    std::exit(0);
  }

  n -= cantidad;
  frijolitosTomados += cantidad;

  lld cantidadEvaluador = 0;
  if (n > 0) {
    // Aquí va la lógica del evaluador
    cantidadEvaluador = 1;
    if (DEBUG) {
      std::cerr << "El evaluador tomo " << cantidadEvaluador << " frijolitos"
                << std::endl;
    }
    n -= cantidadEvaluador;
  }

  if (n == 0 && DEBUG) {
    std::cerr << "El juego ha terminado" << std::endl;
  }
  return cantidadEvaluador;
}

long double score() {
  // Aquí va la lógica para calcular el score
  if (movimientoInvalido) {
    return 0.0;
  }
  if (n > 0) {
    std::cerr << "No se terminó el juego. Quedaron " << n << " frijolitos"
              << std::endl;
    return 0.0;
  }
  if (DEBUG) {
    std::cerr << "Frijolitos tomados: " << frijolitosTomados << std::endl;
  }
  return 1.0;
}

int main() {
  // Leemos n
  std::cin >> n;

  // Mandamos a llamar a la función del concursante
  frijolitos(n);

  std::cout << score() << std::endl;
  return 0;
}
