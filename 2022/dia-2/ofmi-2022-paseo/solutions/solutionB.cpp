#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N, K;
  std::vector<int> T;

  std::cin >> N >> K;
  T.resize(N);

  for (int i = 0; i < N; i++) std::cin >> T[i];

  sort(T.begin(), T.end());

  std::vector<int> diff;
  diff.resize(N - 1);

  for (int i = 1; i < N; i++) diff[i - 1] = T[i] - T[i - 1];

  sort(diff.begin(), diff.end());

  long long c = 0;
  for (int i = 0; i < diff.size() - (K - 1); i++) c += diff[i];

  std::cout << c << std::endl;

  return 0;
}
