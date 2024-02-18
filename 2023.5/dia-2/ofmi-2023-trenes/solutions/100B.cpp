#include <iostream>

const int MAXN = 200002;

int n, k;
int t[MAXN];

int acumulado[MAXN];

int tipoB(int e, char lado, int d) {
  // Queremos sumar el tiempo de e -> e+1 -> e+2 -> ... -> n y de regreso
  int s = (acumulado[n] - acumulado[e - 1] + k) % k;
  // De regreso es el mismo
  s = (s * 2) % k;

  int t;
  if (lado == 'N') {
    // Estoy en el lado norte y el tren que esta en el sur pasará en d minutos
    // Entonces ese tren pasó por aquí hace d - s mod k minutos
    t = (d - s + k) % k;
  } else {
    // Estoy en el lado sur y el tren que esta en el norte pasará en d minutos
    // Entonces ese tren pasará por aquí en d + s mod k minutos
    t = (d + s) % k;
  }

  // Ahora, t es el tiempo que falta para que el primer tren pase por aquí
  // Hay que asegurar que nos quedamos al menos d minutos (sino entonces cómo
  // vimos al tren del otro lado?)
  if (t < d) {
    t += k;
  }

  return t;
}

int tipoA(int e, char lado, int d) { return k - d; }

int main() {
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    std::cin >> t[i];
    acumulado[i] = (t[i] + acumulado[i - 1]) % k;
  }
  int q;
  for (std::cin >> q; q > 0; --q) {
    char tipo, lado;
    int e, d;
    std::cin >> tipo >> e >> lado >> d;
    if (tipo == 'a') {
      std::cout << tipoA(e, lado, d) << std::endl;
    } else {
      std::cout << tipoB(e, lado, d) << std::endl;
    }
  }
  return 0;
}
