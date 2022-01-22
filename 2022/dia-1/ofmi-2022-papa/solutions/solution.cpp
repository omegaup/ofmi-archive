#include <iostream>

int main() {
  int maeva, lorena, ramona;
  // Leemos el tiempo que espera Maeva, Lorena, y Ramona
  std::cin >> maeva >> lorena >> ramona;

  int tiempo = 0;

  // Simulamos el juego de la cobaya caliente con un "mientras"
  while (tiempo < 45) {
    // Se agrega el tiempo de Maeva para checar si Maeva recibe la mordida de la
    // cobaya (tiempo mayor o igual a 45)
    tiempo += maeva;
    if (tiempo < 45) {
      // Se agrega el tiempo de Lorena para checar si Lorena recibe la mordida
      // de la cobaya (tiempo mayor o igual a 45)
      tiempo += lorena;
      if (tiempo < 45) {
        tiempo += ramona;
        // Se agrega el tiempo de Ramona para checar si Ramona recibe la mordida
        // de la cobaya (tiempo mayor o igual a 45)
        if (tiempo >= 45) {
          // Imprimimos que recibe la mordida de la cobaya Ramona
          std::cout << "Ramona" << std::endl;
        }
      } else {
        // Imprimimos que recibe la mordida de la cobaya Lorena
        std::cout << "Lorena" << std::endl;
      }
    } else {
      // Imprimimos que recibe la mordida de la cobaya Maeva
      std::cout << "Maeva" << std::endl;
    }
  }

  return 0;
}