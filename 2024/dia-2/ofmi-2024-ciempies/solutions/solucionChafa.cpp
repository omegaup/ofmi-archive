#include <iostream>
#include <vector>

int main() {
  int n;
  std ::cin >> n;
  std ::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std ::cin >> A[i];
  }

  for (int i = 0; i < n; i++) {
    std ::cout << A[i] << " ";
  }
  std ::cout << "\n";
}
