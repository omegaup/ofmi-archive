#include <iostream>
#include <vector>

struct Rango {
  bool operator<(const Rango& otro) const { return r - l < otro.r - otro.l; }

  int l, r;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  Rango rango_maximo{0, -1};
  std::vector<int> primera_aparicion(n + 2, n);

  for (int i = 0, menores_que_k = 0; i < n; ++i) {
    int puntaje;
    std::cin >> puntaje;
    menores_que_k += (puntaje < k) ? 1 : -1;

    Rango rango{0, i};
    if (menores_que_k >= 0) {
      primera_aparicion[menores_que_k] =
          std::min(primera_aparicion[menores_que_k], i);
      rango.l = primera_aparicion[menores_que_k + 1] + 1;
    }
    rango_maximo = std::max(rango, rango_maximo);
  }

  if (rango_maximo.r >= 0)
    std::cout << rango_maximo.l + 1 << ' ' << rango_maximo.r + 1 << '\n';
  else
    std::cout << "-1\n";
}
