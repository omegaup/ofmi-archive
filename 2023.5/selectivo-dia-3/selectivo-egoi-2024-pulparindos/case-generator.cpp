#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

struct Testcase {
  int N;
  std::vector<int> A;
  void print(std::string filename) {
    std::ofstream input;
    input.open(filename);
    input << N << '\n';
    for (int i = 0; i < N; i++) {
      input << A[i] << " \n"[i == N - 1];
    }
    input.close();
  }
};

struct RandomGen {
  std::mt19937_64 randomEngine;
  RandomGen(std::vector<int> seedSeq) {
    std::seed_seq seq(seedSeq.begin(), seedSeq.end());
    randomEngine.seed(seq);
  }
  long long getNumber(long long l, long long r) {
    std::uniform_int_distribution<long long> udist(l, r);
    return udist(randomEngine);
  }
};
RandomGen rd({-1134910723, -1541832926, 9347191, 859900364});

long long get_random(long long l, long long r) { return rd.getNumber(l, r); }

std::vector<int> randomPermutation(int N) {
  std::vector<int> A(N);
  std::iota(A.begin(), A.end(), 1);
  std::shuffle(A.begin(), A.end(), rd.randomEngine);
  return A;
}

std::vector<int> validPermutation(int N) {
  std::vector<int> A(N);
  std::iota(A.begin(), A.end(), 1);
  for (int i = 0; i < N; i++) {
    int jumps = get_random(0, std::min(2, i));
    for (int j = i; j > i - jumps; j--) {
      std::swap(A[j], A[j - 1]);
    }
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
      numberOfCases = 9;
      startPoint = 1;
    } else if (subtask == 2) {
      numberOfCases = 12;
      startPoint = 1;
      nLimit_L = 250;
      nLimit_R = 1000;
    } else if (subtask == 3) {
      numberOfCases = 20;
      startPoint = 1;
      nLimit_L = 5000;
      nLimit_R = 1e5;
    }
    if (subtask == 1) {
      std::vector<Testcase> tcs;
      tcs.push_back({1, {1}});
      tcs.push_back({2, {1, 2}});
      tcs.push_back({2, {2, 1}});
      std::vector<int> A = {1, 2, 3};
      for (int it = 0; it < 6; it++) {
        tcs.push_back({3, A});
        std::next_permutation(A.begin(), A.end());
      }
      std::shuffle(tcs.begin(), tcs.end(), rd.randomEngine);

      for (int case_n = 0; case_n < tcs.size(); case_n++) {
        int case_number = case_n + startPoint;
        std::string casename =
            "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
        std::string filename = "cases/" + casename + ".in";
        tcs[case_n].print(filename);
      }
    } else {
      for (int case_n = 0; case_n < numberOfCases; case_n++) {
        int N = get_random(nLimit_L, nLimit_R);
        if (case_n >= numberOfCases - 4) N = nLimit_R;
        std::vector<int> A;
        if (case_n & 1)
          A = randomPermutation(N);
        else
          A = validPermutation(N);

        int case_number = case_n + startPoint;
        std::string casename =
            "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
        input.open("cases/" + casename + ".in");

        input << N << '\n';
        for (int i = 0; i < N; i++) {
          input << A[i] << " \n"[i == N - 1];
        }

        input.close();
      }
    }
  }

  std::ofstream testplan;
  testplan.open("testplan");

  testplan << "sub2.sample 0\n";
  testplan << "sub3.sample 0\n";
  int casesPerSubtask[] = {0, 9, 12, 20};
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
