#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "energia.h"

typedef long long int lld;

const int NUM_SUB = 3;
int getSubtask(const std::string& caseName) {
  for (int sub = 1; sub <= NUM_SUB; ++sub) {
    if (caseName.find("sub" + std::to_string(sub)) != std::string::npos) {
      return sub;
    }
  }
  return -1;
}

const int MAXN = 302;

int n, L;
lld pos[MAXN];      // En qué posición está el corredor i
int energia[MAXN];  // Cuánta energía tiene el corredor i
lld maxPos;         // La maxima posicion alcanzada
bool invalidOp;     // Si en algún momento se hace una operación inválida

int pasaEnergia(int i, int j, int l) {
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
  return energia[j];
}

lld mueve(int i, int k) {
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
  return pos[i];
}

lld optimalSolution(int n, int L) {
  lld km = 0;
  lld nn = n - 1;
  lld l = L;
  while (nn > 0) {
    // nn tienen L energía
    // l tiene l energía > 0
    // tengo nn + 1 corredorcitos
    lld totalEnergy = nn * L + l;
    lld avanzo;
    if (nn >= L) {
      // Avanzo un km
      avanzo = 1;
    } else {
      // Cada km gasto nn + 1 litros
      // Quiero gastar l
      avanzo = std::max(1, (int)(l / (nn + 1)));
    }
    km += avanzo;
    totalEnergy -= (nn + 1) * avanzo;
    nn = totalEnergy / L;
    l = totalEnergy % L;
    if (l == 0) {
      nn--;
      l = L;
    }
  }
  // Avanzo los l km que me quedan
  return km + l;
}

float score(int subtask, lld maxPos) {
  // Checar la maxima posicion que se puede alcanzar
  lld optimal = optimalSolution(n, L);
  if (subtask < 3 && maxPos < optimal) {
    std::cerr << "No alcanzaste la maxima posicion que se puede alcanzar"
              << std::endl;
    return 0;
  }
  return std::min(1.0, sqrt((1.0 * maxPos) / (1.0 * optimal)));
}

int main(int argc, char* argv[]) {
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  int subtask = getSubtask(caseName);

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

  std::cout << std::setprecision(2);
  std::cout << score(subtask, maxPos) << std::endl;
  return 0;
}
