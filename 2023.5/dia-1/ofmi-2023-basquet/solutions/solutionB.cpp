#include <iostream>

int playeras[6];
int suma_playeras;

int main() {
  for (int i = 1; i <= 5; i++) std::cin >> playeras[i];

  for (int i = 1; i <= 3; i++) {
    for (int j = i + 1; j <= 4; j++) {
      for (int k = j + 1; k <= 5; k++) {
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
