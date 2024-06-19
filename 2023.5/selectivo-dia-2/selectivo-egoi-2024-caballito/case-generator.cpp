#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
  long long x = (rd() % (r - l + 1));
  return x + l;
}

std::vector<std::array<int, 2>> generateRandomTree(int N) {
  std::vector<std::array<int, 2>> T;
  std::vector<int> V(N - 2);
  std::vector<int> freq(N + 1, 0);
  for (int i = 0; i < N - 2; i++) {
    V[i] = get_random(1, N);
    freq[V[i]]++;
  }
  std::priority_queue<int> pq;
  for (int i = 1; i <= N; i++) {
    if (!freq[i]) pq.push(i);
  }
  for (int i = 0; i < N - 2; i++) {
    T.push_back({V[i], pq.top()});
    pq.pop();
    if (--freq[V[i]] == 0) pq.push(V[i]);
  }
  int u = pq.top();
  pq.pop();
  int v = pq.top();
  pq.pop();
  T.push_back({u, v});
  return T;
}

std::vector<std::array<int, 2>> generateRandomConnectedGraph(int N, int M) {
  auto T = generateRandomTree(N);
  std::vector<std::array<int, 2>> G;
  std::set<std::pair<int, int>> edges;
  for (auto [u, v] : T) {
    edges.insert({std::min(u, v) - 1, std::max(u, v) - 1});
    G.push_back({u, v});
  }
  int cnt = N - 1;
  while (cnt < M) {
    int u = get_random(1, N);
    int v = get_random(1, N);
    if (u == v) continue;
    if (edges.count({std::min(u, v), std::max(u, v)})) continue;
    G.push_back({u, v});
    edges.insert({std::min(u, v), std::max(u, v)});
    cnt++;
  }
  std::shuffle(G.begin(), G.end(), rd);
  return G;
}

std::vector<std::array<int, 2>> generateTreeLine(int N) {
  std::vector<int> A(N);
  std::iota(A.begin(), A.end(), 1);
  std::shuffle(A.begin(), A.end(), rd);
  std::vector<std::array<int, 2>> T;
  for (int i = 1; i < N; i++) {
    if (get_random(0, 1)) {
      T.push_back({A[i], A[i - 1]});
    } else {
      T.push_back({A[i - 1], A[i]});
    }
  }
  std::shuffle(T.begin(), T.end(), rd);
  return T;
}

int main() {
  std::ofstream input;

  for (int subtask = 1; subtask <= 3; subtask++) {
    int numberOfCases;
    int startPoint;
    int nLimit_L, nLimit_R;
    int mLimit = 2e5;
    if (subtask == 1) {
      numberOfCases = 5;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1e5;
    } else if (subtask == 2) {
      numberOfCases = 5;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1000;
    } else if (subtask == 3) {
      numberOfCases = 7;
      startPoint = 1;
      nLimit_L = 2;
      nLimit_R = 1e5;
    }
    for (int case_n = 0; case_n < numberOfCases; case_n++) {
      int case_number = case_n + startPoint;
      std::string casename =
          "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
      input.open("cases/" + casename + ".in");

      int N = get_random(nLimit_L, nLimit_R);
      if (case_n >= numberOfCases - 2) {
        N = nLimit_R;
      }
      long long totalEdges = (N * (long long)(N - 1)) / 2;
      long long M =
          std::min(N - 1 + get_random(0, mLimit - (N - 1)), totalEdges);

      std::vector<std::array<int, 2>> G;
      if (subtask == 1) {
        G = generateTreeLine(N);
        M = N - 1;
      } else {
        G = generateRandomConnectedGraph(N, M);
      }
      int X = get_random(1, 1e5);
      int Y = get_random(1, 1e5);
      int Z = get_random(1, 1e5);

      input << N << ' ' << M << '\n';
      input << X << ' ' << Y << ' ' << Z << '\n';
      for (auto [u, v] : G) {
        input << u << ' ' << v << '\n';
      }
      input.close();
    }
  }

  std::ofstream testplan;
  testplan.open("testplan");

  testplan << "sub2.sample 0\n";
  int casesPerSubtask[] = {0, 10, 10, 14};
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