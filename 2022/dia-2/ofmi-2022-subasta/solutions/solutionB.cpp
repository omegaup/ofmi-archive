#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  // Variable para guardar el indice de la cobaya que ganó
  int ganador = 0;
  // Declaramos un vector donde guardamos solamente las pujas validas
  std::vector<int> pujas_validas{0, 0};

  // Iteramos por cada evento de la subasta
  for (int i = 1; i <= n; i++) {
    // Leemos la nueva puja
    int puja;
    std::cin >> puja;
    // Si la puja es mayor o igual a la suma de las dos validas anteriores
    // entonces esta se vuelve la mejor
    if (puja >=
        pujas_validas.back() + pujas_validas[pujas_validas.size() - 2]) {
      pujas_validas.push_back(puja);
      ganador = i;
    }
  }

  std::cout << ganador << std::endl;
}