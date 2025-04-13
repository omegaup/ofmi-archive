// Sub3: Simular la llegada de aviones a hangares con una priority_queue,
// guardando el tiempo de espera y el hangar correspondiente.

#include <iostream>
#include <queue>
#include <utility>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<long long> hangares(n);
  for (int i = 0; i < n; i++) {
    std::cin >> hangares[i];
  }

  std::priority_queue<std::pair<long long, long long>> aviones;

  for (int i = 0; i < n; i++) {
    aviones.push({0, -i});
  }

  while (k--) {
    auto actual = aviones.top();
    actual.first = -actual.first;
    actual.second = -actual.second;
    aviones.pop();

    actual.first += hangares[actual.second];
    aviones.push({-actual.first, -actual.second});
  }

  auto actual = aviones.top();
  actual.first = -actual.first;
  actual.second = -actual.second;
  std::cout << actual.first << " " << actual.second + 1 << '\n';
}
