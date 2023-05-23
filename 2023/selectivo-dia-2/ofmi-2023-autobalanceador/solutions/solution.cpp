#include <iostream>
#include <string>

#include "autobalanceador.h"

void balancea(int n, char S[]) {
  int comodines = 0;
  int last_comodin_extra = 0;
  for (int i = 0; i < n; i++) {
    char c = S[i];
    if (c == ']') {
      comodines++;
    }
    last_comodin_extra += (c == '(') ? 1 : -1;
  }
  int suma = 0;
  std::string res;
  for (int i = 0; i < n; i++) {
    char c = S[i];
    if (c == '(') {
      res += '(';
      suma += 1;
    } else if (c == ')') {
      res += ')';
      suma -= 1;
    } else {
      suma -= 1;
      comodines -= 1;
      if (comodines == 0 && last_comodin_extra > 0) {
        suma -= last_comodin_extra;
        res += std::string(last_comodin_extra + 1, ')');
      } else {
        res += ')';
      }
    }
    if (suma < 0) {
      res = "IMPOSIBLE";
      break;
    }
  }
  if (suma != 0) {
    res = "IMPOSIBLE";
  }

  // Creamos una copia de respuesta en un arreglo de chars
  char respuesta_copy[res.size() + 1];  // +1 for null terminator
  std::copy(res.begin(), res.end(), respuesta_copy);
  respuesta_copy[res.size()] = '\0';  // Adding null terminator

  respuesta(res.size(), respuesta_copy);
}
