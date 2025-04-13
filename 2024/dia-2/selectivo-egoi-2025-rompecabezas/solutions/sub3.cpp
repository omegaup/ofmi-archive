// Sub3: Utilizamos un set para almacenar los números faltantes, el .begin()
// nos da el primer faltante.

#include <iostream>
#include <queue>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  std::priority_queue<int> pq;
  while (q--) {
    int ri;
    char tipo;
    std::cin >> tipo >> ri;

    if (tipo == '+') {
      if (!pq.empty()) pq.pop();
    } else {
      pq.push(-ri);
      std::cout << -pq.top() << '\n';
    }
  }
}
