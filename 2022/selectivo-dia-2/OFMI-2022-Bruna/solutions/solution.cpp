#include <iostream>
#include <vector>

#include "bruna.h"

const int PROFUNDIDAD_MAXIMA = 30;  // ⌈log_2(10 ^ 9)⌉

class Nodo {
 public:
  int padre;
  std::vector<long long> ganancias_hijos;
};

class Arbol {
 private:
  std::vector<Nodo> lista_nodos;

 public:
  Arbol(int n) {
    lista_nodos = std::vector<Nodo>(
        n + 1, {-1, std::vector<long long>(PROFUNDIDAD_MAXIMA, 0LL)});
  }

  void agregar_padre(int nodo, int padre) { lista_nodos[nodo].padre = padre; }

  void sumar_ganancias(int nodo, int ganancias) {
    for (long long& ganancia_hijos : lista_nodos[nodo].ganancias_hijos) {
      ganancia_hijos += (long long)(ganancias);
      ganancias /= 2;
    }
  }

  long long obtener_ganancias(int nodo) {
    long long respuesta = 0LL;
    for (int num_hijo = 0; nodo != -1 && num_hijo < PROFUNDIDAD_MAXIMA;
         num_hijo++) {
      respuesta += lista_nodos[nodo].ganancias_hijos[num_hijo];
      nodo = lista_nodos[nodo].padre;
    }
    return respuesta;
  }
};

Arbol arbol(1);

void familiaBruna(int N, int mama[]) {
  arbol = Arbol(N);
  for (int i = 1; i <= N; i++) {
    arbol.agregar_padre(i, mama[i - 1]);
  }
}

void depositarDinero(int idx, int X) { arbol.sumar_ganancias(idx, X); }

long long int checarCuenta(int idx) { return arbol.obtener_ganancias(idx); }
