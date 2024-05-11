#include <fstream>
#include <iostream>
#include <set>
#include <string>

const int MAXN = 1e5;

int P[MAXN + 1];
std::pair<int, int> R[MAXN + 1];

long long res[MAXN + 1];

int main() {
  // Leemos el caso.in
  int N;
  {
    std::ifstream din("data.in", std::ifstream::in);
    din >> N;
    for (int i = 0; i < N; i++) {
      din >> P[i];
    }
    for (int i = 0; i < N; i++) {
      din >> R[i].first >> R[i].second;
    }
  }

  // Checamos si existe solucion con el .out
  bool solutionExists;
  {
    std::ifstream din("data.out", std::ifstream::in);
    long long x;
    din >> x;
    solutionExists = (x != -1);
  }

  // Leemos la salida del concursante
  long long x;
  if (!(std::cin >> x)) {
    std::cerr << "Error reading contestant output\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // Checamos si la respuesta coicide
  // No existe solucion
  if (!solutionExists && x == -1) {
    if ((std::cin >> x)) {
      std::cerr << "Contestant output is incorrect\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    std::cout << 1.0 << '\n';
    return 0;
  }
  if (!solutionExists) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // Si existe una solucion
  res[0] = x;
  for (int i = 1; i < N; i++) {
    if (!(std::cin >> res[i])) {
      std::cerr << "Error reading contestant output\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }
  if ((std::cin >> x)) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  std::set<int> nums;
  for (int i = 0; i < N; i++) {
    if (res[i] < 0 || res[i] >= N) {
      std::cerr << "Contestant output is out of bounds\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
    nums.insert(res[i]);
  }
  if (nums.size() != N) {
    std::cerr << "Contestant output is incorrect\n";
    std::cout << 0.0 << '\n';
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (P[res[i]] < R[i].first || R[i].second < P[res[i]]) {
      std::cerr << "Contestant output is incorrect\n";
      std::cout << 0.0 << '\n';
      return 0;
    }
  }
  // Si llega aqui es que la respuesta esta bien
  std::cout << 1.0 << '\n';
  return 0;
}