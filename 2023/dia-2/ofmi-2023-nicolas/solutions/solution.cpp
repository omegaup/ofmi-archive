#include <utility>

#include "nicolas.h"
typedef std::pair<int, int> pii;

const int MAX = 1e3;

int tiempo = 0;

bool intenta(int X, int L) {
  tiempo++;
  return foto(X * tiempo + L - 1);
}

int guessL(int X, int minl, int maxl) {
  // Ahora intentamos adivinar la longitud con busqueda binaria
  // intentando darle a la cabeza
  int l = minl, r = maxl;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (intenta(X, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

int guessX(int minx, int maxx) {
  // Primero intentamos adivinar la velocidad intentando pegarle
  // a la cola.
  int X;
  for (X = minx; X < maxx; ++X) {
    // Si tuviera velocidad X, la cola estaría en la posición X*tiempo
    if (intenta(X, 1)) {
      // Si la foto dio positivo, entonces la cola está en la posición X
      break;
    }
  }
  return X;
}

pii nicolasImpl() {
  // Primero le tiramos a la casilla (MAX, 1) para borrar la mitad del espacio
  // de búsqueda
  if (!intenta(MAX, 1)) {
    // Si la foto dio negativo, entonces el espacio de búsqueda es el triángulo
    // superior izquierdo
    int X = guessX(1, MAX - 1);
    int L = guessL(X, 1, MAX - X);
    return {X, L};
  }

  // Nuestro espacio de búsqueda es ahora el triángulo inferior derecho,
  // volvemos a intentar (MAX, 1)
  if (intenta(MAX, 1)) {
    // Si la foto dio positivo, entonces el espacio de búsqueda es el
    // minitriángulo inferior derecho
    int X = guessX(MAX / 2 + 1, MAX);
    int L = guessL(X, 2 * (MAX - X) + 1, MAX);
    return {X, L};
  }

  // podemos comernos MAX / 3 de un jalón si preguntamos en (MAX / 3, 1)
  if (intenta(MAX / 3, 1)) {
    // Si la foto dio positivo, entonces el espacio de búsqueda
    // Son los primeros MAX / 3 renglones
    int X = guessX(1, MAX / 3);
    int L = guessL(X, MAX - X + 1, MAX);
    return {X, L};
  }

  // Si la foto dio negativo, entonces el espacio de búsqueda es la diagonal
  // rara a partir de MAX / 3
  int X = guessX(MAX / 3 + 1, MAX - 1);
  int L = guessL(X, MAX - X + 1, (X <= MAX / 2 ? MAX : 2 * (MAX - X)));
  return {X, L};
}

void nicolas() {
  pii ans = nicolasImpl();
  return reporta(ans.first, ans.second);
}
