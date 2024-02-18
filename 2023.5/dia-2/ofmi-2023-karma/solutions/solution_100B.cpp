#include <algorithm>
#include <iostream>

/// La solucion es encontrar el k-esimo elemento maximo.

/// Encuentra la mediana de un arreglo de enteros en el subarreglo [l, r)
int median(int arr[], int l, int r) {
  std::sort(arr + l, arr + r);
  return arr[(l + r) / 2];
}

/// Hace la misma particion que en quicksort sobre arreglo 'nums'
/// en el subarreglo [l, r), con la diferencia que particiona en
/// < | = | > en vez de < | >, debido a que se pueden repetir elementos
void partition(int nums[], int l, int r, int pivot, int &first_idx,
               int &last_idx) {
  /**
    Primero particionamos el arreglo en la forma [0, a) U [a, c] U [b, d] U (d,
    n), donde
    - [l, a) son iguales a 'pivot'
    - [a, c] son menores a 'pivot'
    - [b, d] son mayores a 'pivot'
    - (d, r) son iguales a 'pivot'

    Despues, pasamos todos los elementos iguales a pivot a la mitad del arreglo
    quedando una particion de la forma < | = | > y guardamos el inicio y final
    del subarreglo = en 'first_idx' y 'last_idx'.
  */
  int a, b, c, d;
  a = b = l;
  c = d = r - 1;
  while (true) {
    /// Pasamos todos los iguales al subarreglo [l, a) y omitimos
    /// los menores hasta encontrar uno mayor o pasarnos del indice 'c'.
    while (b <= c && nums[b] <= pivot) {
      if (nums[b] == pivot) std::swap(nums[a++], nums[b]);
      b++;
    }

    /// Pasamos todos los iguales al subarreglo (d, r) y omitimos
    /// los mayores hasta encontrar uno menor o pasarnos del indice 'b'.
    while (c >= b && nums[c] >= pivot) {
      if (nums[c] == pivot) std::swap(nums[d--], nums[c]);
      c--;
    }

    if (b > c) break;
    std::swap(nums[b++], nums[c--]);
  }

  /// Pasamos todos los iguales a 'pivot' a la mitad del arreglo y actualizamos
  /// los indices de la primera y ultima aparicion del pivote
  first_idx = l + b - a;
  last_idx = r - (d - c) - 1;

  /// pasa los iguales a 'pivot' del principio al medio del arreglo
  for (int i = a - 1; l <= i; --i) std::swap(nums[i], nums[c--]);

  /// pasa los iguales a 'pivot' del final al medio del arreglo
  for (int i = d + 1; i < r; ++i) std::swap(nums[i], nums[b++]);
}

/**
    Busca el k-esimo elemento maximo en el subarreglo [l, r)
    del arreglo 'nums'. El algoritmo es similar al quicksort.

    Idea:
     - Se particiona el arreglo respecto a un pivote (como en quicksort)
       de manera que primero queden todos los menores, luego todos los iguales
       y al final todos los mayores.
    - La posicion inicial y final del pivote corresponden al subarreglo en donde
       todos los elementos son iguales al pivote.
     - Si n - k esta entre la posicion inicial y final del pivote, entonces
       la respuesta es el pivote.
     - Si n - k es mayor a la posicion final del pivote, entonces la respuesta
       esta en el lado derecho de la particion.
     - Si n - k es menor a la posicion inicial del pivote, entonces la respuesta
       esta en el lado izquierdo de la particion.

    El quicksort es O(n^2) en el peor caso, asi que para solucionar eso podemos
    tomar como pivote un elemento aleatorio (y tener fe de que pase en tiempo) o
    dividir el arreglo en subarreglos mas pequenios y obtener la mediana de cada
    subarreglo. Luego, la mediana de las medianas sera el pivote que minimice
    la cantidad de llamadas recursivas hasta tener un peor caso de O(n).

    En este caso elegimos un tamanio de 5 para los subarreglos
*/

const int BLOCK_SIZE = 5;
int quick_select(int nums[], int l, int r, const int k) {
  int n = r - l;  /// tamanio del subarreglo

  /// (n + BLOCK_SIZE - 1) / BLOCK_SIZE es el entero
  /// mas pequenio que es >= a (n + 1) / BLOCK_SIZE
  int n_medians = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
  int medians[n_medians];
  /// Obtenemos la mediana de cada bloque
  for (int i = 0; BLOCK_SIZE * i < n; ++i)
    medians[i] =
        median(nums, i * BLOCK_SIZE + l, std::min((i + 1) * BLOCK_SIZE + l, r));

  /// Llamamos recursivamente a quick_select para
  /// obtener rapido la mediana de las medianas
  int median_of_mendians =
      n_medians == 1 ? medians[0]
                     : quick_select(medians, 0, n_medians, n_medians / 2);

  /// Para tratar con numeros repetidos, particionamos el
  /// arreglo de la forma < | = | >, respecto al pivote 'median_of_medians'
  int first_pivot_index, last_pivot_index;
  partition(nums, l, r, median_of_mendians, first_pivot_index,
            last_pivot_index);
  int first_pivot_pos = first_pivot_index - l,
      last_pivot_pos = last_pivot_index - l;

  if (first_pivot_pos <= n - k && n - k <= last_pivot_pos)
    return nums[first_pivot_index];  /// el pivote es el k-esimo maximo
  else if (last_pivot_pos <
           n - k)  /// el k-esimo maximo esta en el lado derecho
    return quick_select(nums, last_pivot_index + 1, r, k);

  /// el k-esimo maximo esta en el lado izquierdo y a k le quitamos los
  /// 'n - first_pivot_pos' mayores de la derecha
  return quick_select(nums, l, first_pivot_index, k - n + first_pivot_pos);
}

int main() {
  /**
      Las siguientes tres lineas no son parte de la solucion,
      solo optimizan el tiempo que el programa tarda en las
      entradas y salidas (cin/cout).
  */
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  /// Empieza solucion:
  int n, m;
  std::cin >> n >> m;

  int nums[n];
  for (int i = 0; i < n; ++i) std::cin >> nums[i];

  /// Selecciona el m-esimo maximo o imprime sencillo si
  /// la dificultad es menor o igual a 0
  int dificultad = quick_select(nums, 0, n, m);
  if (dificultad <= 0)
    std::cout << "sencillo\n";
  else
    std::cout << dificultad << '\n';
}