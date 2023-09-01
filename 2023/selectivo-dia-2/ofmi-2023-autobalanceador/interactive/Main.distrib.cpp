#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

#include "autobalanceador.h"

const int LIMIT_DEPTH = 1000000000;
int ops = 0;
bool warning_printed = false;
bool isBalanced(const std::string &S, int i, int j) {
  if (ops > LIMIT_DEPTH) {
    if (!warning_printed) {
      std::clog << "Warning: isBalanced tardo demasiado, se asume que esta "
                << "balanceado aunque podria no estarlo." << std::endl;
      warning_printed = true;
    }
    return true;
  }
  ops += 1;
  if (i >= j) return true;
  if (i == j) return false;
  if (S[i] != '(') return false;
  for (int k = i + 1; k <= j; k++) {
    if (S[k] == ')' && isBalanced(S, i + 1, k - 1) && isBalanced(S, k + 1, j)) {
      return true;
    }
  }
  return false;
}

bool couldBuildFromS(const std::string &S, const std::string &T) {
  std::string reg;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == ']') {
      reg += "\\)+";
    } else {
      reg += "\\";
      reg += S[i];
    }
  }
  std::regex pattern("^" + reg + "$");
  if (std::regex_search(T, pattern)) {  // Search the string for matches
    return true;
  }
  return false;
}

std::string contestantAnswer;
bool respuesta_llamada = false;
void respuesta(int m, char S[]) {
  if (respuesta_llamada) {
    std::cerr << "La función respuesta fue llamada más de una vez" << std::endl;
    std::cout << 0 << std::endl;
    exit(1);
  }
  respuesta_llamada = true;
  for (int i = 0; i < m; i++) {
    contestantAnswer += S[i];
  }
}

int main() {
  // Leemos n y S
  int n;
  std::string S;
  std::cin >> n >> S;

  // Creamos una copia de S en un arreglo de chars
  char S_copy[S.size() + 1];  // +1 for null terminator
  std::copy(S.begin(), S.end(), S_copy);
  S_copy[S.size()] = '\0';  // Adding null terminator

  // Mandamos a llamar a la función de la participante
  std::clog << "Llamando a tu funcion balancea(" << n << ", '" << S_copy << "')"
            << std::endl;
  balancea(n, S_copy);

  std::clog << "Tu funcion regreso '" << contestantAnswer << "'" << std::endl;
  if (!respuesta_llamada) {
    std::cerr << "La función respuesta no fue llamada" << std::endl;
    std::cout << 0 << std::endl;
    return 1;
  }

  // Checamos si contestó imposible
  if (contestantAnswer == "IMPOSIBLE") {
    std::clog << "Warning: se asume que la respuesta es IMPOSIBLE aunque "
              << "podria ser posible." << std::endl;
    std::cout << 1 << std::endl;
    return 0;
  }

  // Verificamos que la respuesta sea válida
  bool isBalancedAnswer =
      isBalanced(contestantAnswer, 0, contestantAnswer.size() - 1);
  bool isComingFromS = couldBuildFromS(S, contestantAnswer);
  if (isBalancedAnswer && isComingFromS) {
    std::clog << "Respuesta correcta" << std::endl;
    std::cout << 1 << std::endl;
  } else {
    std::clog << "Respuesta incorrecta :(" << std::endl;
    if (!isBalancedAnswer) {
      std::clog << "No esta balanceado." << std::endl;
    } else if (!isComingFromS) {
      std::clog << "No es un string valido." << std::endl;
    }
    std::cout << 0 << std::endl;
  }
  return 0;
}
