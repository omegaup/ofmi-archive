#include <algorithm>
#include <iostream>

struct Fraction {
  Fraction() : a(0), b(0) {}
  Fraction(long long a, long long b) : a(a), b(b) {
    long long maxDivisor = std::__gcd<long long>(a, b);
    a /= maxDivisor;
    b /= maxDivisor;
  }
  long long a, b;

  bool operator==(const Fraction &f) const { return a == f.a && b == f.b; }

  bool operator<(const Fraction &f) const { return a * f.b < b * f.a; }
};

struct Ship {
  long long x, v;
  int id;
  bool operator==(const Ship &s) const { return id == s.id; }
  bool operator<(const Ship &s) const { return x == s.x ? v < s.v : x < s.x; }
};

struct Overtake {
  Overtake(Ship a, Ship b) : a(a), b(b) {
    long long dx = b.x - a.x;
    long long dv = a.v - b.v;
    time = Fraction(dx, dv);
    pos = Fraction(a.x * dv + a.v * dx, dv);
  }
  Ship a, b;
  Fraction time, pos;
  bool operator==(const Overtake &o) const {
    return (a == o.a && b == o.b) || (a == o.b && b == o.a);
  }
  bool operator<(const Overtake &o) const {
    if (time == o.time) {
      return pos < o.pos;
    }
    return time < o.time;
  }
};

const int MAXN = 1e6;
Ship A[MAXN + 1];

bool overtake_valid(Ship a, Ship b) { return a.x <= b.x && a.v > b.v; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M;
  std::cin >> N >> M;
  if (N == 1) return 0;
  for (int i = 0; i < N; i++) {
    std::cin >> A[i].x >> A[i].v;
    A[i].id = i + 1;
  }
  std::sort(A, A + N);

  // Subtarea 1
  if (M > 1) {
    return 0;
  }

  bool ovt_valido = overtake_valid(A[0], A[1]);
  Overtake ovt = Overtake(A[0], A[1]);
  for (int i = 2; i < N; i++) {
    Overtake next_ovt = Overtake(A[i - 1], A[i]);
    bool next_ovt_valido = overtake_valid(A[i - 1], A[i]);
    if (!ovt_valido) {
      ovt = next_ovt;
      ovt_valido = next_ovt_valido;
      continue;
    }
    if (next_ovt_valido) {
      ovt = std::min(ovt, next_ovt);
    }
  }

  std::cout << ovt.a.id << ' ' << ovt.b.id;
  return 0;
}
