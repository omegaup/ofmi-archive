#include <algorithm>
#include <iostream>

#include "reunion.h"

const double EPS = 1e-6;
bool is_equal(double r, double s) {
  return std::abs(r - s) / std::max(1.0, s) < EPS;
}

bool didSampleCase(int n, int X[], int V[], double ans) {
  // Caso de ejemplo
  int n_sample = 3;
  int X_sample[] = {28, 4, 12};
  int V_sample[] = {2, 4, 2};
  double ans_sample = 4.0;
  bool is_sample_case = true;

  if (n != n_sample) {
    is_sample_case = false;
  }
  for (int i = 0; i < n_sample; ++i) {
    if (X[i] != X_sample[i]) {
      is_sample_case = false;
    }
    if (V[i] != V_sample[i]) {
      is_sample_case = false;
    }
  }

  if (is_sample_case) {
    if (is_equal(ans, ans_sample)) {
      std::clog << "Respuesta correcta!" << std::endl;
    } else {
      std::clog << "Respuesta incorrecta!" << std::endl;
      std::clog << "Respuesta esperada: " << ans_sample << std::endl;
    }
    return is_equal(ans, ans_sample);
  } else {
    std::clog << "Nota: No podemos verificar que la respuesta sea "
                 "verdaderamente correcta"
              << std::endl;
    return true;
  }
}

int main() {
  // Leemos n y m
  int n;
  std::cin >> n;
  // Leemos el arreglo X y V
  int X[n];
  int V[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> X[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> V[i];
  }
  // Llamamos a la función de la participante
  std::clog << "Llamando a reunion(" << n << ")..." << std::endl;
  double ans = reunion(n, X, V);

  // Imprimimos la respuesta
  std::clog << "Resultado: " << ans << std::endl;

  if (didSampleCase(n, X, V, ans)) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
