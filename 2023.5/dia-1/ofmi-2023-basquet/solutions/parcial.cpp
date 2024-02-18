#include <iostream>

int playeras[6];
int suma_playeras;

int main() {
  for (int i = 1; i <= 5; i++) std::cin >> playeras[i];

  for (int i = 1; i <= 5; i++) {
    for (int j = 2; j <= 5; j++) {
      for (int k = 3; k <= 5; k++) {
        suma_playeras = playeras[i] + playeras[j] + playeras[k];
        if (suma_playeras == 100) {
          std::cout << playeras[i] << " " << playeras[j] << " " << playeras[k];
          return 0;
        }
      }
    }
  }

  std::cout << -1;
}
