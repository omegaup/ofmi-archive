#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  int unos, doses = 0;
  if (k == 1) {
    int l, r, e;
    std::cin >> l >> r >> e;
    unos = r - l + 1;
  } else {
    int l1, r1, l2, r2, e;
    std::cin >> l1 >> r1 >> e;
    std::cin >> l2 >> r2 >> e;

    if (l2 < l1) {
      std::swap(l1, l2);
      std::swap(r1, r2);
    }

    if (r2 <= r1)
      doses = r2 - l2 + 1;
    else if (l2 <= r1)
      doses = r1 - l2 + 1;
    unos = r1 + r2 + 2 - l1 - l2 - doses;
  }

  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;

    if (x > 2)
      std::cout << "0\n";
    else if (x == 1)
      std::cout << unos << "\n";
    else
      std::cout << doses << "\n";
  }
}
