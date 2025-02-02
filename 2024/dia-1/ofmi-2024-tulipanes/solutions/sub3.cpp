// Subtarea 3: Solo tenemos una columna de tulipanes.
//
// Para cubrir todas las apariciones de un [tulipan], debemos de saber
// cual es la posicion mas arriba y mas abajo que pueda aparecer. Si
// vamos a hacer un iterador/bucle/ciclo sobre los tulipanes, podemos
// guardar en una variable por cada [tulipan] cual fue la posicion mas
// arriba y mas abajo. Esto lo podemos hacer con un arreglo de numeros
// para las posiciones de mas arriba y con otro arreglo para las posiciones
// de mas abajo.
//
// Para saber cuales son los mas abundantes, podemos ir contando las
// apariciones con una variable por [tulipan] (el arreglo conteo[]),
// checar cuanto es lo que se repite, y despues ver cual es el menor
// desperdicio que se haria para los tulipanes con esa cantidad de
// posiciones.
#include <iostream>

const int MaxN = 1010;
const int MaxColores = MaxN * MaxN;
int conteo[MaxColores];
int primera_aparicion[MaxColores];
int ultima_aparicion[MaxColores];

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int j = 0; j < m; ++j) {
    int tulipan;
    std::cin >> tulipan;
    if (conteo[tulipan] == 0) {
      primera_aparicion[tulipan] = j;
    }
    ultima_aparicion[tulipan] = j;
    ++conteo[tulipan];
  }

  int max_repeticiones = 0;
  int respuesta = 0;
  for (int tulipan = 0; tulipan < MaxColores; ++tulipan) {
    if (max_repeticiones <= conteo[tulipan]) {
      int flores = ultima_aparicion[tulipan] - primera_aparicion[tulipan] + 1;
      int desperdicio = flores - conteo[tulipan];
      if (max_repeticiones < conteo[tulipan] || desperdicio < respuesta) {
        max_repeticiones = conteo[tulipan];
        respuesta = desperdicio;
      }
    }
  }
  std::cout << respuesta << "\n";
  return 0;
}
