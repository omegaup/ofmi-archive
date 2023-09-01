#include <algorithm>
#include <iostream>

#include "reunion.h"

const double EPS = 1e-6;
bool is_equal(double r, double s) {
  return std::abs(r - s) / std::max(1.0, s) < EPS;
}

bool intersectanRangos(int n, int X[], int V[], double t) {
  double minimo = -1e9, maximo = 1e9;
  for (int i = 0; i < n; ++i) {
    double ini = X[i] - V[i] * t;
    double fin = X[i] + V[i] * t;
    minimo = std::max(minimo, ini);
    maximo = std::min(maximo, fin);
  }
  return minimo <= maximo;
}

double reunionOficial(int n, int X[], int V[]) {
  double low = 0, high = 1e9;
  for (int i = 0; i < 100; ++i) {
    double mid = (low + high) / 2;
    if (intersectanRangos(n, X, V, mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return low;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Leemos n
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
  double ans = reunion(n, X, V);
  // Llamamos a la función oficial
  double ans_oficial = reunionOficial(n, X, V);

  if (is_equal(ans, ans_oficial)) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}
