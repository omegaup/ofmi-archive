// Subtarea 2: El tulipan mas abundante es el 1.
//
// Al ya saber cual es el tulipan mas abundante, nos enfocamos en buscar
// el menor rectangulo que engloba todas las posiciones con este color.
// Observamos que solo nos importa la posicion mas a la izquierda, mas a
// la derecha, mas arriba, y mas abajo donde encontremos el tulipan [1].
//
// El rectangulo que vayamos a cultivar, tiene que cubrir estas posiciones,
// observamos que no es necesario hacer el rectangulo mas grande que esto,
// por lo que solo necesitamos saber cuantos [1] hay en el rectangulo.
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int conteo = 0;
  int izquierda = n;
  int derecha = 0;
  int arriba = 0;
  int abajo = m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int tulipan;
      std::cin >> tulipan;

      if (tulipan == 1) {
        // Actualizamos que tanto se expande el tulipan [1]
        ++conteo;
        izquierda = std::min(izquierda, i);
        derecha = std::max(derecha, i);
        abajo = std::min(abajo, j);
        arriba = std::max(arriba, j);
      }
    }
  }

  int ancho = derecha - izquierda + 1;
  int altura = arriba - abajo + 1;
  int area = ancho * altura;
  // Los demas tulipanes van a ser desperdiciados
  int desperdicio = area - conteo;

  // La respuesta es [desperdicio] porque [1] es el mas abundante
  std::cout << desperdicio << "\n";
  return 0;
}
