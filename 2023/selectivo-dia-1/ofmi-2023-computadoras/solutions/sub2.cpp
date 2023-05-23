#include <algorithm>
#include <vector>

#include "computadoras.h"

const int MAXN = 5002;
// Ordena las computadoras 1 a la n
// en indices[i] queda el indice original de la computadora i
int indices[MAXN];
void ordenaComputadoras(int n, int P[], int M[]) {
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }
  std::sort(indices, indices + n, [&](int i, int j) {
    return P[i] < P[j] || (P[i] == P[j] && M[i] < M[j]);
  });
  int P_ordenado[n], M_ordenado[n];
  for (int i = 0; i < n; ++i) {
    P_ordenado[i] = P[indices[i]];
    M_ordenado[i] = M[indices[i]];
  }
  for (int i = 0; i < n; ++i) {
    P[i] = P_ordenado[i];
    M[i] = M_ordenado[i];
  }
}

void computadoras(int n, int p, int m, int P[], int M[]) {
  ordenaComputadoras(n, P, M);
  // Como las Ps son distintas solo queremos hacer LIS estrictamente
  // creciente en las M
  std::vector<int> lis;
  int idx[n];
  int prev[n];
  for (int i = 0; i < n; ++i) {
    int pos = std::lower_bound(lis.begin(), lis.end(), M[i]) - lis.begin();
    if (pos == lis.size()) {
      lis.push_back(M[i]);
    } else {
      lis[pos] = M[i];
    }
    idx[pos] = i;
    prev[i] = pos == 0 ? -1 : idx[pos - 1];
  }
  std::vector<int> ans;
  int curr = idx[lis.size() - 1];
  while (curr != -1) {
    ans.push_back(indices[curr] + 1);
    curr = prev[curr];
  }
  ans.push_back(0);
  std::reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    presenta(ans[i]);
  }
}
