#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

// AC Solution
const int MAXN = 1e5;
int P[MAXN + 1];
std::pair<int, int> R[MAXN + 1];

void solve(std::ifstream &input, std::ofstream &output) {
  int N;
  input >> N;
  std::vector<std::pair<int, std::pair<int, int>>> points;
  for (int i = 0; i < N; i++) {
    input >> P[i];
    points.push_back({P[i], {0, i}});
  }
  for (int i = 0; i < N; i++) {
    int l, r;
    input >> l >> r;
    R[i] = {l, r};
    points.push_back({l, {-1, i}});
    points.push_back({r, {1, i}});
  }
  std::sort(points.begin(), points.end());

  std::set<std::pair<int, int>> st;
  std::vector<int> res(N, -1);
  bool fin = true;
  for (auto [x, p] : points) {
    if (p.first == 0) {
      if (st.empty()) {
        fin = false;
        break;
      }
      auto it = st.begin();
      res[it->second] = p.second;
      st.erase(it);
    } else if (p.first == -1) {
      st.insert({R[p.second].second, p.second});
    } else if (p.first == 1) {
      st.erase({x, p.second});
    }
  }
  if (fin) {
    output << res[0];
    for (int i = 1; i < N; i++) {
      output << ' ' << res[i];
    }
    output << '\n';
  } else
    output << -1 << '\n';
  return;
}

// Subtasks limits
const int total_subtasks = 6;
int number_of_cases[total_subtasks + 1] = {
    0,
    10,  // 1
    10,  // 2
    15,  // 3
    20,  // 4
    15,  // 5
    15,  // 6
};

int main() {
  std::ifstream input;
  std::ofstream output;

  input.open("cases/sub1.sample.in");
  output.open("cases/sub1.sample.out");
  solve(input, output);
  input.close();
  output.close();

  // Number of subtask
  for (int subtask = 1; subtask <= total_subtasks; subtask++) {
    // Number of case
    for (int case_number = 1; case_number <= number_of_cases[subtask];
         case_number++) {
      std::string casename = "cases/sub" + std::to_string(subtask) + "." +
                             std::to_string(case_number);
      input.open(casename + ".in");
      output.open(casename + ".out");
      solve(input, output);
      input.close();
      output.close();
    }
  }
  return 0;
}