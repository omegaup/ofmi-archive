#include <algorithm>
#include <iostream>

#include "energia.h"

typedef long long int lld;

const int MAXN = 302;

int n, L;
lld pos[MAXN];      // En qué posición está el corredor i
int energia[MAXN];  // Cuánta energía tiene el corredor i
lld maxPos;         // La maxima posicion alcanzada
bool invalidOp;     // Si en algún momento se hace una operación inválida

int pasaEnergia(int i, int j, int l) {
  std::cerr << "Llamaste a pasaEnergia(" << i << ", " << j << ", " << l << ")"
            << std::endl;
  // Pasa energía del corredor i al corredor j
  if (i < 0 || i >= n || j < 0 || j >= n || l < 0) {
    invalidOp = true;
    std::cerr << "Error: operación pasaEnergia inválida" << std::endl;
    return -1;
  }
  // Checar si están en la misma posición
  if (pos[i] != pos[j]) {
    invalidOp = true;
    std::cerr << "Error: los corredores " << i << " y " << j
              << " no están en la misma posición" << std::endl;
    return -1;
  }
  // Checar si el corredor i tiene suficiente energía
  if (energia[i] < l) {
    invalidOp = true;
    std::cerr << "Error: el corredor " << i << " no tiene suficiente energía"
              << std::endl;
    return -1;
  }
  energia[i] -= l;
  energia[j] += l;
  // Checar que el corredor j no se haya pasado de la energía máxima
  if (energia[j] > L) {
    invalidOp = true;
    std::cerr << "Error: el corredor " << j << " no puede aceptar los " << l
              << " litros" << std::endl;
    return -1;
  }
  std::cerr << "Ahora el corredor " << j << " tiene " << energia[j] << " litros"
            << std::endl;
  return energia[j];
}

lld mueve(int i, int k) {
  std::cerr << "Llamaste a mueve(" << i << ", " << k << ")" << std::endl;
  if (i < 0 || i >= n || k < 0) {
    invalidOp = true;
    std::cerr << "Error: operación mueve inválida" << std::endl;
    return -1;
  }
  // Checar si puedo mover el corredor k km
  if (energia[i] < k) {
    invalidOp = true;
    std::cerr << "Error: el corredor " << i
              << " no tiene suficiente energía para moverse " << k << " km"
              << std::endl;
    return -1;
  }
  pos[i] += k;
  energia[i] -= k;
  maxPos = std::max(maxPos, pos[i]);
  std::cerr << "Ahora el corredor " << i << " está en la posición " << pos[i]
            << " y tiene " << energia[i] << " litros" << std::endl;
  return pos[i];
}

int main() {
  // Leemos la entrada
  std::cin >> n >> L;
  // Llenamos las n botellas de energía
  std::fill(energia, energia + n, L);
  // Llamamos a la solución del concursante
  avanzaMaximo(n, L);

  if (invalidOp) {
    std::cerr << "Error: Se hizo una operación inválida" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }
  std::cerr << "Avanzaste " << maxPos << " km correctamente! :)" << std::endl;
  std::cout << 1 << std::endl;
  return 0;
}
