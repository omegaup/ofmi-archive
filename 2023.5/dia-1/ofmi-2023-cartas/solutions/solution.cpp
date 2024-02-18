#include <iostream>

typedef long long int lld;

const int MAXN = 300002;

int n;
int A[MAXN];
int T[MAXN];

lld ans[MAXN];  // Respuesta después de cada clavado

// padre[i] = -1 si la persona i sigue bajo el agua
// Sino es el padre en la componente conexa
int padre[MAXN];
lld sum[MAXN];  // Suma de las personas de la componente

// Componente a la que pertenece la persona
int raiz(int node) {
  if (padre[node] == node) {
    return node;
  }
  return padre[node] = raiz(padre[node]);
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

  // Leemos la entrada
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> T[i];
  }
  // Vamos a procesar los clavados al revés
  // Inicialmente entonces todas las personas están en el agua
  std::fill(padre, padre + n, -1);
  lld currAns = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = currAns;

    int node = T[i];
    // Creamos el componente
    padre[node] = node;
    sum[node] = A[node];
    // Checamos si tenemos que unir con izquierda
    if (node > 0 && padre[node - 1] != -1) {
      int raizIzq = raiz(node - 1);
      padre[raizIzq] = node;
      sum[node] += sum[raizIzq];
      sum[raizIzq] = 0;
    }
    // Checamos si tenemos que unir con derecha
    if (node < n - 1 && padre[node + 1] != -1) {
      int raizDer = raiz(node + 1);
      padre[raizDer] = node;
      sum[node] += sum[raizDer];
      sum[raizDer] = 0;
    }
    // Actualizamos la respuesta
    if (sum[node] > currAns) {
      currAns = sum[node];
    }
  }

  // Imprimimos la respuesta en el orden correcto
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << "\n";
  }
  return 0;
}
