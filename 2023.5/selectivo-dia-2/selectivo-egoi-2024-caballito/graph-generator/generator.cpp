// "jnhen.h" taked from https://github.com/ifsmirnov/jngen
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "jnhen.h"

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
  long long x = (rd() % (r - l + 1));
  return x + l;
}

std::vector<int> random_values(int N, long long L, long long R) {
  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    A[i] = get_random(L, R);
  }
  return A;
}

int main() {
  std::ofstream input;

  for (int subtask = 1; subtask <= 1; subtask++) {
    int numberOfCases;
    int startPoint;
    int nLimit_L, nLimit_R;
    int mLimit = 2e5;
    if (subtask == 1) {
      numberOfCases = 5;
      startPoint = 6;
      nLimit_L = 2;
      nLimit_R = 1e5;
    } else if (subtask == 2) {
      numberOfCases = 5;
      startPoint = 6;
      nLimit_L = 2;
      nLimit_R = 1000;
    } else if (subtask == 3) {
      numberOfCases = 7;
      startPoint = 8;
      nLimit_L = 2;
      nLimit_R = 1e5;
    }
    for (int case_n = 0; case_n < numberOfCases; case_n++) {
      int case_number = case_n + startPoint;
      std::string casename = "graph-sub" + std::to_string(subtask) + "." +
                             std::to_string(case_number);
      input.open(casename + ".in");

      int N = get_random(nLimit_L, nLimit_R);
      if (case_n >= numberOfCases - 2) {
        N = nLimit_R;
      }
      long long totalEdges = (N * (long long)(N - 1)) / 2;
      long long M =
          std::min(N - 1 + get_random(0, mLimit - (N - 1)), totalEdges);

      if (subtask == 1) {
        auto t = Tree::bamboo(N).shuffleAllBut({N - 1});
        input << t.printN().printM();
      } else {
        auto g = Graph::random(N, M).connected().g().shuffled();
        input << g.printN().printM();
      }
      input.close();
    }
  }
  return 0;
}