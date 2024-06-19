#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

std::mt19937_64 rd(43124091);

long long get_random(long long l, long long r) {
  long long x = (rd() % (r - l + 1));
  return x + l;
}

std::vector<int> random_values(int N, int L, int R) {
  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    A[i] = get_random(L, R);
  }
  return A;
}

int main() {
  std::ofstream input;

  for (int subtask = 1; subtask <= 5; subtask++) {
    int numberOfCases;
    int startPoint;
    int nLimit_L, nLimit_R;
    if (subtask == 1) {
      numberOfCases = 10;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1000;
    } else if (subtask == 2) {
      numberOfCases = 10;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1000;
    } else if (subtask == 3) {
      numberOfCases = 10;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 300;
    } else if (subtask == 4) {
      numberOfCases = 10;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1e5;
    } else if (subtask == 5) {
      numberOfCases = 16;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1e5;
    }
    for (int case_n = 0; case_n < numberOfCases; case_n++) {
      int case_number = case_n + startPoint;
      std::string casename =
          "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
      input.open("cases/" + casename + ".in");

      int N = nLimit_R;
      int M;
      if (subtask == 1) {
        M = 2;
      } else if (subtask == 2) {
        M = 3;
      } else {
        if (case_n & 1) {
          M = get_random(1, sqrt(N));
        } else {
          M = get_random(1, N);
        }
      }
      int K = get_random(1, N / M);
      if (subtask == 4) {
        K = 1;
      }
      auto A = random_values(N, 1, 1e9);

      input << N << ' ' << M << ' ' << K << '\n';
      for (int i = 0; i < N; i++) {
        input << A[i] << " \n"[i == N - 1];
      }
      input.close();
    }
  }

  std::ofstream testplan;
  testplan.open("testplan");

  testplan << "sub3.sample 0\n";
  int casesPerSubtask[] = {0, 10, 10, 10, 10, 16};
  int pointsPerSubtask[] = {0, 8, 12, 35, 9, 36};
  for (int subtask = 1; subtask <= 5; subtask++) {
    for (int case_number = 1; case_number <= casesPerSubtask[subtask];
         case_number++) {
      std::string casename =
          "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
      int points = case_number == 1 ? pointsPerSubtask[subtask] : 0;
      testplan << casename << " " << points << "\n";
    }
  }
  return 0;
}