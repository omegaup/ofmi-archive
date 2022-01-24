#include <algorithm>
#include <iostream>
#include <vector>

const int LIM_SEG = 17;
const int MAX_MCM = 720721;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

std::vector<long long> a(MAX_N);

std::vector<long long> cubeta(LIM_SEG);

std::vector<long long> saltos(MAX_MCM);

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    cubeta[a[i]]++;
  }
  // mcm = mcm(a_0, a_1, ..., a_n-1)
  long long mcm = a[0];
  for (int i = 1; i < n; i++) {
    mcm = (mcm * a[i]) / std::__gcd(mcm, a[i]);
  }
  for (int i = 1; i < LIM_SEG; i++) {
    for (int j = i; j <= mcm; j += i) {
      saltos[j] += cubeta[i];
    }
  }
  for (int i = 2; i <= mcm; i++) {
    saltos[i] += saltos[i - 1];
  }
  long long saltos_por_ciclo = saltos[mcm];
  int q, x;
  long long mTotal = 0, m;
  long long respuesta = 0;
  std::cin >> q >> x;
  while (q--) {
    mTotal += x;
    m = mTotal;
    // Sumamos los segundos que tardamos en los multiplos del mcm.
    long long segundos = mcm * (m / saltos_por_ciclo);
    m %= saltos_por_ciclo;
    // Busqueda binaria sobre saltos[] para encontrar la menor cantidad de
    // segundos restantes.
    int lower_b = 0, upper_b = mcm, lower_seg;
    while (lower_b <= upper_b) {
      int mitad = (lower_b + upper_b) / 2;
      if (m <= saltos[mitad]) {
        lower_seg = mitad;
        upper_b = mitad - 1;
      } else {
        lower_b = mitad + 1;
      }
    }
    segundos += lower_seg;
    respuesta = (respuesta + (segundos % MOD)) % MOD;
  }
  std::cout << respuesta << "\n";
}