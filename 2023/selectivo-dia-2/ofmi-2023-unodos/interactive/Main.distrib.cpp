#include <iostream>

#include "unodos.h"

const double EPS = 1e-6;

const int MAXN = 100002;
const int MAXM = 200002;
int n, m;

int U[MAXM], V[MAXM], T[MAXM];
bool asignado[MAXN];
double valorAsignado[MAXN];

bool asignado_correctamente = true;
int num_asignados = 0;
double sumaValoresAbsolutos = 0.0;
bool asigna(int v, double x) {
  std::clog << "Llamaste a asigna(" << v << ", " << x << ")" << std::endl;
  if (v <= 0 || v > n) {
    std::cerr << "Vertice invalido: " << v << std::endl;
    asignado_correctamente = false;
    return false;
  }
  if (asignado[v]) {
    std::cerr << "Ya habias asignado valor a " << v << std::endl;
    asignado_correctamente = false;
    return false;
  }
  num_asignados++;
  asignado[v] = true;
  valorAsignado[v] = x;
  sumaValoresAbsolutos += std::abs(x);
  return true;
}

bool is_equal(double r, double s) { return std::abs(r - s) <= EPS; }

bool isSampleCase(int n, int m, int U[], int V[], int T[]) {
  // Caso de ejemplo
  int n_sample = 5;
  int m_sample = 4;
  int U_sample[] = {2, 4, 3, 2};
  int V_sample[] = {4, 5, 4, 3};
  int T_sample[] = {2, 1, 2, 1};

  if (n != n_sample) {
    return false;
  }
  if (m != m_sample) {
    return false;
  }
  for (int i = 0; i < m_sample; ++i) {
    if (U[i] != U_sample[i]) {
      return false;
    }
    if (V[i] != V_sample[i]) {
      return false;
    }
    if (T[i] != T_sample[i]) {
      return false;
    }
  }
  return true;
}

bool didSampleCase(int n, int m, int U[], int V[], int T[], double ans) {
  if (isSampleCase(n, m, U, V, T)) {
    double ans_sample = 3.0;
    if (is_equal(ans, ans_sample)) {
      std::clog << "Respuesta correcta!" << std::endl;
    } else {
      std::cerr << "Respuesta esperada: " << ans_sample << std::endl;
    }
    return is_equal(ans, ans_sample);
  } else {
    std::clog << "Nota: No podemos verificar que la respuesta sea "
                 "verdaderamente correcta"
              << std::endl;
    return true;
  }
}

double respuestaCorrecta(bool posible) {
  if (!posible && !isSampleCase(n, m, U, V, T)) {
    std::clog << "Regresaste que es imposible hacer la asignacion" << std::endl;
    std::clog << "Nota: No podemos verificar que la respuesta sea "
                 "verdaderamente correcta"
              << std::endl;
    return true;
  }
  // Checamos que hayamos asignado correctamente valor a todos los nodos
  if (num_asignados < n || !asignado_correctamente) {
    std::cerr << "No asignaste valor correctamente a todos los nodos"
              << std::endl;
    return false;
  }
  // Checamos que todas las aristas cumplan con la condicion
  for (int i = 0; i < m; ++i) {
    double sumaArista = valorAsignado[U[i]] + valorAsignado[V[i]];
    if (T[i] == 1) {
      if (!is_equal(sumaArista, 1.0)) {
        std::cerr << "La arista (" << U[i] << ", " << V[i] << ") no cumple la "
                  << "condicion" << std::endl;
        return false;
      }
    } else {
      if (!is_equal(sumaArista, 2.0)) {
        std::cerr << "La arista (" << U[i] << ", " << V[i] << ") no cumple la "
                  << "condicion" << std::endl;
        return false;
      }
    }
  }
  std::clog << "Assignaste correctamente! La suma de valores absoluto fue: "
            << sumaValoresAbsolutos << std::endl;
  return didSampleCase(n, m, U, V, T, sumaValoresAbsolutos);
}

int main() {
  // Leemos la entrada
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> U[i] >> V[i] >> T[i];
  }
  // Llamamos a la función de la participante
  std::clog << "Llamando a unodos(" << n << ", " << m << ")..." << std::endl;
  bool posible = unoDos(n, m, U, V, T);

  // Checamos que la respuesta sea correcta
  if (respuestaCorrecta(posible)) {
    std::cout << 1.0 << std::endl;
  } else {
    std::cerr << "Respuesta incorrecta :(" << std::endl;
    std::cout << 0.0 << std::endl;
  }

  return 0;
}
