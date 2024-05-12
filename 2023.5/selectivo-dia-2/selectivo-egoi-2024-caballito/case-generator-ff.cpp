#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// This thing exists because the graph generator takes ages to compile haha

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
  long long x = (rd() % (r - l + 1));
  return x + l;
}

std::vector<std::array<int, 2>> getGraphFromFile(int &N, int &M,
                                                 std::string casename) {
  std::ifstream fin;
  fin.open("graph-generator/graphs/graph-" + casename + ".in");

  fin >> N >> M;
  std::vector<std::array<int, 2>> G;
  for (int i = 0; i < M; i++) {
    int u, v;
    fin >> u >> v;
    G.push_back({u + 1, v + 1});
  }
  fin.close();

  return G;
}

int main() {
  std::ofstream input;

  for (int subtask = 1; subtask <= 3; subtask++) {
    int numberOfCases;
    int startPoint;
    if (subtask == 1) {
      numberOfCases = 5;
      startPoint = 6;
    } else if (subtask == 2) {
      numberOfCases = 5;
      startPoint = 6;
    } else if (subtask == 3) {
      numberOfCases = 7;
      startPoint = 8;
    }
    for (int case_n = 0; case_n < numberOfCases; case_n++) {
      int case_number = case_n + startPoint;
      std::string casename =
          "sub" + std::to_string(subtask) + "." + std::to_string(case_number);
      input.open("cases/" + casename + ".in");

      int N, M;
      auto G = getGraphFromFile(N, M, casename);

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
  return 0;
}