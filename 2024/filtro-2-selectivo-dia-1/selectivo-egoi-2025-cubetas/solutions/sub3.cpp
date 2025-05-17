// Sub3: Hacemos la misma idea que la solucion oficial,
// pero utilizaremos un vector de tamaño 10^6+1 como cubeta.

#include <iostream>
#include <vector>

const int MaxN = 1000001;

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<int> cubeta(MaxN, 0);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    cubeta[x]++;
  }

  int ans = 0;
  for (int i = 1; i < MaxN; i++) {
    int actual = cubeta[i], siguiente = cubeta[i + 1];
    ans += actual - std::min(actual, siguiente);
  }
  std::cout << ans << "\n";
}
