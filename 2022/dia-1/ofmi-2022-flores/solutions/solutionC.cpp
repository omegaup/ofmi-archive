#include <iostream>
#include <vector>

int n, m;

struct Flor {
  int x, y, limite;
};

std::vector<Flor> flores;
std::vector<bool> visitado;

typedef long long ll;
const int oo = 3e5;

bool conectan(ll l1, ll r1, ll l2, ll r2) {
  return std::max(l1, l2) <= std::min(r1, r2);
}

bool conectan(Flor a, Flor b, ll tiempo) {
  // Preparar líneas de flor a
  ll limite = a.limite == -1 ? oo : a.limite;
  ll x1_a = a.x - std::min(m * tiempo, limite);
  ll x2_a = a.x + std::min(m * tiempo, limite);
  ll y1_a = a.y + std::min(m * tiempo, limite);
  ll y2_a = a.y - std::min(m * tiempo, limite);
  // Preparar líneas de flor b
  limite = b.limite == -1 ? oo : b.limite;
  ll x1_b = b.x - std::min(m * tiempo, limite);
  ll x2_b = b.x + std::min(m * tiempo, limite);
  ll y1_b = b.y + std::min(m * tiempo, limite);
  ll y2_b = b.y - std::min(m * tiempo, limite);

  // Evaluar el eje horizontal y vertical
  return conectan(x1_a, x2_a, x1_b, x2_b) && conectan(y2_a, y1_a, y2_b, y1_b);
}

bool dfs(int tiempo, int actual, int salida) {
  // Verificamos si llegamos a la salida
  bool encontrado = actual == salida;
  // Marcar nodo actual como visitado
  visitado[actual] = true;

  for (int nodo = 0; nodo < n; nodo++) {
    // Exploramos vecinos no visitados
    if (!visitado[nodo]) {
      Flor a = flores[actual];
      Flor b = flores[nodo];
      if (conectan(a, b, tiempo)) {
        // Buscamos un camino por este nodo
        encontrado |= dfs(tiempo, nodo, salida);
      }
    }
  }
  return encontrado;
}

int main() {
  std::cin >> n >> m;
  n += 2;
  // Creamos un arreglo de n + 2 flores
  flores = std::vector<Flor>(n);
  const int ENTRADA = 0;
  const int SALIDA = 1;

  /* A continuación leemos la ubicación de
   * la entrada, la salida y de las flores */
  for (auto &[x, y, _] : flores) std::cin >> x >> y;
  // Leemos el límite de crecimiento de cada flor
  for (int i = 2; i < n; i++) std::cin >> flores[i].limite;

  /** Solución parcial
  const int MAX_T = 100;
  int t;
  for (t = 0; t <= MAX_T; t ++) {
    // Inicializar arreglo de nodos visitados
    visitado.resize(n);
    std::fill(visitado.begin(), visitado.end(), 0);

    if(dfs(t, ENTRADA, SALIDA))
      // Respuesta encontrada
      break;
  }

  if (t <= MAX_T)
    std::cout << "-1\n"; // Imposible llegar
  else
    std::cout << t << "\n";
  */

  // Búsqueda binaria
  int limite_inferior = 0, limite_superior = 2e5 + 10;
  while (limite_inferior < limite_superior) {
    int mitad = (limite_inferior + limite_superior) / 2;
    // Inicializar arreglo de nodos visitados
    visitado.resize(n);
    std::fill(visitado.begin(), visitado.end(), 0);
    if (dfs(mitad, ENTRADA, SALIDA))
      limite_superior = mitad;
    else
      limite_inferior = mitad + 1;
  }

  if (limite_inferior == 2e5 + 10) {
    std::cout << "-1\n";
  } else {
    std::cout << limite_inferior << "\n";
  }
  return 0;
}
