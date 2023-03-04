#include <iostream>

int main() {
  int n, d;
  std::cin >> n >> d;         // Sabemos n = 1 para esta subtarea
  long long int escudos = 0;  // Aquí guardaremos la respuesta
  // Leemos la vida del unico zombie que hay
  int zombie;
  std::cin >> zombie;
  while (zombie > 0) {
    zombie -= d;
    escudos++;
  }
  // en el ultimo disparo el zombie ya no nos dispara de vuelta
  escudos--;  // por lo que el ultimo disparo no cuenta como escudo gastado
  std::cout << escudos << std::endl;
  return 0;
}
