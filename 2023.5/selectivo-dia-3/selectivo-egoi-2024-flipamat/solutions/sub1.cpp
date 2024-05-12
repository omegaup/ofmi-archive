#include <iostream>

const int MAXN = 12;

int n, m;
char a[MAXN][MAXN];
int pre1s[MAXN][MAXN][MAXN][MAXN];
int pre0s[MAXN][MAXN][MAXN][MAXN];

struct Rect {
  int x1, y1, x2, y2;
};

bool overlap(const Rect& a, const Rect& b) {
  int x1 = std::max(a.x1, b.x1);
  int x2 = std::min(a.x2, b.x2);
  if (x1 > x2) return false;
  int y1 = std::max(a.y1, b.y1);
  int y2 = std::min(a.y2, b.y2);
  return y1 <= y2;
}

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  // Precalculamos la suma de 1s y 0s en los subrectangulos
  for (int x1 = 1; x1 <= n; x1++) {
    for (int y1 = 1; y1 <= m; y1++) {
      for (int x2 = x1; x2 <= n; x2++) {
        for (int y2 = y1; y2 <= m; y2++) {
          pre1s[x1][y1][x2][y2] =
              (y2 > y1 ? pre1s[x1][y1][x2][y2 - 1] : 0) +
              (x2 > x1 ? pre1s[x1][y1][x2 - 1][y2] : 0) -
              (y2 > y1 && x2 > x1 ? pre1s[x1][y1][x2 - 1][y2 - 1] : 0) +
              (a[x2][y2] == '1');

          pre0s[x1][y1][x2][y2] =
              (y2 > y1 ? pre0s[x1][y1][x2][y2 - 1] : 0) +
              (x2 > x1 ? pre0s[x1][y1][x2 - 1][y2] : 0) -
              (y2 > y1 && x2 > x1 ? pre0s[x1][y1][x2 - 1][y2 - 1] : 0) +
              (a[x2][y2] == '0');
        }
      }
    }
  }

  // Calculamos para cada par de rectangulos
  int ans = 0;
  for (int x1 = 1; x1 <= n; x1++) {
    for (int y1 = 1; y1 <= m; y1++) {
      for (int x2 = x1; x2 <= n; x2++) {
        for (int y2 = y1; y2 <= m; y2++) {
          for (int xx1 = 1; xx1 <= n; xx1++) {
            for (int yy1 = 1; yy1 <= m; yy1++) {
              for (int xx2 = xx1; xx2 <= n; xx2++) {
                for (int yy2 = yy1; yy2 <= m; yy2++) {
                  Rect a = {x1, y1, x2, y2};
                  Rect b = {xx1, yy1, xx2, yy2};
                  if (overlap(a, b)) continue;
                  int funcionamiento = pre1s[1][1][n][m];
                  funcionamiento +=
                      pre0s[x1][y1][x2][y2] - pre1s[x1][y1][x2][y2];
                  funcionamiento +=
                      pre0s[xx1][yy1][xx2][yy2] - pre1s[xx1][yy1][xx2][yy2];
                  ans = std::max(ans, funcionamiento);
                }
              }
            }
          }
        }
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
