# Subasta de cobayas - Solución

## Subtarea 1 (10 puntos): $N \leq 3$

Para esta subtarea, dado que a lo más habrá tres pujas, podemos simular manualmente cada nueva puja, esto se puede hacer con una complejidad constante para cada puja.

```
int main() {
  int n;
  std::cin >> n;

  int a[4];
  a[0] = 0;  // Puja inicial
  std::cin >> a[1];
  if (2 <= n) {
    std::cin >> a[2];
  }
  if (3 <= n) {
    std::cin >> a[3];
  }

  int puja1 = 0, puja2 = 0;
  if (a[1] >= a[puja1] + a[puja2]) {
    puja2 = puja1;
    puja1 = 1;
  }
  if (2 <= n && a[2] >= a[puja1] + a[puja2]) {
    puja2 = puja1;
    puja1 = 2;
  }
  if (3 <= n && a[3] >= a[puja1] + a[puja2]) {
    puja2 = puja1;
    puja1 = 3;
  }

  std::cout << puja1 << "\n";
}
```

## Subtarea 2 (25 puntos).

Como se asegura que si una nueva puja es mayor a la última puja válida, entonces siempre será más grande que la suma de las dos últimas pujas válidas, bastaría con regresar la posición de la mayor puja.
Esto se puede hacer iterando sobre el arreglo o utilizando la función max_element, ambas opciones con una complejidad $O(n)$

```
    int main() {
      int n;
      std::cin >> n;
      int a[n];
      for (int i = 0; i < n; i++) {
        std::cin >> a[i];
      }
      std::cout << std::max_element(a, a + n) - a + 1;
      return 0;
    }
```

## Subtarea 3, sin restricciones (65 puntos).

Para cada nueva puja solo debemos tomar en cuenta las dos últimas pujas válidas,
si la nueva puja es mayor o igual a la suma de las dos anteriores, ahora la nueva
puja se convertirá en la mejor y la anterior mejor puja pasara a ser la segunda
mejor puja.

```
    int main() {
      int n;
      std::cin >> n;
      int ganador = 0;
      int mejor = 0;
      int segunda = 0;
      for (int i = 1; i <= n; i++) {
        int puja;
        std::cin >> puja;
        if (puja >= mejor + segunda) {
          segunda = mejor;
          mejor = puja;
          ganador = i;
        }
      }
      std::cout << ganador << std::endl;
    }
```
