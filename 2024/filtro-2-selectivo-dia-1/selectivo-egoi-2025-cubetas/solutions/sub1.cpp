// Sub1: Hacer cubeta de 1, 2 y 3, hacer conteo a mano.

#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<int> cubeta(4, 0);

  for (int i = 0; i < n; i++) {
    int ti;
    std::cin >> ti;
    cubeta[ti]++;
  }

  int ans = cubeta[1] - std::min(cubeta[1], cubeta[2]);
  ans += cubeta[2] - std::min(cubeta[2], cubeta[3]);
  ans += cubeta[3];

  std::cout << ans << "\n";
}
