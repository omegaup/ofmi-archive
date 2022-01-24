#include <iostream>
#include <vector>

const int MaxN = 102;

int N, M;
int x_salida, y_salida;
int mapa[MaxN][MaxN];

int buscar_peon(int columna) {
  // Buscamos la fila del peon en la columna 'columna'
  for (int i = 1; i <= N; ++i) {
    if (mapa[i][columna] == 1) {
      // Encontramos al peon
      return i;
    }
  }
  // No existe peon en la columna
  return -1;
}

int misma_columna() {
  // Checamos si podemos ir directo
  int peon_izquierda = buscar_peon(1);
  if (peon_izquierda < x_salida) {
    // Se logro sin zig-zag
    return N - x_salida;
  }

  // Tenemos que hacer un zig-zag para llegar a la salida
  int peon_derecha = buscar_peon(2);

  // Calcular el costo del camino
  int costo_camino = 0;

  if (peon_derecha == N) {
    // No es posible movernos a la derecha
    return -1;
  }
  if (peon_izquierda == N - 1) {
    // No es posible hacer zig-zag
    return -1;
  }

  // Mover el peon de la columna 1 a la salida
  if (peon_izquierda < x_salida) {
    costo_camino += x_salida - peon_izquierda;
    peon_izquierda = x_salida;
  }

  // Mover el peon de la derecha a una posicion factible
  if (peon_derecha < peon_izquierda + 1) {
    costo_camino += (peon_izquierda + 1) - peon_derecha;
    peon_derecha = peon_izquierda + 1;
  }

  // Iniciamos en la posicion (N, 1)

  // Nos movemos a la posicion (peon_derecha + 1, 1)
  costo_camino += N - (peon_derecha + 1);
  // Nos comemos al peon_derecha para estar en (peon_derecha, 2)
  costo_camino += 1;

  // Nos movemos a la posicion (peon_izquierda + 1, 2)
  costo_camino += (peon_izquierda + 1) - peon_derecha;
  // Nos comemos al peon_izquierda para estar en (peon_izquierda, 1)
  costo_camino += 1;

  // Nos movemos hasta la salida (x_salida, 1)
  costo_camino += peon_izquierda - x_salida;

  // Regresamos el costo
  return costo_camino;
}

int ir_al_destino() {
  if (N - x_salida < y_salida - 1) {
    // No es posible llegar a la columna destino
    return -1;
  }

  // Costo del camino
  // Inicia con los movs que realiza el peon blanco
  int costo_camino = N - x_salida;

  // Columna actual
  int y_actual = y_salida;
  // Fila que queremos cubrir con un peon
  int fila_objetivo = x_salida;

  while (y_actual > 1) {
    // Peon de la columna
    int x_actual = buscar_peon(y_actual);
    if (x_actual < fila_objetivo) {
      // Movemos el peon a la fila objetivo
      costo_camino += fila_objetivo - x_actual;
      x_actual = fila_objetivo;
    }
    // Tratamos de cubrir la siguiente fila
    fila_objetivo = x_actual + 1;
    --y_actual;

    if (fila_objetivo >= N && y_actual > 1) {
      // No lo puede alcanzar el peon blanco
      return -1;
    }
  }

  if (fila_objetivo > N) {
    // Fuera del tablero
    return -1;
  }
  int peon_actual = buscar_peon(1);
  if (fila_objetivo < peon_actual) {
    // Ponemos al alcance del peón blanco el peón negro de a lado
    costo_camino += peon_actual - fila_objetivo + 1;
  }
  return costo_camino;
}

int main() {
  // Leemos las dimensiones de la matriz
  std::cin >> N >> M;
  // Leemos la matriz
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      std::cin >> mapa[i][j];
    }
  }
  // Leemos la posicion de salida
  std::cin >> x_salida >> y_salida;

  if (y_salida == 1) {
    std::cout << misma_columna() << "\n";
  } else {
    std::cout << ir_al_destino() << "\n";
  }
}
