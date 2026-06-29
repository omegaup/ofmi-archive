#include <iostream>
#include <queue>
#include <utility>

typedef std::pair<int, int> pii;

int main() {
  int n, conexiones_i;

  // Lista de conexiones ordenada por llenar
  // <Faltantes, Indice de Estrella>
  std::priority_queue<pii> lista_conexiones;

  pii top1, top2;
  std::vector<pii> conexiones_final;
  std::queue<pii> regresar;

  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> conexiones_i;

    // Solo me es relevante si necesita conexiones
    if (conexiones_i != 0)
      lista_conexiones.push(std::make_pair(conexiones_i, i));
  }

  while (lista_conexiones.empty() == false) {
    // Tomo la que tiene mas pendientes
    top1 = lista_conexiones.top();
    lista_conexiones.pop();

    // Tomo la segunda con mas pendientes
    for (int i = top1.first; i > 0; i--) {
      top2 = lista_conexiones.top();
      lista_conexiones.pop();

      // Las uno, guardo la conexion y reduzco en uno las que le faltan
      conexiones_final.push_back(std::make_pair(top1.second, top2.second));

      top1.first--;
      top2.first--;

      // Las guardo para regresarla luego si es necesario
      if (top2.first > 0) regresar.push(top2);
    }
    while (regresar.empty() == false) {
      lista_conexiones.push(regresar.front());
      regresar.pop();
    }
  }

  std::cout << conexiones_final.size() << "\n";
  for (int i = 0; i < conexiones_final.size(); i++) {
    std::cout << conexiones_final[i].first << " " << conexiones_final[i].second
              << "\n";
  }
}
