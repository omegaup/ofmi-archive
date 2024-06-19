#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long int lld;
typedef std::pair<int, int> pii;
const int MAXN = 100002;
const lld INF = 1e18;

int n, m, k;
int arr[MAXN];

lld pre[1002][1002];

// Te regresa el minimo costo de dividir los primeros i elementos en j bolsas
lld memo[1002][1002];
bool vis[1002][1002];
lld dp(int i, int j) {
  if (j * k > i + 1) {
    return memo[i][j] = INF;
  }
  if (j == 1) {
    return memo[i][j] = pre[0][i];
  }
  if (!vis[i][j]) {
    vis[i][j] = true;
    // Ver donde cortar para j-1 bolsas
    memo[i][j] = INF;
    for (int x = 0; x <= i - k; x++) {
      memo[i][j] = std::min(memo[i][j], dp(x, j - 1) + pre[x + 1][i]);
    }
  }
  return memo[i][j];
}

int main() {
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  /*
  Sub 2. Hay tres bolsas, entonces intentamos fijar
  i, j, precalculando la suma de los k menores elementos.
  */
  if (n > 300) {
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

  std::vector<int> ans;
  int i = n - 1;
  int j = m;
  while (j > 1) {
    for (int x = 0; x <= i - k; x++) {
      if (dp(i, j) == dp(x, j - 1) + pre[x + 1][i]) {
        ans.push_back(x);
        i = x;
        j--;
        break;
      }
    }
  }

  std::reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] + 1 << " ";
  }
  std::cout << "\n";
  return 0;
}
