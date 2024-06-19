#include <iostream>
#include <string>
#include <vector>

const int MAXN = 300;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M;
  std::cin >> N >> M;

  int countZeros = 0, countOnes = 0;
  for (int i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < M; j++) {
      countZeros += s[j] == '0';
      countOnes += s[j] == '1';
    }
  }

  std::cout << countOnes + std::min(2, countZeros);
  return 0;
}