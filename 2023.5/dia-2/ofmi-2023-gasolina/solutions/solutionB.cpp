#include <algorithm>

#include "energia.h"

const int MaxN = 1007;

int energia[MaxN];
int corredoresRestantes;
int pasos;
int kilometro;
int energiaPasada;
int ini, fin;

void avanzaMaximo(int n, int L) {
  // Inicializar la cantidad de energía
  for (int i = 0; i < n; i++) energia[i] = L;
  // Inicializar la cantidad de corredores "Activos"
  corredoresRestantes = n;

  // Mientras tenga corredores activos repito mi metodo
  while (corredoresRestantes > 0) {
    /* La cantidad de pasos minimos requeridos para descartar un corredor
     * sin desperdiciar energía es "energía de corredor a
     * descartar"/corredoresRestantes El corredor que intentemos descartar
     * siempre sera el que tenga menos energía mantendremos el corredor con
     * menos energía como el ultimo de corredoresRestantes
     */
    pasos = (energia[corredoresRestantes - 1] + corredoresRestantes - 1) /
            corredoresRestantes;  // Obtenemos el techo de asi
    kilometro += pasos;

    // Avanzar cada corredor "pasos" y reducir su energía
    for (int i = 0; i < corredoresRestantes; i++) {
      energia[i] -= pasos;
      mueve(i, pasos);
    }

    // Resurtir de energía, esto lo hacemos con dos punteros,
    // uno señalando a quien resurtimos, otro de donde extraemos
    ini = 0;
    fin = corredoresRestantes - 1;
    // Aseguramos que este es el ultimo con energía
    while (energia[fin] == 0 && fin >= 0) fin--;
    while (ini < fin) {
      energiaPasada = std::min(energia[fin], L - energia[ini]);
      if (energiaPasada > 0) {
        energia[fin] -= energiaPasada;
        energia[ini] += energiaPasada;
        pasaEnergia(fin, ini, energiaPasada);
      }

      if (energia[fin] == 0) fin--;
      if (energia[ini] == L) ini++;
    }
    corredoresRestantes = fin + 1;
  }
  return;
}
