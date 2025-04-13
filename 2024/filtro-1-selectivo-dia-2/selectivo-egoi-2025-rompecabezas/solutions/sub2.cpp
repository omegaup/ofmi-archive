// Sub 2: Se utiliza una cubeta para simular las operaciones
// se calcula la respuesta para el primer '-'
// para cada '-' posterior se calcula si el número es menor
// que la respuesta y si la aparición es cero, se actualiza la respuesta

#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, q, realq;
  std::cin >> n >> q;
  realq = q;

  std::vector<int> aparicion(q + 1, 0);

  int ans = 1e9;
  while (q--) {
    char tipo;
    int ri;
    std::cin >> tipo >> ri;

    if (tipo == '+') {
      if (ri <= realq) aparicion[ri]++;
    } else {
      if (ri <= realq) aparicion[ri]--;

      for (int i = 1; i <= n; i++) {
        if (aparicion[i] == 0) {
          ans = i;
          break;
        }
      }

      std::cout << ((ans == 1e9) ? -1 : ans) << '\n';
      break;
    }
  }

  while (q--) {
    char tipo;
    int ri;
    std::cin >> tipo >> ri;

    if (ri <= realq) aparicion[ri]--;
    if (ri < std::min(ans, realq) && aparicion[ri] == 0) {
      ans = ri;
    }

    std::cout << ((ans == 1e9) ? -1 : ans) << '\n';
  }
}
