#include <iostream>
#include <vector>

#include "computadoras.h"

bool didSampleCase(int n, int p, int m, int P[], int M[], int ans) {
  // Caso de ejemplo
  int n_sample = 5;
  int p_sample = 11;
  int m_sample = 9;
  int P_sample[] = {18, 23, 9, 3, 14};
  int M_sample[] = {18, 22, 11, 5, 16};
  int ans_sample = 4;
  bool is_sample_case = true;

  if (n != n_sample) {
    is_sample_case = false;
  }
  if (p != p_sample) {
    is_sample_case = false;
  }
  if (m != m_sample) {
    is_sample_case = false;
  }
  for (int i = 0; i < n_sample; ++i) {
    if (P[i] != P_sample[i]) {
      is_sample_case = false;
    }
    if (M[i] != M_sample[i]) {
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

const int MAXN = 5002;

int n;
int p, m;
int P[MAXN], M[MAXN];

std::vector<int> presentadas;
bool presentadoCorrectamente = true;
bool presentoComputadoraOFMI = false;
int ultimaPresentada = -1;  // índice de la última computadora presentada
bool presenta(int identificador) {
  std::clog << "Llamaste a presenta(" << identificador << ")" << std::endl;
  if (ultimaPresentada == -1) {
    if (identificador == 0) {
      ultimaPresentada = 0;
      presentadas.push_back(0);
      presentoComputadoraOFMI = true;
      return true;
    } else {
      std::cerr << "La primera computadora debe ser la ofmi" << std::endl;
      presentadoCorrectamente = false;
      return false;
    }
  }
  if (identificador < 0 || identificador > n) {
    std::cerr << "El índice de la computadora debe estar entre 0 y n"
              << std::endl;
    presentadoCorrectamente = false;
    return false;
  }
  int pUltima = ultimaPresentada == 0 ? p : P[ultimaPresentada - 1];
  int mUltima = ultimaPresentada == 0 ? m : M[ultimaPresentada - 1];
  if (P[identificador - 1] <= pUltima) {
    std::cerr << "La computadora " << identificador
              << " no es más potente que la última presentada "
              << ultimaPresentada << std::endl;
    presentadoCorrectamente = false;
    return false;
  }
  if (M[identificador - 1] <= mUltima) {
    std::cerr << "La computadora " << identificador
              << " no tiene más memoria que la última presentada "
              << ultimaPresentada << std::endl;
    presentadoCorrectamente = false;
    return false;
  }
  presentadas.push_back(identificador);
  ultimaPresentada = identificador;
  return true;
}

int main() {
  // Leemos n
  std::cin >> n;
  // Leemos p y m
  std::cin >> p >> m;
  // Leemos las otras n computadoras
  for (int i = 0; i < n; ++i) {
    std::cin >> P[i] >> M[i];
  }

  // Llamamos a la solución de la participante
  computadoras(n, p, m, P, M);

  if (presentadoCorrectamente && presentoComputadoraOFMI &&
      didSampleCase(n, p, m, P, M, presentadas.size())) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}
