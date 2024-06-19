#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long int lld;
typedef std::pair<int, int> pii;
const int MAXN = 100002;

int n, m, k;
int arr[MAXN];

lld pre[1002][1002];

int main() {
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  /*
  Sub 2. Hay tres bolsas, entonces intentamos fijar
  i, j, precalculando la suma de los k menores elementos.
  */
  if (m != 3 || n > 1000) {
    std::cout << "0\n";
    return 0;
  }

  // precalculo
  for (int i = 0; i < n; i++) {
    std::priority_queue<int> pq;
    lld pqSum = 0;
    for (int j = i; j < n; j++) {
      pq.push(arr[j]);
      pqSum += arr[j];
      if (pq.size() > k) {
        pqSum -= pq.top();
        pq.pop();
      }
      pre[i][j] = pqSum;
    }
  }

  lld min_sum = 1e15;
  pii idxAns = {0, 0};

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      // Nos aseguramos que hay k elementos en cada bolsa
      if (i + 1 < k || j - i < k || n - j - 1 < k) {
        continue;
      }
      lld sum = pre[0][i] + pre[i + 1][j] + pre[j + 1][n - 1];
      if (sum < min_sum) {
        min_sum = sum;
        idxAns = {i, j};
      }
    }
  }

  std::cout << idxAns.first + 1 << " " << idxAns.second + 1 << '\n';
  return 0;
}
