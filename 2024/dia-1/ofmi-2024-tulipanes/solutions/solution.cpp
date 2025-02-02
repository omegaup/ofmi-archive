#include <iostream>

// Hay a lo mas un millon de colores para los tulipanes.
constexpr int kColoresDiferentes = 1000000;

// Cubeta para contar cuantos tulipanes hay de cada color.
int conteo_tulipanes[kColoresDiferentes];

// Con estas cubetas, vamos a guardar cual es el tulipan que esta mas abajo,
// arriba, a la derecha y a la izquierda en el campo.
int tulipan_abajo[kColoresDiferentes];
int tulipan_arriba[kColoresDiferentes];
int tulipan_derecha[kColoresDiferentes];
int tulipan_izquierda[kColoresDiferentes];

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < kColoresDiferentes; ++i) {
    // Usamos valores bandera para indicar que aun no encontramos un tulipan,
    // para los mas abajo y a la izquierda vamos a usar los limites del campo,
    // ya que cualquier tulipan se encontrara antes que estas posiciones.
    tulipan_abajo[i] = n;
    tulipan_izquierda[i] = m;

    // Para los mas arriba y a la derecha usamos 0, ya que cualquier
    // tulipan se encontrara despues de estas posiciones.
    tulipan_arriba[i] = 0;
    tulipan_derecha[i] = 0;
  }

  int mas_abundantes = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int color;
      std::cin >> color;

      // Indexamos el color desde 0.
      --color;

      // Incrementamos el conteo de tulipanes de este color; si notamos que el
      // conteo de tulipanes es mayor a mas_abundante, hay que actualizarlo.
      ++conteo_tulipanes[color];
      if (conteo_tulipanes[color] > mas_abundantes)
        mas_abundantes = conteo_tulipanes[color];

      // Actualizamos la posicion de los tulipanes mas abajo, arriba, a la
      // derecha y a la izquierda, comparando con la i y j que representan
      // la fila y columna del tulipan actual respectivamente.
      if (i < tulipan_abajo[color]) tulipan_abajo[color] = i;
      if (i > tulipan_arriba[color]) tulipan_arriba[color] = i;
      if (j > tulipan_derecha[color]) tulipan_derecha[color] = j;
      if (j < tulipan_izquierda[color]) tulipan_izquierda[color] = j;
    }
  }

  int menor_desperdicio = n * m;
  for (int i = 0; i < kColoresDiferentes; ++i) {
    if (conteo_tulipanes[i] == mas_abundantes) {
      // Si el conteo de tulipanes de este color es igual al mas abundante,
      // calculamos el area delimitada por los tulipanes en los extremos y con
      // ellos sacar la area minima para contener a todos los de este color.
      int area = (tulipan_arriba[i] - tulipan_abajo[i] + 1) *
                 (tulipan_derecha[i] - tulipan_izquierda[i] + 1);

      // Actualizamos la respuesta si el area que contiene a todos los
      // tulipanes de este color desperdicia menos tulipanes.
      if (area - conteo_tulipanes[i] < menor_desperdicio)
        menor_desperdicio = area - conteo_tulipanes[i];
    }
  }
  std::cout << menor_desperdicio << '\n';
  return 0;
}
