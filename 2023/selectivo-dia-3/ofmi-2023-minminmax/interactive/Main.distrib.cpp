#include <iostream>

#include "minminmax.h"

bool didSampleCase(int n, int m, int A[], int ans) {
  // Caso de ejemplo
  int n_sample = 5, m_sample = 2;
  int A_sample[] = {9, 8, 7, 6, 5};
  int ans_sample = 5;
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
    if (ans == ans_sample) {
      std::clog << "Respuesta correcta!" << std::endl;
    } else {
      std::clog << "Respuesta incorrecta!" << std::endl;
      std::clog << "Respuesta esperada: " << ans_sample << std::endl;
    }
    return ans == ans_sample;
  } else {
    std::clog << "Nota: No podemos verificar que la respuesta sea "
                 "verdaderamente correcta"
              << std::endl;
    return true;
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
  std::clog << "Llamando a minMinMax(" << n << ", " << m << ")..." << std::endl;
  int ans = minMinMax(n, m, A);

  // Imprimimos la respuesta
  std::clog << "Resultado: " << ans << std::endl;

  if (didSampleCase(n, m, A, ans)) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
