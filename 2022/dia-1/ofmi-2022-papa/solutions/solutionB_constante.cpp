#include <string.h>

#include <iostream>

int main() {
  int maeva, lorena, ramona;
  std::cin >> maeva >> lorena >> ramona;

  int tiempoVuelta = maeva + lorena + ramona;

  int res = 45 % tiempoVuelta;

  std::string mordida;

  if (res == 0) {
    mordida = "Ramona";
  } else {
    if (res <= maeva) {
      mordida = "Maeva";
    } else {
      if (res <= maeva + lorena) {
        mordida = "Lorena";
      } else {
        mordida = "Ramona";
      }
    }
  }

  std::cout << mordida << std::endl;

  return 0;
}