#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 1e5;

int A[MAXN + 1];
int p[MAXN + 1];

int main() {
  // Read case.in
  int N, M, K;
  {
    std::ifstream din("data.in", std::ifstream::in);
    din >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
      din >> A[i];
    }
  }
  // Calculate sum of M*K smallest elements
  std::priority_queue<int> pq;
  for (int i = 1; i <= N; i++) {
    pq.push(A[i]);
    if (pq.size() > M * K) pq.pop();
  }
  long long result = 0;
  while (!pq.empty()) {
    result += pq.top();
    pq.pop();
  }

  // Contestant output
  p[0] = 0;
  for (int i = 1; i < M; i++) {
    if (!(std::cin >> p[i])) {
      std::cerr << "Error reading contestant output\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }
  p[M] = N;

  {  // Check that there isn't aditional output
    int x;
    if (std::cin >> x) {
      std::cerr << "More than M-1 integers in output\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }

  // Check if partition is valid
  for (int i = 1; i <= M; i++) {
    if (p[i] <= p[i - 1]) {
      std::cerr << "The partition is invalid\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    if (p[i] - p[i - 1] < K) {
      std::cerr << "The partition is invalid\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }

  // Check if the sum of K smallest elements in subarrays
  // give the correct answer
  long long contestantResult = 0;
  for (int m = 1; m <= M; m++) {
    for (int i = p[m - 1] + 1; i <= p[m]; i++) {
      pq.push(A[i]);
      if (pq.size() > K) pq.pop();
    }
    while (!pq.empty()) {
      contestantResult += pq.top();
      pq.pop();
    }
  }

  if (contestantResult != result) {
    std::cerr << "Wrong Answer\n";
    std::cout << 0.0 << '\n';
    return 0;
  }
  // The output is correct
  std::cout << 1.0 << '\n';
  return 0;
}