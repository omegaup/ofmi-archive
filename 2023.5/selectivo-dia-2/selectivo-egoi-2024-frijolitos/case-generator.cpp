#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
  long long x = (rd() % (r - l + 1));
  return x + l;
}

std::vector<long long> distinctRandomValues(int N, long long L, long long R) {
  std::vector<long long> A(N);
  std::set<long long> nums;
  for (int i = 0; i < N; i++) {
    do {
      A[i] = get_random(L, R);
    } while (nums.count(A[i]));
    nums.insert(A[i]);
  }
  return A;
}

int main() {
  std::ofstream input;

  for (int subtask = 1; subtask <= 3; subtask++) {
    int numberOfCases;
    int startPoint;
    long long nLimit_L, nLimit_R;
    if (subtask == 1) {
      numberOfCases = 20;
      startPoint = 1;
      nLimit_L = 1;
      nLimit_R = 20;
    } else if (subtask == 2) {
      numberOfCases = 25;
      startPoint = 1;
      nLimit_L = 1;
      nLimit_R = 1e6;
    } else if (subtask == 3) {
      numberOfCases = 30;
      startPoint = 1;
      nLimit_L = 1;
      nLimit_R = 1e18;
    }
    auto N = distinctRandomValues(numberOfCases, nLimit_L, nLimit_R);
    if (subtask == 1) {
      std::iota(N.begin(), N.end(), 1);
      std::shuffle(N.begin(), N.end(), rd);
    }
    for (int case_n = 0; case_n < numberOfCases; case_n++) {
      int case_number = case_n + startPoint;
      std::string casename =
          "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
      input.open("cases/" + casename + ".in");

      input << N[case_n] << '\n';

      input.close();
    }
  }

  std::ofstream testplan;
  testplan.open("testplan");

  testplan << "sub1.sample 0\n";
  int casesPerSubtask[] = {0, 20, 25, 30};
  for (int subtask = 1; subtask <= 3; subtask++) {
    for (int case_number = 1; case_number <= casesPerSubtask[subtask];
         case_number++) {
      std::string casename =
          "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
      testplan << casename << " 0\n";
    }
  }
  return 0;
}