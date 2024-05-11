#include "cubos.h"

/**
    En el caso 2D se puede resolver de manera equivalente
    al problema de poner N torres en un tablero de NxN sin
    que se ataquen entre si. La misma idea se puede extender al
    caso 3D poniendo N^2 torres sin que se ataquen, que atacan
    hacia arriba, abajo, izquierda, derecha, adelante y atras.

    Por lo tanto, la solucion se resume en poner N^2 puntos
    sin repetir nunca alguna fila, columna o profundidad.
*/

void cubo(int N) {
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      ponerBloque(x, y, (x + y) % N);
    }
  }
}
