#include <iostream>
#include <string>

#include "autobalanceador.h"

// Si hay exactamente uno, entonces le tenemos que poner
// exactamente la suma final
void balancea(int n, char S[]) {
  int sumaFinal = 0;
  for (int i = 0; i < n; i++) {
    char c = S[i];
    if (c == '(') {
      sumaFinal += 1;
    } else {
      sumaFinal -= 1;
    }
  }

  if (sumaFinal < 0) {
    respuesta(9, "IMPOSIBLE");
    return;
  }

  // Reemplazamos el unico ] por sumaFinal veces )
  std::string res = "";
  int suma = 0;
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
      res += ')';
      // Agregamos sumaFinal un )
      for (int j = 0; j < sumaFinal; j++) {
        suma -= 1;
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
