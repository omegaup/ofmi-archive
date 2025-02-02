#include <fstream>
#include <iostream>
#include <set>
#include <string>

const int MaxN = 1e6 + 1;

int N;
char pieza[MaxN];
int x[MaxN], y[MaxN];

bool movimiento_torre(int x, int y, int a, int b) { return x == a || y == b; }

bool movimiento_alfil(int x, int y, int a, int b) {
  return x - y == a - b || x + y == a + b;
}

bool movimiento_reina(int x, int y, int a, int b) {
  return movimiento_torre(x, y, a, b) || movimiento_alfil(x, y, a, b);
}

int caballo[8][2] = {{2, 1},  {2, -1},  {1, 2},  {1, -2},
                     {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
bool movimiento_caballo(int x, int y, int a, int b) {
  for (int i = 0; i < 8; i++) {
    if (x + caballo[i][0] == a && y + caballo[i][1] == b) {
      return true;
    }
  }
  return false;
}

bool movimiento_dentro_del_tablero(int x, int y) {
  return 1 <= x && x <= N && 1 <= y && y <= N;
}

int main() {
  // Leemos el caso.in
  int K;
  int x_inicial, y_inicial;
  {
    std::ifstream din("data.in", std::ifstream::in);
    din >> N >> K;
    din >> x_inicial >> y_inicial;
    for (int i = 0; i < K; i++) {
      din >> x[i] >> y[i];
    }
  }

  // Checamos si existe solucion con el .out
  bool solutionExists;
  {
    std::ifstream din("data.out", std::ifstream::in);
    long long x_output;
    din >> x_output;
    solutionExists = (x_output != -1);
  }

  // Leemos la salida del concursante
  long long x_contest;
  if (!(std::cin >> x_contest)) {
    std::cerr << "Error reading contestant output\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // Checamos si la respuesta coicide
  // No existe solucion
  if (!solutionExists && x_contest == -1) {
    if ((std::cin >> x_contest)) {
      std::cerr << "Contestant output is incorrect\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    std::cout << 1.0 << '\n';
    return 0;
  }
  if (!solutionExists) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // Si existe una solucion y la concursante dijo una posicion
  long long y_contest;
  if (!(std::cin >> y_contest)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // La concursante puso numeros de mas
  if ((std::cin >> y_contest)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  if (!movimiento_dentro_del_tablero(x_contest, y_contest)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  if (!movimiento_reina(x_inicial, y_inicial, x_contest, y_contest)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  for (int i = 0; i < K; i++) {
    bool ataque_alfil =
        pieza[i] == 'A' && movimiento_alfil(x[i], y[i], x_contest, y_contest);
    bool ataque_caballo =
        pieza[i] == 'C' && movimiento_caballo(x[i], y[i], x_contest, y_contest);
    bool ataque_torre =
        pieza[i] == 'T' && movimiento_torre(x[i], y[i], x_contest, y_contest);
    // La pieza ataca a la posicion sugerida por la concursante
    if (ataque_alfil || ataque_caballo || ataque_torre) {
      std::cerr << "Contestant output is incorrect\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }

  // Si llega aqui es que la respuesta esta bien
  std::cout << 1.0 << '\n';
  return 0;
}
