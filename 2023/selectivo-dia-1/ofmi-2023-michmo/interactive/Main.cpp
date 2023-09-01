#include <iostream>
#include <string>

#include "michmo.h"

typedef long long int lli;
typedef std::pair<int, int> pii;

int NUM_SUB = 4;
int subtask;
int N, M, P, A, B;
bool casoEvaluado;

int getSubtask(const std::string& caseName) {
  for (int sub = 1; sub <= NUM_SUB; ++sub) {
    if (caseName.find("sub" + std::to_string(sub)) != std::string::npos) {
      return sub;
    }
  }
  return -1;
}

void arreglarFraccion(pii& frac) {
  // Cambia denominador a positivo
  if (frac.second < 0) {
    frac.first *= -1;
    frac.second *= -1;
  }
}

bool compararFracciones(pii fracIzq, pii fracDer) {
  // a/b <= x/y
  // a*y <= x*b
  arreglarFraccion(fracIzq);
  arreglarFraccion(fracDer);
  return ((lli)fracIzq.first) * fracDer.second <=
         ((lli)fracIzq.second) * fracDer.first;
}

bool esTiroValido(int p, int a, int b) {
  if (b == 0) {
    // No se permite que el denominador sea 0
    return false;
  }
  pii fracTiro = std::make_pair(a, b);
  pii fracInferior;
  pii fracSuperior;
  if (M < p) {
    // Debe pegar entre (N/2, 0) y (N, M)
    fracInferior = std::make_pair(-p, N / 2);
    fracSuperior = std::make_pair(M - p, N);
  } else if (0 <= p) {
    // Debe pegar entre (N/2, 0) y (N/2, M)
    fracInferior = std::make_pair(-p, N / 2);
    fracSuperior = std::make_pair(M - p, N / 2);
  } else {
    // Debe pegar entre (N, 0) y (N/2, M)
    fracInferior = std::make_pair(-p, N);
    fracSuperior = std::make_pair(M - p, N / 2);
  }
  return compararFracciones(fracInferior, fracTiro) &&
         compararFracciones(fracTiro, fracSuperior);
}

int interseccion(int p, int a, int b) { return (float)a * N / b + p; }

void devolver(int p, int a, int b) {
  if (casoEvaluado) {
    // Ya se llamo 'devolver' o 'terminar'
    return;
  }
  casoEvaluado = true;

  if (subtask == 1) {
    if (0 <= P && P <= M) {
      // Detectaron que estaba dentro de la mesa
      std::cout << "1\n";
    } else {
      std::cout << "0\n";
    }
    return;
  }

  if (b == 0) {
    // No es valido
    std::cout << "0\n";
    return;
  }

  if (!esTiroValido(P, A, B)) {
    // El tiro era invalido, no debieron devolver
    std::cout << "0\n";
    return;
  }

  // Verificar que si sea el punto correcto
  int interseccionP = interseccion(P, A, B);
  if (interseccionP != p) {
    // No calculo bien la interseccion
    std::cout << "0\n";
    return;
  }

  // Consideramos el reflejo para reusar la funcion
  if (esTiroValido(p, -a, b)) {
    // Fue un tiro valido
    std::cout << "1\n";
  } else {
    std::cout << "0\n";
  }
}

void terminar() {
  if (casoEvaluado) {
    // Ya se llamo 'devolver' o 'terminar'
    return;
  }
  casoEvaluado = true;

  if (subtask == 1) {
    if (0 <= P && P <= M) {
      // Detectaron que estaba fuera de la mesa
      std::cout << "0\n";
    } else {
      std::cout << "1\n";
    }
    return;
  }

  // La participante reporto que el tiro fue invalido
  if (esTiroValido(P, A, B)) {
    // Se equivoco, el tiro fue valido
    std::cout << "0\n";
  } else {
    // Correcto
    std::cout << "1\n";
  }
}

int main(int argc, char* argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  subtask = getSubtask(caseName);

  // Leemos el caso
  std::cin >> N >> M;
  std::cin >> P >> A >> B;

  // Llamamos a la función de la participante
  michmo(N, M, P, A, B);

  if (!casoEvaluado) {
    // No hubo llamadas a las funciones 'devolver' o 'terminar'
    std::cout << "0\n";
  }
  return 0;
}
