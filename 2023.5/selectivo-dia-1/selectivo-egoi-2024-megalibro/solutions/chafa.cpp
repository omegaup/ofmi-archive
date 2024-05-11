/*
Vamos a ir coloreando del menor al mayor tiempo
hasta que el número de paginas continuas sin colorear sea menor o igual a k
*/
#include <iostream>
#include <queue>
#include <utility>

typedef long long int lld;
typedef std::pair<lld, lld> pll;

const int MAXN = 200002;

int n, k;
lld arr[MAXN];
bool colored[MAXN];

int maxContiguous() {
  int maxContiguous = 0;
  int contiguous = 0;
  for (int i = 0; i < n; i++) {
    if (!colored[i]) {
      contiguous++;
    } else {
      maxContiguous = std::max(maxContiguous, contiguous);
      contiguous = 0;
    }
  }
  return std::max(maxContiguous, contiguous);
}

int main() {
  std::cin >> n >> k;
  std::priority_queue<pll> pq;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
    pq.push({-arr[i], i});
  }
  lld ans = 0;
  while (maxContiguous() > k) {
    pll top = pq.top();
    pq.pop();
    colored[top.second] = true;
    ans += -top.first;
  }
  std::cout << ans << std::endl;
  return 0;
}
