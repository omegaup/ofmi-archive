#include <iostream>

const int MAX_NUM = 100;
int cubeta[2 * MAX_NUM + 1];

int main() {
  int n, m;
  std::cin >> n >> m;

  int num;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    cubeta[num + MAX_NUM]++;
  }

  int idx = 2 * MAX_NUM;
  while (m > 0 && idx > 100) {
    m -= cubeta[idx];
    if (m > 0) {
      idx--;
    }
  }

  if (m > 0) {
    std::cout << "sencillo\n";
  } else {
    std::cout << idx - MAX_NUM << "\n";
  }

  return 0;
}
