#include <iostream>
#include <queue>  //priority_queue

// Valor maximo de N
const int MAXN = 1e6;
// Arreglo para guardar los valores
int K[MAXN + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  // Leemos los valores de N(cantidad) y M(posicion)
  int N, M;
  std::cin >> N >> M;

  // Creamos una cola de prioridad
  std::priority_queue<int> pq;
  for (int i = 0; i < N; i++) {
    // Leemos el valor de la dificultad
    std::cin >> K[i];
    // Lo insertamos en la cola de prioridad
    pq.push(K[i]);
  }

  /*Hacemos pop M-1 veces, de esta manera se eliminara el valor
  maximo de la cola M-1 veces, en otras palabras, se eliminaran
  los primeros M-1 numeros mas grandes, dejando entonces en
  pq.top() el M-esimo numero mas grande
  */
  // Iteramos del 1 al M-1
  for (int i = 1; i < M; i++) {
    // Hacemos pop
    pq.pop();
  }
  // Asignamos a x el valor del M-esimo numero mas grande
  int x = pq.top();
  if (x <= 0) {
    // Si es menor o igual a 0
    // Imprime "sencillo"
    std::cout << "sencillo\n";
  } else {
    // Si es mayor a cero
    // Imprime el valor
    std::cout << x << '\n';
  }
  return 0;
}