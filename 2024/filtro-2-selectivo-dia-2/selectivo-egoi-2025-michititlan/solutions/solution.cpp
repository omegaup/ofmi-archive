#include <iostream>
#include <vector>

constexpr int kMaxX = 1000;

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<int> dp_columna_actual(2 * kMaxX + 1);
  std::vector<int> dp_columna_previa(2 * kMaxX + 1);
  std::vector<int> dp_fila_actual(2 * kMaxX + 1);
  std::vector<int> dp_fila_previa(2 * kMaxX + 1);

  for (int i = 2 * kMaxX; i >= 0; --i)
    dp_columna_previa[i] = dp_fila_previa[i] = std::abs(i - kMaxX);

  // Las coordenadas previas son (0, 0) recorridas por `kMaxX`.
  int x, y, prev_x = kMaxX, prev_y = kMaxX;

  while (n--) {
    std::cin >> x >> y;

    // Las coordenadas se traducen a numeros indexados en 0.
    x += kMaxX, y += kMaxX;

    for (int i = 2 * kMaxX; i >= 0; --i) {
      dp_columna_actual[i] =
          std::min(dp_columna_previa[i] + std::abs(y - prev_y),
                   dp_fila_previa[y] + std::abs(i - prev_x));

      dp_fila_actual[i] = std::min(dp_columna_previa[x] + std::abs(i - prev_y),
                                   dp_fila_previa[i] + std::abs(x - prev_x));
    }

    dp_columna_previa.swap(dp_columna_actual);
    dp_fila_previa.swap(dp_fila_actual);
    prev_x = x, prev_y = y;
  }

  int mas_corto = std::min(dp_columna_previa[0], dp_fila_previa[0]);
  for (int i = 2 * kMaxX; i; --i) {
    mas_corto =
        std::min(mas_corto, std::min(dp_columna_previa[i], dp_fila_previa[i]));
  }
  std::cout << mas_corto << '\n';
}
