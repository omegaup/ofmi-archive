#include <iostream>
#include <regex>
#include <string>

#include "maldoso.h"

int getSubtask(const std::string& caseName) {
  std::regex pattern(".*sub(\\d+).*");
  std::smatch match;
  if (std::regex_search(caseName, match, pattern)) {
    std::string caseNumber = match[1];
    return std::stoi(caseNumber);
  }
  return -1;
}

typedef long long lld;
const int MAXN = 1e4;

int n;
lld A_modificada[MAXN];
int A_ini[MAXN];

int num_preguntas = 0;
lld pregunta(int i, int j) {
  ++num_preguntas;
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
  respuesta_called_once = true;
  igual_a_inicio = true;
  for (int i = 0; i < n; ++i) {
    igual_a_inicio &= (A[i] == A_ini[i]);
  }
}

int main(int argc, char* argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  // Leemos n
  std::cin >> n;
  // Leemos el arreglo A
  for (int i = 0; i < n; ++i) {
    std::cin >> A_ini[i];
    // Hacemos una copia para la concursante
    A_modificada[i] = A_ini[i];
  }
  // Llamamos a la función de la participante
  maldoso(n);

  int subtask = getSubtask(caseName);
  // No importa el numero de preguntas en el subtask 3
  bool calls_to_pregunta_ok = (subtask == 3) || (num_preguntas <= n);
  if (igual_a_inicio && respuesta_called_once && calls_to_pregunta_ok) {
    std::cout << 1 << std::endl;
  } else {
    std::cerr << "Respuesta incorrecta :(" << std::endl;
    std::cout << 0 << std::endl;
  }

  return 0;
}
