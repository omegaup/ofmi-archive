// Subtarea 1: n = 8
//
// En esta subtarea, el tablero es de 8x8. Esto significa
// que podemos guardar de forma explicita que posiciones
// estan siendo atacadas.
//
// Lo hacemos para cada pieza, y buscamos entre las posiciones
// que puede tener la reina por alguna que este disponible.
#include <iostream>

const int MaxN = 1010;
// En un tablero guardamos las posiciones atacadas
bool tablero[MaxN][MaxN];

int N;

// Coloreamos las posiciones que puede atacar la torre en (x, y)
void colorear_torre(int x, int y) {
  for (int i = 1; i <= N; ++i) {
    // Toda la fila [x]
    tablero[x][i] = true;
    // Toda la columna [y]
    tablero[i][y] = true;
  }
}

bool es_atacado_por_alfil(int x_alfil, int y_alfil, int x, int y) {
  return x_alfil - y_alfil == x - y || x_alfil + y_alfil == x + y;
}

// Coloreamos las posiciones que puede atacar el alfil en (x, y)
void colorear_alfil(int x, int y) {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (es_atacado_por_alfil(x, y, i, j)) {
        tablero[i][j] = true;
      }
    }
  }
}

bool es_posible_para_reina(int x_reina, int y_reina, int x, int y) {
  return x_reina == x || y_reina == y ||
         es_atacado_por_alfil(x_reina, y_reina, x, y);
}

bool esta_dentro_del_tablero(int x, int y) {
  return 1 <= x && x <= N && 1 <= y && y <= N;
}

// Coloreamos las posiciones que puede atacar y estar el caballo desde (x, y)
int caballo[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                     {1, -2},  {1, 2},  {2, -1},  {2, 1}};
void colorear_caballo(int x, int y) {
  tablero[x][y] = true;
  for (int i = 0; i < 8; ++i) {
    int x_caballo = x + caballo[i][0];
    int y_caballo = y + caballo[i][1];
    if (esta_dentro_del_tablero(x_caballo, y_caballo)) {
      tablero[x_caballo][y_caballo] = true;
    }
  }
}

int main() {
  int K;
  std::cin >> N >> K;

  int x_reina, y_reina;
  std::cin >> x_reina >> y_reina;

  // Dependiendo del tipo de pieza, coloreamos el tablero
  for (int i = 0; i < K; ++i) {
    char pieza;
    int x, y;
    std::cin >> pieza >> x >> y;
    if (pieza == 'T') {
      colorear_torre(x, y);
    } else if (pieza == 'A') {
      colorear_alfil(x, y);
    } else if (pieza == 'C') {
      colorear_caballo(x, y);
    }
  }

  // Para cada posicion, checamos si la reina puede llegar a esa posicion
  // y ademas si la posicion no es atacada u ocupada por otra pieza
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (es_posible_para_reina(x_reina, y_reina, i, j) && !tablero[i][j]) {
        std::cout << i << " " << j << "\n";
        return 0;
      }
    }
  }

  // Si no encontramos una pieza, imprimimos -1
  std::cout << "-1\n";
  return 0;
}
