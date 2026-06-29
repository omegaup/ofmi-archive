#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  int m = 0;
  std::vector<int> d1, d2;

  for (int i = 0; i < n; ++i) {
    int degree;
    std::cin >> degree;

    m += degree;
    if (degree == 1)
      d1.push_back(i + 1);
    else if (degree == 2)
      d2.push_back(i + 1);
  }

  std::cout << m / 2 << "\n";

  // Esta solucion sirve dos propositos: funcionar para la subtarea 1 y estar
  // *casi* bien, pero fallar para la subtarea 2. En este caso, la solucion no
  // considera que haya solo uno o dos 2-degree.
  for (int i = 1; i < d2.size(); ++i)
    std::cout << d2[i - 1] << " " << d2[i] << "\n";
  if (!d2.empty()) std::cout << d2.back() << " " << d2[0] << "\n";

  for (int i = 0; i < d1.size(); i += 2)
    std::cout << d1[i] << " " << d1[i + 1] << "\n";
}
