#include <iostream>

const int MAXN = 1e6;             // Cantidad maxima de elementos
long long T[MAXN + 2];            // Guardar la distancia entre estaciones
long long TimeToNorth[MAXN + 2];  // Guarda distancia a la estacion del norte

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;        // Cantidad de estaciones con dos lados
  long long K;  // Tiempo de espera entre cada tren
  // Leemos los enteros
  std::cin >> N >> K;

  // Leemos las distancias
  for (int i = 1; i <= N; i++) {
    std::cin >> T[i];
  }
  // Calculamos distancia a la estacion norte (suffix sum)
  for (int i = N; i > 0; i--) {
    TimeToNorth[i] = TimeToNorth[i + 1] + T[i];
  }

  int Q;  // Cantidad de preguntas
  // Leemos el entero
  std::cin >> Q;

  while (Q--) {             // Se repite Q veces
    char t, side_of_track;  // t = tipo de pregunta, side_of_track = lado en
                            // donde se encuentra
    int idx;                // Indice de la estacion
    long long d;            // Tiempo transcurrido/esperado
    // Leemos los datos
    std::cin >> t >> idx >> side_of_track >> d;

    if (t == 'a') {
      // Si es de tipo 'a'
      // Entonces solo tiene que esperar el proximo
      // Como van hacia la misma direcdion, el siguiente llegara en K - d
      // minutos
      std::cout << (K - d) % K;
    } else {
      // Si es de tipo 'b'

      // Calcula la distancia que tiene/tuvo que recorrer el tren
      long long dist = 2 * TimeToNorth[idx];
      // Al sacar modulo tenemos el tiempo que le sobra al tren para llegar
      long long nxt = dist % K;
      if (side_of_track == 'N') {
        // Si estas en el lado norte y lo viste pasar por el lado sur, entonces
        // necesitas esperar el tiempo que le falra recorrer para completar una
        // distancia multiplo de K
        std::cout << ((K - nxt) % K) + d;
      } else {
        // Si estas en el lado sur, el tren con tiempo sobrante viene hacia ti,
        // por lo que solo tienes que esperar a que se le acabe el tiempo de
        // sobra
        std::cout << nxt + d;
      }
      // En ambos casos le agregas el tiempo que esperaste para vel el tren
    }
    std::cout << '\n';
  }
  return 0;
}