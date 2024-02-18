/*Primero separando en positivos y negativos,
y luego hacemos un radix sort quitando los
repetidos mientras se esta iterando.
Al final contamos cuantos quedaron.
*/
#include <iostream>

// Valor maximo de N
const int MAXN = 2e5;
/*Arreglo para guardar los valores
flowerN -> para los negativos
flowerP -> para los positivos
*/
int flowerN[MAXN + 1], flowerP[MAXN + 1];

// Para ordenar y comparar por digitos
// Cubeta por cada digito
std::pair<int, int> digit[10][MAXN + 1];
// Areglo auxiliar
std::pair<int, int> aux[MAXN + 1];

/* Funcion que recive un arreglo y su tamanio
modifica el tamanio para que sea el total
de valores diferentes
A -> Arreglo con valores (es un apuntador,
pero funcionara igual que un arreglo)
n -> tamanio
*/
void solve(int *A, int &n) {
  /*cnt[i] -> contador de la cantidad de elementos
  insertados en digit[i] hasta el momento
  */
  int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  /*Pasa los elementos del arreglo original
  al arreglo auxiliar
  */
  for (int i = 0; i < n; i++) {
    aux[i] = {A[i], A[i]};
  }

  /*Va a hacer un total de 10 iteraciones
  una por cada digito (los numeros pueden
  tener hasta 10 digitos)
  */
  for (int it = 0; it < 10; it++) {
    /*Recorre el arreglo e inserta el elemento
    en la cubeta del digito que le corresponde
    */
    for (int i = 0, d; i < n; i++) {
      // d -> digito correspondiente
      d = aux[i].second % 10;
      /*Divide entre 10 para que en la siguiente
      iteracion pueda sacar el siguiente digito
      */
      aux[i].second /= 10;
      // Inserta el elemento en la cubeta
      digit[d][cnt[d]++] = aux[i];
    }
    // Inicializa el valor de n
    n = 0;
    /*Va a iterar por todas las cubetas,
    empezando por el 0 y terminado con el 9,
    en cada uno saca los elementos que se
    insertaron en esa cubeta y los regresa al
    arreglo auxiliar, excepto cuando un elemento
    anterior es igual al que intentas insertar,
    en ese caso simplemente lo ignoras.
    */
    for (int i = 0; i < 10; i++) {
      // Pasa por todos los elementos en la cubeta
      for (int j = 0; j < cnt[i]; j++) {
        /*Si es el primero que vas a meter o es
        diferente al anterior, insertalo en el
        arreglo auxiliar y aumenta el contador(n)
        */
        if (n == 0 || aux[n - 1].first != digit[i][j].first) {
          aux[n++] = digit[i][j];
        }
      }
      cnt[i] = 0;
    }
  }
  // Al final n = cantidad de elementos distintos
  /* Al ser pasados por referencia, al terminar
  la ejecucion de la funcion, nn y np respectivamente,
  habran cambiado su valor
  */
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  // Leemos N (cantidad de noches)
  int N;
  std::cin >> N;
  /*Declaramos algunas variables
  np -> contador de numeros positivos
  nn -> contador de numeros negativos
  zero -> si hay un cero en los numeros
  */
  int np = 0, nn = 0, zero = 0;
  // Iteramos por la cantidad de numeros (N)
  for (int i = 0, x; i < N; i++) {
    // Leemos el numero (tipo de flor)
    std::cin >> x;
    if (x < 0) {
      // Es un numero negativo
      // Agregar el valor al arreglo de negativos
      flowerN[nn++] = -x;
    } else if (x > 0) {
      // Es un numero positivo
      // Agregar el valor al arreglo de positivos
      flowerP[np++] = x;
    } else {
      // Es un cero
      zero = 1;
    }
  }
  solve(flowerN, nn);
  // Ahora nn tiene el total de numeros negativos distintos
  solve(flowerP, np);
  // Ahora np tiene el total de numeros positivos distintos

  /*Imprime:
      numeros negativos distintos +
      numeros positivos distintos +
      si habia un zero

      = total de numeros distintos
  */
  std::cout << np + nn + zero;
  return 0;
}