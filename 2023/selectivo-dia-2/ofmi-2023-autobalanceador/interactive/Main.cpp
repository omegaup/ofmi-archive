#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

#include "autobalanceador.h"

bool isBalanced(const std::string &s) {
  int balance = 0;
  for (char c : s) {
    if (c == '(') {
      balance++;
    } else {
      balance--;
    }
    if (balance < 0) {
      return false;
    }
  }
  return balance == 0;
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

bool isImpossibleImpl(const std::string &S) {
  int comodines = 0;
  int last_comodin_extra = 0;
  for (char c : S) {
    if (c == ']') {
      comodines++;
    }
    last_comodin_extra += (c == '(') ? 1 : -1;
  }
  int suma = 0;
  for (char c : S) {
    if (c == '(') {
      suma += 1;
    } else if (c == ')') {
      suma -= 1;
    } else {
      suma -= 1;
      comodines -= 1;
      if (comodines == 0 && last_comodin_extra > 0) {
        suma -= last_comodin_extra;
      }
    }
    if (suma < 0) {
      return true;
    }
  }
  return suma != 0;
}

std::string contestantAnswer;
bool respuesta_llamada = false;
void respuesta(int m, char S[]) {
  if (respuesta_llamada) {
    std::cerr << "La función respuesta fue llamada más de una vez" << std::endl;
    std::cout << 0 << std::endl;
    exit(0);
  }
  respuesta_llamada = true;
  for (int i = 0; i < m; i++) {
    contestantAnswer += S[i];
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Leemos n y S
  int n;
  std::string S;
  std::cin >> n >> S;

  // Creamos una copia de S en un arreglo de chars
  char S_copy[S.size() + 1];  // +1 for null terminator
  std::copy(S.begin(), S.end(), S_copy);
  S_copy[S.size()] = '\0';  // Adding null terminator

  // Mandamos a llamar a la función de la participante
  balancea(n, S_copy);
  if (!respuesta_llamada) {
    std::cerr << "La función respuesta no fue llamada" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }
  bool isImpossible = isImpossibleImpl(S);
  // Verificamos que la respuesta sea válida
  if ((isImpossible && contestantAnswer == "IMPOSIBLE") ||
      (isBalanced(contestantAnswer) && couldBuildFromS(S, contestantAnswer))) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}
