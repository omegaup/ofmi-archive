#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> pq;
  while (q--) {
    int ri;
    char type;
    std::cin >> type >> ri;

    if (type == '+') {
      if (!pq.empty()) pq.erase(pq.begin());
    } else {
      pq.insert(upper_bound(pq.begin(), pq.end(), ri), ri);
      std::cout << *pq.begin() << '\n';
    }
  }
}
