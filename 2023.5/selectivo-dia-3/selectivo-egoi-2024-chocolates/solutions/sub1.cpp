#include <algorithm>
#include <iostream>
#include <vector>
typedef long long int lld;
const int MAXN = 100002;

int n, m, k;
int arr[MAXN];

int main() {
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  /*
  Sub 1. Hay dos bolsas, entonces intentamos fijar
  donde cerrar la primera bolsa, calculamos los k
  menores elementos y los sumamos.
  */
  if (m != 2 || n > 1000) {
    std::cout << "0\n";
    return 0;
  }
  lld min_sum = 1e15;
  int idxAns = 0;
  for (int i = k; i < n - k; i++) {
    std::vector<int> tmp(arr, arr + n);
    // Ordenamos de 1 a i
    std::sort(tmp.begin(), tmp.begin() + i + 1);
    // Ordenamos de i + 1 a n
    std::sort(tmp.begin() + i + 1, tmp.end());
    // Obtenemos la suma de los k menores
    lld sum = 0;
    for (int j = 0; j < k; j++) {
      sum += tmp[j];
      sum += tmp[j + (i + 1)];
    }
    if (sum < min_sum) {
      min_sum = sum;
      idxAns = i;
    }
  }
  std::cout << idxAns + 1 << '\n';
  return 0;
}
