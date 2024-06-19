#include <iostream>
#include <vector>

const int MAXN = 1e5;

struct Fenwick {
 private:
  std::vector<int> bit;
  int n;

 public:
  Fenwick(int _n) : bit(_n), n(_n) {}
  void update(int i, int x) {
    for (; i < n; i += (i & -i)) bit[i] += x;
  }
  int query(int i) {
    int res = 0;
    for (; i > 0; i &= (i - 1)) res += bit[i];
    return res;
  }
};

int A[MAXN + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
  }
  Fenwick ft(N + 1);
  int res = 0;
  for (int i = N; i >= 1; i--) {
    int qr = ft.query(A[i]);
    if (qr > 2) {
      std::cout << -1;
      return 0;
    }
    res += qr;
    ft.update(A[i], 1);
  }
  std::cout << res;
  return 0;
}