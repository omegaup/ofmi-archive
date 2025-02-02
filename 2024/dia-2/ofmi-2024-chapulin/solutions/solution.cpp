#include <deque>
#include <iostream>

const int MaxN = 1e5 + 10;

int puntos[MaxN];
int hacer_saltos_S[MaxN];
int hacer_saltos_con_supersalto[MaxN];

int main() {
  /*
    Observemos que hacer saltos de S en S nos hara caer en todas las
    posiciones con el mismo residuo bajo el modulo S.

    El hacer un super-salto nos permite cambiar el tipo de posiciones a
    las que vamos a caer.

    Entonces, si consideramos los siguientes dos arreglos:
    * hacer_saltos_S[] = En la posicion [i] del arreglo guardamos la suma
        acumulada hacia la derecha de las posiciones con residuo [i] modulo S
    que encontrariamos si no hacemos un super-salto.
    * hacer_saltos_con_supersalto[] = En la posicion [i] del arreglo guardamos
        la suma acumulada hacia la derecha de las posiciones con residuo [i],
    considerando que en algun punto se hizo el super-salto.

    Actualizamos ambos arreglos con un barrido de las posiciones, empezando
    en el numero mas grande a la derecha. Esto es, desde cierta posicion K que
    tenga resiudo [i] bajo el modulo S, tendriamos que hacer_saltos_S[i] =
    puntos[K] + puntos[K+S] + puntos[K+2S] + puntos[K+3S] + ...
     hacer_saltos_S[i] = puntos[K] + ... + puntos[K+aS] + puntos[Y] +
                         puntos[Y+S] + puntos[Y+2S] + puntos[Y+3S] + ...
                        (Donde Y es el resultado de super-salto desde K+aS, esto
    es, Y <= K+aS + T)
   */
  int N, S, T;
  std::cin >> N >> S >> T;
  for (int i = 0; i < N; i++) {
    std::cin >> puntos[i];
  }

  // Hacer saltos mas grandes que [S-1] no nos sumara nada ya que es lo mismo
  // que hacer saltos menos o iguales a [S-1] y luego hacer saltos normales.
  T = std::min(T, S - 1);

  std::deque<std::pair<int, int>> maximos_saltos_sin_supersalto;
  for (int i = N - 1; i >= 0; i--) {
    int salto_actual = i % S;

    // Quitar salto que ya no podamos hacer
    while (!maximos_saltos_sin_supersalto.empty()) {
      int posicion = maximos_saltos_sin_supersalto.front().second;
      if (posicion > i + T) {
        maximos_saltos_sin_supersalto.pop_front();
      } else {
        break;
      }
    }

    int mejor_supersalto = hacer_saltos_con_supersalto[salto_actual];
    if (!maximos_saltos_sin_supersalto.empty()) {
      int hacer_supersalto = maximos_saltos_sin_supersalto.front().first;
      // Comparar si es mejor hacer el supersalto ahora o despues
      mejor_supersalto = std::max(hacer_supersalto, mejor_supersalto);
    }

    hacer_saltos_S[salto_actual] += puntos[i];
    hacer_saltos_con_supersalto[salto_actual] = puntos[i] + mejor_supersalto;

    // Agregar actual salto normal sin supersalto
    while (!maximos_saltos_sin_supersalto.empty()) {
      int ultimo_salto = maximos_saltos_sin_supersalto.back().first;
      if (ultimo_salto <= hacer_saltos_S[salto_actual]) {
        // Podemos hacer un mejor supersalto, entonces borramos el ultimo
        maximos_saltos_sin_supersalto.pop_back();
      } else {
        // No podemos hacer un mejor supersalto, entonces conservamos ese
        break;
      }
    }
    maximos_saltos_sin_supersalto.push_back(
        std::make_pair(hacer_saltos_S[salto_actual], i));
  }

  // Vemos donde fue mejor iniciar nuestra aventura
  int respuesta = 0;
  for (int i = 0; i < S; i++) {
    respuesta = std::max(respuesta, hacer_saltos_con_supersalto[i]);
  }

  std::cout << respuesta << "\n";
}
