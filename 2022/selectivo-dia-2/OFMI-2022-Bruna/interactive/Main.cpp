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

int main() {
  int N, Q;

  std::cin >> N >> Q;
  int mama[N];
  for (int i = 0; i < N; i++) {
    std::cin >> mama[i];
  }

  // Inicializar en ambos lados
  familiaBruna(N, mama);

  // Construir arbol
  Arbol arbol = Arbol(N);
  for (int i = 1; i <= N; i++) {
    arbol.agregar_padre(i, mama[i - 1]);
  }

  for (int i = 0; i < Q; i++) {
    int op, idx, X;
    std::cin >> op >> idx;
    if (op == 1) {
      // Depositar
      std::cin >> X;
      // Depositar en ambos lados
      depositarDinero(idx, X);
      arbol.sumar_ganancias(idx, X);
    } else {
      // Checar cuenta
      long long int obtained = checarCuenta(idx);
      long long int expected = arbol.obtener_ganancias(idx);
      if (obtained != expected) {
        // Hay error, hay error
        fprintf(stderr, "op %d: idx %d; got %lld, expected %lld", i, idx,
                obtained, expected);
        printf("0.0\n");
        return 0;
      }
    }
  }

  // Respuestas correctas
  printf("1.0\n");
  return 0;
}
