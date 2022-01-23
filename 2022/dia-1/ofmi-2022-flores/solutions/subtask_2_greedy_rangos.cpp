#include <algorithm>
#include <iostream>
#include <vector>

/*
    N - Cantidad de flores
    M - Constante de crecimiento de las flores
    x_entrada, y_entrada - Inicio en (x_entrada, y_entrada)
    x_salida, y_salida   - Fin en (x_salida, y_salida)
    tallo       - Coordenadas de los tallos
    crecimiento - Longitud maxima de cada planta
*/

int N, M;
int x_entrada, y_entrada;
int x_salida, y_salida;
std::vector<int> tallo;  // Guardamos solo el eje x
std::vector<int> crecimiento;

struct Flor {
  int inicio, fin;
};
bool cmp_flor(const Flor& A, const Flor& B) {
  return A.inicio < B.inicio || (A.inicio == B.inicio && A.fin < B.fin);
}

Flor calcular_flor(int indice, int tiempo) {
  // Calculamos el crecimiento de la flor en
  // la posicion 'indice' en el minuto 'tiempo'
  int longitud = std::min(crecimiento[indice], M * tiempo);
  if (longitud == -1) {
    longitud = M * tiempo;
  }
  Flor A;
  A.inicio = tallo[indice] - longitud;
  A.fin = tallo[indice] + longitud;
  return A;
}

bool greedy(std::vector<Flor> flores) {
  std::sort(flores.begin(), flores.end(), cmp_flor);

  int flor_actual = -1;
  int flor_siguiente = 0;
  // Buscamos la primer flor que cubre a la entrada
  while (flor_siguiente < N) {
    if (!(flores[flor_siguiente].inicio <= x_entrada &&
          x_entrada <= flores[flor_siguiente].fin)) {
      ++flor_siguiente;
    } else {
      flor_actual = flor_siguiente;
      break;
    }
  }
  if (flor_actual == -1) {
    // No se cubre el inicio
    return false;
  }
  if (x_salida <= flores[flor_actual].fin) {
    // Se alcanzo el final
    return true;
  }

  while (flor_siguiente < N) {
    // Nos movemos a la derecha siempre que podamos
    if (flores[flor_siguiente].inicio - 1 <= flores[flor_actual].fin &&
        flores[flor_actual].fin < flores[flor_siguiente].fin) {
      flor_actual = flor_siguiente;
    }
    ++flor_siguiente;
  }

  // Checamos si se cubrimos la salida
  return x_salida <= flores[flor_actual].fin;
}

bool prueba(int tiempo) {
  std::vector<Flor> flores;
  for (int i = 0; i < N; ++i) {
    Flor actual = calcular_flor(i, tiempo);
    flores.push_back(actual);
  }
  return greedy(flores);
}

int busquedaBinaria() {
  // Binaria sobre el tiempo
  int inicio = 0, final = 2e5 + 10, mitad;

  if (!prueba(final)) {
    // No se puede llegar a la salida
    return -1;
  }

  while (inicio < final) {
    mitad = (inicio + final) / 2;

    // Vemos si podemos llegar al final si tenemos el tiempo "mitad"
    if (prueba(mitad)) {
      // Si se puede, probaremos con un tiempo menor
      final = mitad;
    } else {
      // No se puede, probamos con un tiempo mayor
      inicio = mitad + 1;
    }
  }
  return inicio;
}

int main() {
  // Lectura de datos
  std::cin >> N >> M;
  std::cin >> x_entrada >> y_entrada;
  std::cin >> x_salida >> y_salida;

  if (x_entrada > x_salida) {
    std::swap(x_entrada, x_salida);
  }

  // Tallos
  for (int i = 0; i < N; ++i) {
    int x, y;
    std::cin >> x >> y;
    // y == 0
    tallo.push_back(x);
  }

  // Limite de crecimiento
  for (int i = 0; i < N; ++i) {
    int limite;
    std::cin >> limite;
    crecimiento.push_back(limite);
  }

  // Respuesta al problema
  std::cout << busquedaBinaria() << "\n";
}
