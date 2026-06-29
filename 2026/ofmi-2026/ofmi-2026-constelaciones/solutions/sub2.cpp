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

  if (d1.empty()) {
    for (int i = 1; i < d2.size(); ++i)
      std::cout << d2[i - 1] << " " << d2[i] << "\n";
    if (!d2.empty()) std::cout << d2.back() << " " << d2[0] << "\n";
    return 0;
  }

  int anterior = d1[0];
  for (int u : d2) {
    std::cout << anterior << " " << u << "\n";
    anterior = u;
  }

  std::cout << anterior << " " << d1[1] << "\n";
  for (int i = 2; i < d1.size(); i += 2)
    std::cout << d1[i] << " " << d1[i + 1] << "\n";
}
