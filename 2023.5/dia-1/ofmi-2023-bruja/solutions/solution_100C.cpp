#include <algorithm>
#include <iostream>

/**
  La idea de la solucion es contar la cantidad de elementos diferentes.

  Si ordenamos el arreglo de numeros, todos los numeros iguales quedaran
  juntos, por lo que la solucion es contar cuantas veces cambiamos de valor.
*/

int main() {
  /**
    Las siguientes tres lineas no son parte de la solucion,
    solo optimizan el tiempo que el programa tarda en las
    entradas y salidas (cin/cout).
  */
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  /// Aqui empieza la solucion.
  int n;
  std::cin >> n;  /// Lee la primera linea.
  int nums[n];
  for (int i = 0; i < n; ++i) {  /// Lee los n enteros de la segunda linea
    std::cin >> nums[i];
  }

  /// Ordenamos los numeros para tener todos los iguales
  /// consecutivos
  std::sort(nums, nums + n);

  /// La variable 'cnt' nos servira para contar los cambios de valor.
  /// Siempre hay al menos un valor (1 <= n <= 10^6).
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    /// Si el numero actual es diferente del anterior,
    /// entonces acabamos de cambiar de valor.
    if (nums[i] != nums[i - 1]) cnt++;
  }

  /// Al final solo imprimimos la respuesta.
  std::cout << cnt << '\n';
}
