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

Flor unificar(Flor A, Flor B) {
  // Juntamos los rangos de las flores A y B
  Flor C;
  C.inicio = std::min(A.inicio, B.inicio);
  C.fin = std::max(A.fin, B.fin);
  return C;
}

bool interseccion(Flor A, Flor B) {
  return (A.inicio <= B.inicio && B.inicio <= A.fin + 1) ||
         (B.inicio <= A.inicio && A.inicio <= B.fin + 1);
}

bool unir_rangos(std::vector<Flor> flores) {
  Flor actual;
  bool entrada_cubierta = false;

  // Buscaremos una flor en la cual ya estemos posicionados en la entrada
  for (int i = 0; i < N; i++) {
    if (flores[i].inicio <= x_entrada && x_entrada <= flores[i].fin) {
      actual = flores[i];
      entrada_cubierta = true;
      break;
    }
  }

  if (!entrada_cubierta) {
    // No se cubre la entrada
    return false;
  }

  // Nos expandimos desde esta flor hasta ya no poder mas
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (interseccion(actual, flores[j])) {
        actual = unificar(actual, flores[j]);
      }
    }
  }

  return actual.inicio <= x_entrada && x_salida <= actual.fin;
}

bool prueba(int tiempo) {
  std::vector<Flor> flores;
  for (int i = 0; i < N; ++i) {
    Flor actual = calcular_flor(i, tiempo);
    flores.push_back(actual);
  }
  return unir_rangos(flores);
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
