#include <iostream>

#include "maldoso.h"

typedef long long lld;
const int MAXN = 1e4;

int n;
lld A_modificada[MAXN];
int A_ini[MAXN];

void imprimeArreglo(int A[]) {
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

int num_preguntas = 0;
lld pregunta(int i, int j) {
  ++num_preguntas;
  std::clog << "Llamando a pregunta(" << i << "," << j << ")...";
  if (i == j) {
    std::cerr << "Los indices (i, j) deben ser distintos." << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  if (i < 0 || j < 0 || i >= n || j >= n) {
    std::cerr << "Indices fuera del rango." << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  lld x = A_modificada[i];
  lld y = A_modificada[j];
  A_modificada[i] = x + y;
  A_modificada[j] = x - y;
  std::clog << " Devolvio: " << A_modificada[j] << std::endl;
  return A_modificada[j];
}

bool respuesta_called_once = false;
bool igual_a_inicio = false;
void respuesta(int n_participante, int A[]) {
  if (respuesta_called_once) {
    std::cerr << "Llamaste a respuesta mas de una vez" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  if (n_participante != n) {
    std::cerr << "La n no coincide con la n inicial" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  std::clog << "Llamaste a respuesta(";
  imprimeArreglo(A);
  std::clog << ")...";
  respuesta_called_once = true;
  igual_a_inicio = true;
  for (int i = 0; i < n; ++i) {
    igual_a_inicio &= (A[i] == A_ini[i]);
  }
}

int main() {
  // Leemos n
  std::cin >> n;
  // Leemos el arreglo A
  for (int i = 0; i < n; ++i) {
    std::cin >> A_ini[i];
    // Hacemos una copia para la concursante
    A_modificada[i] = A_ini[i];
  }
  // Llamamos a la función de la participante
  std::clog << "Llamando a maldoso(" << n << ")..." << std::endl;
  maldoso(n);

  std::clog << "Llamaste a pregunta " << num_preguntas << " veces."
            << std::endl;
  if (igual_a_inicio && respuesta_called_once) {
    std::clog << "Respuesta correcta!" << std::endl;
    std::cout << 1 << std::endl;
  } else {
    std::clog << "Respuesta incorrecta :(" << std::endl;
    std::clog << "El arreglo inicial era: ";
    imprimeArreglo(A_ini);
    std::clog << std::endl;
    std::cout << 0 << std::endl;
  }

  return 0;
}
