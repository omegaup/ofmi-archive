// Sub2: Dado que todas las espias son espiadas por otra espia, el grafo
// resultante esta compuesto de unicamente ciclos simples. Finalmente, podemos
// marcar los ciclos y determinar cual de ellos tiene mayor tamano.

#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<int> espia(n);
  for (int i = 0; i < n; ++i) {
    int u;
    std::cin >> u;
    espia[i] = u - 1;
  }

  int maximo_tamano = 0;
  std::vector<bool> visitado(n);

  for (int i = 0; i < n; ++i) {
    int tamano = 0;
    for (int u = i; !visitado[u]; ++tamano, u = espia[u]) visitado[u] = true;
    maximo_tamano = std::max(maximo_tamano, tamano);
  }
  std::cout << maximo_tamano << '\n';
}
