#include <fstream>
#include <iostream>
#include <vector>

int main() {
  // Leemos el caso de prueba.
  int n, k;
  std::vector<int> puntajes;
  {
    std::ifstream caso("data.in", std::ifstream::in);
    caso >> n >> k;
    for (int i = 0; i < n; ++i) {
      int puntaje;
      caso >> puntaje;
      puntajes.push_back(puntaje);
    }
  }

  // Checamos cual es el tamano maximo esperado del rango.
  int tamano_esperado = 0;
  {
    std::ifstream caso("data.out", std::ifstream::in);
    int a, b;
    caso >> a;
    if (a > 0) {
      caso >> b;
      tamano_esperado = b - a + 1;
    }
  }

  // Leemos el primer valor de la salida de la concursante.
  int a;
  if (!(std::cin >> a)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << "0.0\n";
    return 0;
  }

  // Checamos si la concursante dijo que no hay rango.
  if (a == -1) {
    // La concursante imprimio mas que solo "-1".
    if ((std::cin >> a)) {
      std::cerr << "Contestant output is incorrect\n";
      std::cout << "0.0\n";
      return 0;
    }

    std::cout << (tamano_esperado ? "0.0\n" : "1.0\n");
    return 0;
  }

  // Leemos el segundo valor de la salida de la concursante.
  int b;
  if (!(std::cin >> b)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << "0.0\n";
    return 0;
  }

  // El rango tiene que cumplir que 1 <= a <= b <= n.
  if (!(1 <= a && a <= b && b <= n)) {
    std::cout << "0.0\n";
    return 0;
  }

  --a, --b;
  int mayores_que_k = 0;
  for (int i = a; i <= b; ++i) {
    mayores_que_k += (puntajes[i] >= k) ? 1 : 0;
  }

  // Checamos que los valores mayores o iguales a k son la mayoria absoluta.
  int tamano_concursante = b - a + 1;
  if (mayores_que_k < tamano_concursante / 2 + 1) {
    std::cout << "0.0\n";
    return 0;
  }

  // Si la concursante dio un rango de mayor tamano que la solucion oficial,
  // le damos puntos completos, pero la solucion oficial es incorrecta.
  if (tamano_concursante > tamano_esperado) {
    std::cerr << "Official solution is incorrect\n";
    std::cout << "Unexpected answer " << tamano_concursante << '\n';
    return 1;
  }

  // Checamos que el tamano del rango de la concursante sea el esperado.
  std::cout << ((tamano_concursante < tamano_esperado) ? "0.0\n" : "1.0\n");
  return 0;
}
