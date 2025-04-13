// La busqueda binaria es incorrecta y solo debe dar la subtarea 3.

#include <iostream>
#include <vector>

int PosibleInicio(const std::vector<int>& T, int k, int m) {
  int mayores_que_k = 0;
  for (int i = 0; i < m; ++i) mayores_que_k += (T[i] >= k) ? 1 : 0;
  if (mayores_que_k > m / 2) return 1;

  for (int i = m; i < T.size(); ++i) {
    mayores_que_k += ((T[i] >= k) ? 1 : 0) - ((T[i - m] >= k) ? 1 : 0);
    if (mayores_que_k > m / 2) return i - m + 2;
  }
  return 0;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> T(n);
  for (int& Ti : T) std::cin >> Ti;

  int l = 1, r = n + 1;
  while (l < r) {
    int m = (l + r) / 2;

    if (PosibleInicio(T, k, m))
      l = m + 1;
    else
      r = m;
  }

  if (--l) {
    int inicio = PosibleInicio(T, k, l);
    std::cout << inicio << ' ' << inicio + l - 1 << '\n';
  } else {
    std::cout << "-1\n";
  }
  return 0;
}
