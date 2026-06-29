#include <iostream>

int main() {
  int n;
  std::string comandos;
  std::cin >> n >> comandos;

  int latitud = 0, longitud = 0;
  for (int i = 0; i < n; i++) {
    if (comandos[i] == '^') {
      latitud++;
    } else if (comandos[i] == 'v') {
      latitud--;
    } else if (comandos[i] == '>') {
      longitud++;
    } else {
      longitud--;
    }
  }
  std::cout << latitud << ' ' << longitud << '\n';
}
