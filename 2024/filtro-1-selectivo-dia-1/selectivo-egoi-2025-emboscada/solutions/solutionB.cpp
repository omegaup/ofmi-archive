#include <iostream>

int main() {
  int n, k;
  int t[100005];

  std::cin >> n >> k;

  for (int i = 0; i < n; i++) {
    std::cin >> t[i];
  }

  // Busqueda binaria sobre el momento de inspeccion

  long long ini = 0, fin = 1e18, mid;
  long long atendidas = 0;

  while (ini != fin) {
    mid = (ini + fin) / 2;

    // Contamos las naves inspeccionadas por el hangar 'i'
    atendidas = 0;
    for (int i = 0; i < n; i++) {
      atendidas += 1 + mid / t[i];

      // El conteo de atendidas podria desbordarse
      if (atendidas > k) break;
    }

    // Si inspeccionamos mas de k -> podemos intentar con menos minutos.
    // Si no -> necesitamos esperar mas tiempo para que lleguemos a la k deseada
    if (atendidas > k)
      fin = mid;
    else
      ini = mid + 1;
  }

  // Para el tiempo en que llega la nave, hacemos recuento de cuantos se
  // atendieron
  atendidas = 0;
  for (int i = 0; i < n; i++) {
    atendidas += 1 + fin / t[i];
  }

  // Ya tenemos cuando paso la nave, y cuantas pasaron para ese momento
  // Falta ubicar exactamente en que hangar entro nuestra nave especifica

  for (int i = n - 1; i >= 0; i--) {
    // Si este hangar atendio nave en este tiempo
    if (fin % t[i] == 0) {
      // Checamos si es nuestra nave
      if (atendidas == k + 1) {
        // Si es, pues aqui entro y ya quedo
        std::cout << fin << " " << i + 1;
        return 0;
      } else {
        // Si no, pues ya pasamos una nave mas y seguimos
        atendidas--;
      }
    }
  }
}
