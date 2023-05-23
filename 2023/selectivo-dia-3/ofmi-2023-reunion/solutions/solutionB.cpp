#include "reunion.h"

double reunion(int n, int X[], int V[]) {
  double maxi = 1e9;
  double ini = 0;
  double fin = maxi;
  double med, lmax, hmin, pin, pfin;
  while (ini < fin && fin - ini >= 0.000000001 && ((ini + fin) / 2) != med) {
    med = (ini + fin) / 2;
    lmax = 0.0;
    hmin = maxi + 1;

    // CÁLCULO DE RANGOS
    for (int i = 0; i < n; i++) {
      if (X[i] - V[i] * med > 0)
        pin = X[i] - (V[i] * med);
      else
        pin = 0;

      if (pin > lmax) lmax = pin;

      if (X[i] + (V[i] * med) < maxi)
        pfin = X[i] + (V[i] * med);
      else
        pfin = maxi;

      if (pfin < hmin) hmin = pfin;
    }
    if (lmax < hmin)
      fin = med;
    else
      ini = med;
  }
  return med;
}
