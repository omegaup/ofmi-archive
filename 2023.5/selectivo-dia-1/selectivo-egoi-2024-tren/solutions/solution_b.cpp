#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, c;
  std::cin >> n >> c;

  long long grupos_acumulados = 0;
  for (int hora_actual = 0; hora_actual < n; ++hora_actual) {
    int a;
    std::cin >> a;
    grupos_acumulados += a;

    long long horas_para_subir = grupos_acumulados / c;
    grupos_acumulados = std::max(grupos_acumulados - c, 0LL);

    if (horas_para_subir < n - hora_actual)
      std::cout << horas_para_subir << ' ';
    else
      std::cout << "-1 ";
  }
  std::cout << '\n';
  return 0;
}
