#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();
  int N, B, R, L;
  std::cin >> N >> B >> R >> L;
  for (int i = 0; i < N; ++i) {
    int Di;
    std::cin >> Di;
    if (Di > L) {
      Di = L;
    }
    if (B - Di < R) {
      Di = B - R;
    }
    B -= Di;
    std::cout << Di << "\n";
  }
  return 0;
}
