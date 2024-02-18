#include <iostream>

const int MAX_N = 300000;

int n;
int A[MAX_N];
int T[MAX_N];

// Para el Segment Tree
long long maxLeft[5 * MAX_N];
long long maxRight[5 * MAX_N];
long long maxContiguousSum[5 * MAX_N];
int lenLeft[5 * MAX_N];
int lenRight[5 * MAX_N];

void initializeST(int node, int l, int r) {
  if (l == r) {
    maxLeft[node] = maxRight[node] = maxContiguousSum[node] = (long long)A[l];
    lenLeft[node] = lenRight[node] = 1;
    return;
  }
  int m = (l + r) / 2;
  int leftNode = node * 2;
  int rightNode = leftNode + 1;

  initializeST(leftNode, l, m);
  initializeST(rightNode, m + 1, r);

  maxLeft[node] = maxRight[node] = maxContiguousSum[node] =
      maxContiguousSum[leftNode] + maxContiguousSum[rightNode];
  lenLeft[node] = lenRight[node] = (r - l) + 1;
}

void update(int node, int l, int r, int x) {
  if (x < l or x > r) {
    return;
  }

  if (l == r) {
    maxLeft[node] = maxRight[node] = maxContiguousSum[node] = 0;
    lenLeft[node] = lenRight[node] = 0;
    return;
  }

  int m = (l + r) / 2;
  int leftNode = node * 2;
  int rightNode = leftNode + 1;

  update(leftNode, l, m, x);
  update(rightNode, m + 1, r, x);

  maxContiguousSum[node] =
      std::max(maxContiguousSum[leftNode], maxContiguousSum[rightNode]);
  maxContiguousSum[node] =
      std::max(maxContiguousSum[node], maxRight[leftNode] + maxLeft[rightNode]);

  lenLeft[node] = lenLeft[leftNode];
  maxLeft[node] = maxLeft[leftNode];
  if (lenLeft[leftNode] == m - l + 1) {
    lenLeft[node] += lenLeft[rightNode];
    maxLeft[node] += maxLeft[rightNode];
  }

  lenRight[node] = lenRight[rightNode];
  maxRight[node] = maxRight[rightNode];
  if (lenRight[rightNode] == r - m) {
    lenRight[node] += lenRight[leftNode];
    maxRight[node] += maxRight[leftNode];
  }
}

int main() {
  /**
    Las siguientes tres lineas no son parte de la solucion,
    solo optimizan el tiempo que el programa tarda en las
    entradas y salidas (cin/cout).
  */
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> T[i];
  }

  initializeST(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    update(1, 0, n - 1, T[i]);
    std::cout << maxContiguousSum[1] << "\n";
  }

  return 0;
}
