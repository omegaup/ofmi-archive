#include <iostream>

constexpr int tableroMaximo = 102;
constexpr int inf = 1e9;

int tablero[tableroMaximo][tableroMaximo];

int numeroDeMovimientos(int origenX, int origenY, int destinoX, int destinoY) {
  int movimientos = 0;
  // vamos cambiando de columna hasta llegar a la columna destino
  while (origenX != destinoX) {
    if (origenX < destinoX) {
      origenX++;
    } else {
      origenX--;
    }
    origenY--;
    // si en la posicion actual el tablero tiene 0, significa que no hay peon
    // que podamos comer para cambiar de columna
    if (tablero[origenY][origenX] == 0) {
      return inf;
    }
    // de lo contrario solo sumamos el costo de comerlo
    movimientos += tablero[origenY][origenX];
  }

  // imprimimos el costo de llegar a la columna destino, y sumamos el costo de
  // movernos hasta la fila destino
  return movimientos + origenY - destinoY;
}

int main() {
  int n, m, origenX, origenY, destinoX, destinoY;
  std::cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> tablero[i][j];
    }
  }

  origenY = n;
  origenX = 1;

  std::cin >> destinoY >> destinoX;

  // cuando el destino esta atras de la posicion de origen
  if (destinoY > origenY) {
    std::cout << -1 << "\n";
    return 0;
  }

  // cuando el destino esta a la misma altura que la posicion de origen
  if (destinoY == origenY && origenX != destinoX) {
    std::cout << -1 << "\n";
    return 0;
  }

  // cuando el destino es el mismo que el origen
  if (destinoX == origenX && destinoY == origenY) {
    std::cout << 0 << "\n";
    return 0;
  }

  // precalculamos cuanto nos cuesta llevar un peon negro y comerlo para llegar
  // a una posicion
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (tablero[i - 1][j] > 0) {
        tablero[i][j] += tablero[i - 1][j] + 1;
      }
    }
  }

  // cuando el destino esta en la misma columna que el origen y hay un peon
  // entre el destino y el origen.
  if (origenX == destinoX && tablero[origenY][origenX] > 0) {
    // si no hay peones que podamos comer para llegar al destino, no hay
    // solucion
    if (tablero[origenY][origenX + 1] == 0 &&
        tablero[origenY][origenX - 1] == 0) {
      std::cout << -1 << "\n";
    } else if (tablero[origenY][origenX] <
               3) {  // requerimos al menos estar a 2 cuadros de distancia del
                     // peon
      std::cout << -1 << "\n";
    } else {
      // obtenemos la posicion donde esta el numero 3 en esta columna
      int posTresY = origenY - tablero[origenY][origenX] + 3;
      int total = origenY - posTresY;
      //¿tomamos izquierda o derecha?
      if (tablero[posTresY - 1][origenX + 1] == 0) {
        total += tablero[posTresY - 1][origenX - 1];
      } else if (tablero[posTresY - 1][origenX - 1] == 0) {
        total += tablero[posTresY - 1][origenX + 1];
      } else {
        total += std::min(tablero[posTresY - 1][origenX + 1],
                          tablero[posTresY - 1][origenX - 1]);
      }
      // sumamos todo lo que falta desde el peon de la columna original hasta el
      // destino. se suma uno por regresar a la columna principal
      total += (posTresY - 2) - destinoY + 1;
      std::cout << total << "\n";
    }
    return 0;
  }

  int minimaCantidadMovs = inf;
  // tratamos empezando en todos los cuadros antes de que el peon llegue a el
  // peon negro de esta forma nos vamos por todas las diagonales posibles rumbo
  // al destino
  for (int i = 0; tablero[origenY - i][origenX] > 1; i++) {
    int movsAux =
        numeroDeMovimientos(origenX, origenY - i, destinoX, destinoY) + i;
    minimaCantidadMovs = std::min(minimaCantidadMovs, movsAux);
  }

  // inf indica que nunca se encontro una solucion.
  if (minimaCantidadMovs >= inf) {
    std::cout << -1 << "\n";
  } else {
    std::cout << minimaCantidadMovs << "\n";
  }
  return 0;
}
