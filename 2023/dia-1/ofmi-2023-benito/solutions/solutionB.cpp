#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int> > mat;

bool checkEqualSquare(int l) {
  for (int k = l; k < n - l; ++k) {
    if (mat[l][k] != mat[k][l] || mat[l][k] != mat[n - l - 1][n - k - 1] ||
        mat[l][k] != mat[n - k - 1][n - l - 1]) {
      return false;
    }
  }
  return true;
}

bool checkIncreasingDiagonal() {
  if (mat[0][0] != 1) {
    return false;
  }
  for (int i = 0; i < n / 2; ++i) {
    if (mat[i][i] + 1 != mat[i + 1][i + 1]) {
      return false;
    }
  }
  return true;
}

bool checkDecreasingDiagonal() {
  if (mat[n / 2][n / 2] != 1) {
    return false;
  }
  for (int i = 0; i < n / 2; ++i) {
    if (mat[i][i] - 1 != mat[i + 1][i + 1]) {
      return false;
    }
  }
  return true;
}

bool isSpiralMatrix() {
  for (int l = 0; l < n / 2; ++l) {
    if (!checkEqualSquare(l)) {
      return false;
    }
  }
  return checkDecreasingDiagonal() || checkIncreasingDiagonal();
}

int main() {
  std::cin >> n;
  mat.resize(n);
  for (int i = 0; i < n; ++i) {
    mat[i].resize(n);
    for (int j = 0; j < n; ++j) {
      std::cin >> mat[i][j];
    }
  }

  bool spiral = isSpiralMatrix();
  if (spiral) {
    std::cout << n / 2 + 1 << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
  return 0;
}
