#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::cout << std::max_element(a, a + n) - a + 1;
  return 0;
}