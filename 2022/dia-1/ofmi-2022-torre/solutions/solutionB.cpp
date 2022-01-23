#include <iostream>

#include "torre.h"

int val;
bool salir;

void assert_salida_y_mueve_a_tapia(int *x_t, int *y_t) {
  // Manejamos lo que regresa el interactive.
  if (val <= 0) {
    salir = true;
    return;
  }
  if (*x_t == 0 && *y_t == 0) {
    *x_t = 1;
    *y_t = val;
    return;
  }
  if (val == 1) *x_t = *x_t - 1;
  if (val == 2) *x_t = *x_t + 1;
  if (val == 3) *y_t = *y_t + 1;
  if (val == 4) *y_t = *y_t - 1;
  if (*x_t == 0) *y_t = 0;
}

void sube_a_juan(int *x_j, int *y_j, int *x_t, int *y_t) {
  if (salir) return;
  *x_j = *x_j - 1;
  if (*x_j == 0) *y_j = 0;
  val = mueve(*x_j, *y_j);
  assert_salida_y_mueve_a_tapia(x_t, y_t);
}

void baja_a_juan(int *x_j, int *y_j, int *x_t, int *y_t) {
  if (salir) return;
  *x_j = *x_j + 1;
  val = mueve(*x_j, *y_j);
  assert_salida_y_mueve_a_tapia(x_t, y_t);
}

void juan_a_la_izquierda(int *x_j, int *y_j, int *x_t, int *y_t) {
  if (salir) return;
  *y_j = *y_j - 1;
  val = mueve(*x_j, *y_j);
  assert_salida_y_mueve_a_tapia(x_t, y_t);
}

void juan_a_la_derecha(int *x_j, int *y_j, int *x_t, int *y_t) {
  if (salir) return;
  *y_j = *y_j + 1;
  val = mueve(*x_j, *y_j);
  assert_salida_y_mueve_a_tapia(x_t, y_t);
}

bool paridad_distinta(int x_j, int y_j, int x_t, int y_t) {
  // Juan puede atrapar a tapia?
  return ((x_j + y_j) % 2) != ((x_t + y_t) % 2);
}

void ve_si_tapia_es_atrapable(int *x_j, int *y_j, int *x_t, int *y_t) {
  if (salir) return;
  if (*x_j == 0 && *y_j == 0) {
    if (*x_t == 1) {
      *x_j = 1;
      *y_j = *y_t;
      if (salir) return;
      val = mueve(*x_j, *y_j);
      assert_salida_y_mueve_a_tapia(x_t, y_t);
    }
  }
  if (*x_t == 0 && *y_t == 0) {
    if (*x_j == 1) {
      *x_j = 0;
      *y_j = 0;
      if (salir) return;
      val = mueve(*x_j, *y_j);
      assert_salida_y_mueve_a_tapia(x_t, y_t);
    }
    return;
  }
  if (*x_j - 1 == *x_t && *y_j == *y_t) sube_a_juan(x_j, y_j, x_t, y_t);
  if (*x_j + 1 == *x_t && *y_j == *y_t) baja_a_juan(x_j, y_j, x_t, y_t);
  if (*x_j == *x_t && *y_j - 1 == *y_t) juan_a_la_izquierda(x_j, y_j, x_t, y_t);
  if (*x_j == *x_t && *y_j + 1 == *y_t) juan_a_la_derecha(x_j, y_j, x_t, y_t);
}

bool persiguiendo_a_tapia = false;

void cambia_paridad(int *nn, int *mm, int *x_j, int *y_j, int *x_t, int *y_t) {
  if (salir) return;
  while (*x_j > 0) {
    if (salir) return;
    ve_si_tapia_es_atrapable(x_j, y_j, x_t, y_t);
    sube_a_juan(x_j, y_j, x_t, y_t);
    ve_si_tapia_es_atrapable(x_j, y_j, x_t, y_t);
  }
  // Bajamos a una columna que cambia la paridad, y ademas es optima para
  // atrapar a Tapia.
  int col = -1, costo = *mm;
  for (int i = 1; i <= *mm; i++) {
    if (!paridad_distinta(1, i, *x_t, *y_t)) {
      if (abs(i - *y_t) == *x_t - 1) {
        if (i < *y_t) {
          if (costo > *mm - i) {
            col = i;
            costo = *mm - i;
          }
        } else {
          if (costo > i - 1) {
            col = i;
            costo = i - 1;
          }
        }
      }
    }
  }
  if (col == -1 || costo > (*mm / 2)) {
    for (int i = (*mm + 1) / 2 - 1; i <= (*mm + 1) / 2 + 1; i++) {
      if (i >= 1 && i <= *mm && !paridad_distinta(1, i, *x_t, *y_t)) {
        col = i;
        break;
      }
    }
  }
  *x_j = 1;
  *y_j = col;
  if (salir) return;
  val = mueve(*x_j, *y_j);
  assert_salida_y_mueve_a_tapia(x_t, y_t);
  ve_si_tapia_es_atrapable(x_j, y_j, x_t, y_t);
  persiguiendo_a_tapia = true;
}

void juega(int n, int m, int x_j, int y_j, int x_t, int y_t) {
  if (salir) return;
  ve_si_tapia_es_atrapable(&x_j, &y_j, &x_t, &y_t);
  if (x_j == 0 && y_j == 0) {
    cambia_paridad(&n, &m, &x_j, &y_j, &x_t, &y_t);
    juega(n, m, x_j, y_j, x_t, y_t);
    return;
  }
  if (!paridad_distinta(x_j, y_j, x_t, y_t)) {
    cambia_paridad(&n, &m, &x_j, &y_j, &x_t, &y_t);
    juega(n, m, x_j, y_j, x_t, y_t);
    return;
  }
  if (x_j > 0 && (x_j > x_t || std::abs(y_j - y_t) > std::abs(x_j - x_t) + 1)) {
    // Juan sube mientras no pueda atrapar a Tapia
    sube_a_juan(&x_j, &y_j, &x_t, &y_t);
    juega(n, m, x_j, y_j, x_t, y_t);
    return;
  }
  if (2 * x_j <= std::abs(y_t - y_j) + 1 && !persiguiendo_a_tapia) {
    // Juan sube al techo y reduce la distancia entre el y Tapia.
    cambia_paridad(&n, &m, &x_j, &y_j, &x_t, &y_t);
  }
  ve_si_tapia_es_atrapable(&x_j, &y_j, &x_t, &y_t);
  // Persecucion de Tapia.
  if (std::abs(y_j - y_t) >= std::abs(x_j - x_t) + 1) {
    if (y_j > 1 &&
        (std::abs(y_j - 1 - y_t) < std::abs(y_j + 1 - y_t) || y_j == m)) {
      juan_a_la_izquierda(&x_j, &y_j, &x_t, &y_t);
      juega(n, m, x_j, y_j, x_t, y_t);
      return;
    } else {
      juan_a_la_derecha(&x_j, &y_j, &x_t, &y_t);
      juega(n, m, x_j, y_j, x_t, y_t);
      return;
    }
  }
  baja_a_juan(&x_j, &y_j, &x_t, &y_t);
  juega(n, m, x_j, y_j, x_t, y_t);
  return;
}
