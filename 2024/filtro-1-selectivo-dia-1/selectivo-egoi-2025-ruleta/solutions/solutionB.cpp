#include <algorithm>
#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::string ruleta;
  std::cin >> ruleta;

  int inicio, fin, premios, intentandos, ans, cont, rango;
  inicio = fin = premios = intentandos = ans = cont = rango = 0;

  while (cont < 2 * n) {
    cont++;

    if (ruleta[fin] == 'P')
      premios++;
    else
      intentandos++;

    fin = (fin + 1) % n;
    rango++;

    while (intentandos >= k || rango > n) {
      if (ruleta[inicio] == 'P')
        premios--;
      else
        intentandos--;

      inicio = (inicio + 1) % n;
      rango--;
    }
    ans = std::max(ans, premios);
  }

  std::cout << ans << "\n";
}
