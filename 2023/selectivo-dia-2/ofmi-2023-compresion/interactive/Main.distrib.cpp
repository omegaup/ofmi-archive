#include <iostream>

#include "compresion.h"

bool didSampleCase(int n, int m, int A[], int ans) {
  // Caso de ejemplo
  int n_sample = 6, m_sample = 2;
  int A_sample[] = {4, 3, 4, 5, 6, 5};
  int ans_sample = 2;
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

const int MAXN = 300000;
int n, m;
int A[MAXN];
bool llamaste_a_aplastar = false;

void aplasta(int a, int b) {
  std::clog << "Llamando a aplasta(" << a << ", " << b << ")..." << std::endl;

  if (llamaste_a_aplastar) {
    std::cerr << "Llamaste a aplasta más de una vez!" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  llamaste_a_aplastar = true;
  if (a > b) {
    std::cerr << "Llamaste a aplasta con rango inválido!" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] < a) {
      A[i] = a;
    }
    if (A[i] > b) {
      A[i] = b;
    }
  }

  std::clog << "El arreglo final es: [";
  for (int i = 0; i < n; ++i) {
    std::clog << A[i] << (i + 1 == n ? "" : ", ");
  }
  std::clog << "]" << std::endl;
}

int main() {
  // Leemos n y m
  std::cin >> n >> m;
  // Leemos el arreglo A
  int A_copy[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
    A_copy[i] = A[i];
  }
  // Llamamos a la función de la participante
  std::clog << "Llamando a compresion(" << n << ", " << m << ")..."
            << std::endl;
  int ans = compresion(n, m, A);

  // Imprimimos la respuesta
  std::clog << "Tu funcion compresion devolvio: " << ans << std::endl;

  if (didSampleCase(n, m, A_copy, ans)) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
