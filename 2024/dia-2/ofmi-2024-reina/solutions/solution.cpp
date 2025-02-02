#include <algorithm>
#include <iostream>
#include <vector>

const int MaxN = 1e6 + 10;

int N;
bool es_fila_atacada[MaxN];
bool es_columna_atacada[MaxN];
bool diagonal_principal[2 * MaxN];
bool diagonal_secundaria[2 * MaxN];

int mov_caballos[8][2] = {{2, 1},  {2, -1},  {1, 2},  {1, -2},
                          {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
std::vector<std::pair<int, int> > posibles_posiciones_de_los_caballos;

bool es_posicion_valida(int x, int y) {
  // Checar que este en el tablero
  if (x < 1 || x > N || y < 1 || y > N) {
    return false;
  }
  // Checar fila y columna
  if (es_fila_atacada[x] || es_columna_atacada[y]) {
    return false;
  }
  // Checar las diagonales
  if (diagonal_secundaria[x + y] || diagonal_principal[x - y + MaxN]) {
    return false;
  }
  // Posicion valida hasta el momento
  return true;
}

// Funcion para obtener las posiciones validas para la reina
std::vector<std::pair<int, int> >
obtener_posibles_movimientos_de_la_reina_ordenados(int x_reina, int y_reina) {
  std::vector<std::pair<int, int> > posibles_movimientos_de_la_reina;
  // Recorremos las posiciones desde la primer fila hasta la ultima, de
  // izquierda a derecha para ir guardando las posiciones posibles de menor a
  // mayor
  for (int i = 1; i <= N; ++i) {
    std::vector<int> y_posibles;
    if (i == x_reina) {
      for (int j = 1; j <= N; ++j) {
        y_posibles.push_back(j);
      }
    } else {
      // Diagonal principal
      y_posibles.push_back(i - x_reina + y_reina);
      // Columna
      y_posibles.push_back(y_reina);
      // Diagonal secundaria
      y_posibles.push_back(x_reina + y_reina - i);
    }

    for (int j = 0; j < y_posibles.size(); ++j) {
      if (es_posicion_valida(i, y_posibles[j])) {
        posibles_movimientos_de_la_reina.push_back(
            std::make_pair(i, y_posibles[j]));
      }
    }
  }

  std::sort(posibles_movimientos_de_la_reina.begin(),
            posibles_movimientos_de_la_reina.end());

  return posibles_movimientos_de_la_reina;
}

int main() {
  int K;
  int x_reina, y_reina;

  std::cin >> N >> K;
  std::cin >> x_reina >> y_reina;
  for (int i = 0; i < K; ++i) {
    char pieza;
    int x, y;
    std::cin >> pieza >> x >> y;
    if (pieza == 'A') {
      // Marcamos las diagonales de (x, y) como atacadas
      diagonal_secundaria[x + y] = true;
      diagonal_principal[x - y + MaxN] = true;
    } else if (pieza == 'T') {
      // Marcar la columan [y] y el renglon [x] como atacados
      es_fila_atacada[x] = true;
      es_columna_atacada[y] = true;
    } else if (pieza == 'C') {
      // Guardar las posiciones del caballo
      posibles_posiciones_de_los_caballos.push_back(std::make_pair(x, y));
      // Guardar las posiciones atacadas por caballos
      for (int j = 0; j < 8; ++j) {
        int x_ataque = x + mov_caballos[j][0];
        int y_ataque = y + mov_caballos[j][1];
        posibles_posiciones_de_los_caballos.push_back(
            std::make_pair(x_ataque, y_ataque));
      }
    }
  }
  // Ordenamos las posiciones donde pueden estar los caballos
  std::sort(posibles_posiciones_de_los_caballos.begin(),
            posibles_posiciones_de_los_caballos.end());

  // Obtenemos las posiciones donde la reina se puede mover y que a la vez
  // no son atacadas por torres o alfiles
  // Estan posiciones ya estan ordenadas por la forma en que las construimos
  std::vector<std::pair<int, int> > posibles_movimientos_de_la_reina =
      obtener_posibles_movimientos_de_la_reina_ordenados(x_reina, y_reina);

  // Comparamos y buscamos por alguna posicion en
  // [posibles_movimientos_de_la_reina] que no este en
  // [posibles_posiciones_de_los_caballos] para garantizar que ninguna pieza nos
  // pueda atacar
  int posible_caballo = 0;
  for (int i = 0; i < posibles_movimientos_de_la_reina.size(); ++i) {
    std::pair<int, int> posicion_reina = posibles_movimientos_de_la_reina[i];

    bool atacan_a_la_reina = false;
    while (posible_caballo < posibles_posiciones_de_los_caballos.size()) {
      std::pair<int, int> posicion_caballo =
          posibles_posiciones_de_los_caballos[posible_caballo];
      if (posicion_caballo < posicion_reina) {
        // La posicion del caballo es menor
        ++posible_caballo;
      } else {
        if (posicion_caballo == posicion_reina) {
          // Checamos si la posicion es atacada u ocupada por un caballo
          atacan_a_la_reina = true;
        }
        break;
      }
    }

    if (!atacan_a_la_reina) {
      // Nadie ataco a la reina, entonces podemos movernos a [posicion_reina]
      std::cout << posicion_reina.first << " " << posicion_reina.second << "\n";
      return 0;
    }
  }
  // Si llegamos hasta aqui, significa que no encontramos una posicion de reina
  // valida Entonces nuestra respuesta es -1
  std::cout << "-1\n";
  return 0;
}
