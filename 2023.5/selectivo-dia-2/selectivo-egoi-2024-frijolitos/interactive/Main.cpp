#include <iostream>

#include "frijolitos.h"

typedef long long int lld;

const bool DEBUG = false;

const int NUM_SUB = 3;
int getSubtask(const std::string& caseName) {
  for (int sub = 1; sub <= NUM_SUB; ++sub) {
    if (caseName.find("sub" + std::to_string(sub)) != std::string::npos) {
      return sub;
    }
  }
  return -1;
}

lld n;
lld frijolitosTomados = 0;
bool movimientoInvalido = false;

lld optimo(lld x) {
  if (x > 8 && (x % 4) == 0) {
    return 1;
  }
  return x & 1 ? 1 : x / 2;
}

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
    cantidadEvaluador = optimo(n);
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

lld calcularOptimo(lld x) {
  // Calcula el optimo del juego
  lld ans = 0;
  int player = 0;
  while (x > 0) {
    lld y = optimo(x);
    if (player == 0) {
      ans += y;
    }
    x -= y;
    player ^= 1;
  }
  return ans;
}

lld initialN;
long double score(const int subtask) {
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
  lld Y = calcularOptimo(initialN);
  if (subtask == 1 || subtask == 2) {
    return (frijolitosTomados == Y ? 1.0 : 0.0);
  } else if (subtask == 3) {
    if (frijolitosTomados >= Y) {
      return 1.0;
    }
    return ((frijolitosTomados + 1.0) / Y) * 0.7;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  int subtask = getSubtask(caseName);

  // Leemos n
  std::cin >> n;
  initialN = n;

  // Mandamos a llamar a la función del concursante
  frijolitos(n);

  std::cout << score(subtask) << std::endl;
  return 0;
}
