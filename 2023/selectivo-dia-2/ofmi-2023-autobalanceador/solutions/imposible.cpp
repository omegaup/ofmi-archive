#include <iostream>
#include <string>

#include "autobalanceador.h"

// Es checar si está o no balanceado
void balancea(int n, char S[]) {
  std::string res = "IMPOSIBLE";
  // Creamos una copia de respuesta en un arreglo de chars
  char respuesta_copy[res.size() + 1];  // +1 for null terminator
  std::copy(res.begin(), res.end(), respuesta_copy);
  respuesta_copy[res.size()] = '\0';  // Adding null terminator

  respuesta(res.size(), respuesta_copy);
}
