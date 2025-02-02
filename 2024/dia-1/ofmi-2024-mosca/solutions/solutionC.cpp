#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_N = 2e5;
int nums[MAX_N + 1];

std::pair<int, int> queries[MAX_N];
std::pair<int, std::string> answers[MAX_N];

int main() {
  nums[0] = 0;
  int n, m, q;
  std::cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    std::cin >> nums[i];
    nums[i] += nums[i - 1];
  };
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int a;
    std::cin >> a;
    queries[i] = {a, i};
  };
  std::sort(queries, queries + q);
  int i = 1, j = 0;
  while (j < q) {
    if (nums[i] < queries[j].first) {
      i++;
      continue;
    };
    if (queries[j].first > nums[i]) {
      j++;
      continue;
    };
    std::string answer = "Abeja";
    if (i % 2) {
      answer = "Mosca";
    };
    answers[j] = {queries[j].second, answer};
    j++;
  };
  std::sort(answers, answers + q);
  for (int i = 0; i < q; ++i) {
    std::cout << answers[i].second << '\n';
  };
  return 0;
}
