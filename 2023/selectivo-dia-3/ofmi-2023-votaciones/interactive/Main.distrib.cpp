#include <iostream>

#include "votaciones.h"

void imprimeArreglo(int n, int A[]) {
  if (n <= 0) {
    std::clog << "[]";
    return;
  }
  std::clog << "[" << A[0];
  for (int i = 1; i < n; ++i) {
    std::clog << ", " << A[i];
  }
  std::clog << "]";
}

bool didSampleCase(int n, int m, int A[], int ans[]) {
  // Caso de ejemplo

  int n_sample = 5, m_sample = 2;
  int A_sample[] = {0, 0, 1, 0, 0};
  int ans_sample[] = {1, 0, 1, 0, 0};
  bool is_sample_case = true;

  if (n != n_sample || m != m_sample) {
    is_sample_case = false;
  }
  for (int i = 0; i < n_sample; ++i) {
    if (A[i] != A_sample[i]) {
      is_sample_case = false;
    }
  }

  if (is_sample_case) {
    bool ans_same = true;
    for (int i = 0; i < n_sample; ++i) {
      if (ans[i] != ans_sample[i]) {
        ans_same = false;
      }
    }
    if (ans_same) {
      std::clog << "Respuesta correcta!" << std::endl;
    } else {
      std::clog << "Respuesta incorrecta!" << std::endl;
      std::clog << "Respuesta esperada: ";
      imprimeArreglo(n_sample, ans_sample);
      std::clog << std::endl;
    }
    return ans_same;
  } else {
    std::clog << "Nota: No podemos verificar que la respuesta sea "
                 "verdaderamente correcta"
              << std::endl;
    return true;
  }
}

const int MAXN = 1e6;
int ans_contestant[MAXN];
bool respuesta_llamada = false;
void resultados(int n, int R[]) {
  if (respuesta_llamada) {
    std::cerr << "Llamaste a respuesta mas de una vez" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  std::clog << "Llamaste a respuesta(";
  imprimeArreglo(n, R);
  std::clog << ")" << std::endl;
  respuesta_llamada = true;
  for (int i = 0; i < n; ++i) {
    ans_contestant[i] = R[i];
  }
}

int main() {
  // Leemos n y m
  int n, m;
  std::cin >> n >> m;
  // Leemos el arreglo A
  int A[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  // Llamamos a la función de la participante
  std::clog << "Llamando a votacion(" << n << ", " << m << ")" << std::endl;
  votacion(n, m, A);

  if (!respuesta_llamada) {
    std::cerr << "No llamaste a respuesta" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }

  if (didSampleCase(n, m, A, ans_contestant)) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
