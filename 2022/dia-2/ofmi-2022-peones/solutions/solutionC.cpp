#include <iostream>

const int NEGRO = 1;

int main() {
  int n, m;
  int negros[101];
  int fila_inicial, fila_final, columna_inicial, columna_final;
  std::cin >> n >> m;

  for (int fila = 1; fila <= n; fila++) {
    for (int columna = 1; columna <= m; columna++) {
      int peon = 0;
      std::cin >> peon;
      if (peon == NEGRO) {
        negros[columna] = fila;
      }
    }
  }

  fila_inicial = n;
  columna_inicial = 1;

  std::cin >> fila_final >> columna_final;

  int pasos = -1;

  if (fila_final == fila_inicial) {
    // caso donde esta en la misma fila
    if (columna_final == columna_inicial) {
      pasos = 0;
    }
    std::cout << pasos << std::endl;
    return 0;
  }

  if (columna_inicial == columna_final) {
    // caso donde esta en la misma columna
    int peon_negro = negros[columna_inicial];

    if (peon_negro < fila_final || peon_negro > fila_inicial) {
      // caso donde no hay peon entre el inicio y el fin
      pasos = fila_inicial - fila_final;
    } else {
      if (columna_inicial < n && peon_negro < fila_inicial - 1) {
        // caso donde el peon negro esta entre el inicio y el fin
        int vecino = negros[columna_inicial + 1];
        if (vecino <= peon_negro) {
          // caso donde el vecino esta atras del peon negro
          pasos = fila_inicial - fila_final + peon_negro - vecino + 1;
        } else {
          // caso donde el vecino esta entre el inicio y el peon negro
          if (vecino < fila_inicial) {
            pasos = fila_inicial - fila_final;
          }
        }
      }
    }
  } else {
    int pasos_negros = 0;
    int fila = fila_final;
    for (int i = columna_final; i > columna_inicial; i--) {
      if (fila > fila_inicial) {
        break;
      }

      if (negros[i] <= fila) {
        pasos_negros += fila - negros[i];
        fila++;
      } else {
        fila = negros[i] + 1;
      }

      // std::cout << "columna " << i << " fila " << fila << " pasos " <<
      // pasos_negros << std::endl;
    }

    if (fila <= negros[columna_inicial]) {
      pasos_negros += negros[columna_inicial] - fila + 1;
    }

    if (fila > fila_inicial) {
      pasos = -1;
    } else {
      pasos = fila_inicial - fila_final + pasos_negros;
    }
  }
  std::cout << pasos << std::endl;
  return 0;
}
