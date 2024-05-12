#include <iostream>
#include <string>
#include <vector>

const int MAXN = 300;
int mat[MAXN + 1][MAXN + 1];
int bu[MAXN + 1], bd[MAXN + 1], bl[MAXN + 1], br[MAXN + 1];

// Kadane's Algorithm
int max_subarray(const std::vector<int> &arr) {
  int curr_sum = 0, best_sum = 0;
  for (auto x : arr) {
    curr_sum = std::max(curr_sum + x, 0);
    best_sum = std::max(best_sum, curr_sum);
  }
  return best_sum;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M;
  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < M; j++) {
      mat[i][j] = s[j] == 'X' ? 0 : (s[j] == '1' ? -1 : 1);
    }
  }

  // Max submatrix in the top and the bottom
  for (int ini = 0; ini < N; ini++) {
    std::vector<int> arr(M);
    for (int fin = ini; fin < N; fin++) {
      for (int i = 0; i < M; i++) {
        arr[i] += mat[fin][i];
      }
      int best_sum = max_subarray(arr);
      bu[fin] = std::max(bu[fin], best_sum);
      bd[ini] = std::max(bd[ini], best_sum);
    }
  }
  // Max submatrix in the left and the right
  for (int ini = 0; ini < M; ini++) {
    std::vector<int> arr(N);
    for (int fin = ini; fin < M; fin++) {
      for (int i = 0; i < N; i++) {
        arr[i] += mat[i][fin];
      }
      int best_sum = max_subarray(arr);
      bl[fin] = std::max(bl[fin], best_sum);
      br[ini] = std::max(br[ini], best_sum);
    }
  }

  // Get max for all the submatrix in the same side
  for (int i = 1; i < N; i++) {
    bu[i] = std::max(bu[i], bu[i - 1]);
  }
  for (int i = N - 2; i >= 0; i--) {
    bd[i] = std::max(bd[i], bd[i + 1]);
  }
  for (int i = 1; i < M; i++) {
    bl[i] = std::max(bl[i], bl[i - 1]);
  }
  for (int i = M - 2; i >= 0; i--) {
    br[i] = std::max(br[i], br[i + 1]);
  }

  int cnt = 0;
  // Count original number of ones
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cnt += mat[i][j] == -1;
    }
  }

  // Get the answer
  int res = cnt;
  for (int i = 1; i < N; i++) {
    res = std::max(res, cnt + bu[i - 1] + bd[i]);
  }
  for (int i = 1; i < M; i++) {
    res = std::max(res, cnt + bl[i - 1] + br[i]);
  }
  std::cout << res << '\n';
  return 0;
}
