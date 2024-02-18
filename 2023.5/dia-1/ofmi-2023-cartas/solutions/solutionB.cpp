#include <iostream>

const int MAX_N = 300000;

int n;
int A[MAX_N];
int T[MAX_N];

long long res[MAX_N];  // respuesta para cada clavado

long long
    sumIni[MAX_N];  // sumIni[i] es la suma del rango contiguo que empieza en i
long long
    sumFin[MAX_N];  // sumFin[i] es la suma del rango contiguo que termina en i
int idxIni[MAX_N];  // idxIni[i] es el inicio del rango contiguo que contiene a
                    // i, o -1 si no hay rango.
int idxFin[MAX_N];  // idxFin[i] es el fin del rango contiguo que contiene a i,
                    // o -1 si no hay rango.

// La persona i se lanza al agua, actualiza los arreglos de sum e idx, y
// devuelve la suma del nuevo rango contiguo que se forma cuando i se echa un
// clavado.
long long clavado(int i) {
  int ini, fin;
  long long suma = (long long)A[i];
  ini = fin = i;

  if (i > 0 and idxIni[i - 1] != -1) {
    // Hay un rango contiguo a la izquierda de i que se unirá con el rango a la
    // derecha
    ini = idxIni[i - 1];
    suma += sumIni[ini];
  }

  if (i < n - 1 and idxFin[i + 1] != -1) {
    // Hay un rango contiguo a la derecha de i que se unirá con el rango a la
    // izquierda
    fin = idxFin[i + 1];
    suma += sumFin[fin];
  }

  // Actualizamos los arreglos
  idxFin[ini] = fin;
  idxIni[fin] = ini;
  sumIni[ini] = sumFin[fin] = suma;
  return suma;
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

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> T[i];
  }

  // Inicializamos los arreglos de sum e idx
  for (int i = 0; i < n; i++) {
    idxIni[i] = idxFin[i] = -1;
    sumIni[i] = sumFin[i] = 0;
  }

  // Respondemos las preguntas en orden inverso
  long long sumaMax = 0;
  for (int i = n - 1; i >= 0; i--) {
    res[i] = sumaMax;
    // La suma contigua máxima al lanzarse al agua la i-ésima persona es el
    // máximo entre la suma máxima al momento y la suma del rango contiguo
    // que se forma al echarse i su clavado.
    sumaMax = std::max(sumaMax, clavado(T[i]));
  }

  // Imprimimos las respuestas en el orden correcto
  for (int i = 0; i < n; ++i) {
    std::cout << res[i] << "\n";
  }
  return 0;
}
