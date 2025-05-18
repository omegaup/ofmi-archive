#include <iostream>

const long long MAX_COSTO = 5e7;

std::pair<int, int> arr[20002];
int n;
long long dp[2][2002][2];
long long answ = MAX_COSTO;

int main() {
  int x, y;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x >> y;
    arr[i] = {x + 1000, y + 1000};
  }

  for (int i = 0; i <= 2000; i++) {
    dp[0][i][0] = abs(1000 - arr[0].second) + abs(i - 1000);
    dp[0][i][1] = abs(1000 - arr[0].first) + abs(i - 1000);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 2000; j++) {
      dp[i % 2][j][0] = MAX_COSTO;
      dp[i % 2][j][1] = MAX_COSTO;
    }

    for (int j = 0; j <= 2000; j++) {
      // Vengo del axis 0
      // Mantuve el axis guardada,
      // Me movi en la otra axis
      // En la que me movi es la del previo
      dp[i % 2][j][0] =
          std::min(dp[i % 2][j][0], dp[(i + 1) % 2][j][0] +
                                        abs(arr[i].second - arr[i - 1].second));

      // Cambie el axis guardada,
      // Me movi en la que tenia antes guardada
      // la guardad es ahora el del previo dios, pues no se movio
      dp[i % 2][arr[i - 1].second][1] =
          std::min(dp[i % 2][arr[i - 1].second][1],
                   dp[(i + 1) % 2][j][0] + abs(arr[i].first - j));

      // Vengo del axis 1
      // Mantuve el axis guardada,
      // Me movi en la otra axis
      // En la que me movi es la del previo
      dp[i % 2][j][1] =
          std::min(dp[i % 2][j][1], dp[(i + 1) % 2][j][1] +
                                        abs(arr[i].first - arr[i - 1].first));

      // Cambie el axis guardada,
      // Me movi en la que tenia antes guardada
      // la guardad es ahora el del previo dios, pues no se movio
      dp[i % 2][arr[i - 1].first][0] =
          std::min(dp[i % 2][arr[i - 1].first][0],
                   dp[(i + 1) % 2][j][1] + abs(arr[i].second - j));
    }
  }

  for (int i = 0; i <= 2000; i++) {
    answ = std::min(answ, dp[(n + 1) % 2][i][0]);
    answ = std::min(answ, dp[(n + 1) % 2][i][1]);
  }
  std::cout << answ;
}
