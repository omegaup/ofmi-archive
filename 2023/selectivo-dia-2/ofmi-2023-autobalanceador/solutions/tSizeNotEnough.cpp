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
  int m = 0;
  char imposible[] = "IMPOSIBLE";
  char res[100002];
  for (int i = 0; i < n; i++) {
    char c = S[i];
    if (c == '(') {
      res[m++] = '(';
      suma += 1;
    } else if (c == ')') {
      res[m++] = ')';
      suma -= 1;
    } else {
      suma -= 1;
      comodines -= 1;
      if (comodines == 0 && last_comodin_extra > 0) {
        suma -= last_comodin_extra;
        for (int j = 0; j < last_comodin_extra + 1; j++) {
          res[m++] = ')';
        }
      } else {
        res[m++] = ')';
      }
    }
    if (suma < 0) {
      respuesta(9, imposible);
      return;
    }
  }
  if (suma != 0) {
    respuesta(9, imposible);
    return;
  }

  respuesta(m, res);
}
