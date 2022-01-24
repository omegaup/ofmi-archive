#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int arr[n + 1];
  int maxArg = 1;
  for (int i = 1; i <= n; ++i) {
    std::cin >> arr[i];
    if (arr[i] > arr[maxArg]) {
      maxArg = i;
    }
  }
  std::cout << maxArg << std::endl;
  return 0;
}
