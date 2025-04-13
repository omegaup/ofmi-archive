#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> T(n);
  for (int i = 0; i < n; i++) {
    std::cin >> T[i];

    T[i] = (T[i] >= k) ? 1 : -1;
  }

  std::vector<int> pref(n + 1);
  std::unordered_map<int, int> aparicion;
  int ans = -1, inicio = 0, fin = 0;
  pref[0] = T[0];
  aparicion[T[0]] = 0;
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + T[i];
    if (aparicion.find(pref[i]) == aparicion.end()) aparicion[pref[i]] = i;
    if (pref[i] > 0) {
      ans = i + 1;
      inicio = 1;
      fin = i + 1;
    } else {
      if (aparicion.find(pref[i] - 1) != aparicion.end() &&
          i - aparicion[pref[i] - 1] + 1 > ans) {
        ans = i - aparicion[pref[i] - 1] + 1;
        inicio = aparicion[pref[i] - 1] + 2;
        fin = i + 1;
      }
    }
  }

  if (ans == -1) {
    std::cout << "-1\n";
  } else {
    std::cout << inicio << " " << fin << "\n";
  }

  return 0;
}
