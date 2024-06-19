#include <algorithm>
#include <fstream>
#include <random>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

struct RandomGen {
  std::mt19937_64 randomEngine;
  RandomGen(std::vector<uint32_t> seedSeq) { seed(seedSeq); }
  RandomGen() {
    std::random_device rdev;
    std::vector<uint32_t> seedSeq;
    for (int i = 0; i < 4; i++) {
      seedSeq.push_back(rdev());
    }
    seed(seedSeq);
  }
  void seed(std::vector<uint32_t>& seedSeq) {
    std::seed_seq seq(seedSeq.begin(), seedSeq.end());
    randomEngine.seed(seq);
  }
  long long Int(long long l, long long r) {
    std::uniform_int_distribution<long long> udist(l, r);
    return udist(randomEngine);
  }
  std::vector<long long> IntArray(int N, int A_l, int A_r) {
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
      A[i] = Int(A_l, A_r);
    }
    return A;
  }
  std::vector<long long> IntDistinctArray(int N, int A_l, int A_r) {
    std::vector<long long> A(N);
    std::set<long long> S;
    for (int i = 0; i < N; i++) {
      do {
        A[i] = Int(A_l, A_r);
      } while (S.count(A[i]));
      S.insert(A[i]);
    }
    return A;
  }
};
RandomGen rnd({524944473, 893981846, 1401809892, 667536017});

struct Fraction {
  Fraction(long long n, long long d) : num(n), den(d) {
    const auto common_divisor = std::__gcd<long long>(num, den);
    num /= common_divisor;
    den /= common_divisor;
  }

  bool operator==(const Fraction& other) const {
    return num == other.num && den == other.den;
  }

  bool operator<(const Fraction& other) const {
    return (num * other.den) < (other.num * den);
  }

  long long num, den;
};

struct Overtake {
  bool operator==(const Overtake& other) const {
    return time == other.time && x == other.x;
  }
  bool operator<(const Overtake& other) const {
    if (time == other.time) {
      return x < other.x;
    }
    return time < other.time;
  }
  Fraction time, x;
};

struct overtake_hash {
  size_t operator()(const Overtake& overtake) const {
    return ((long long)(overtake.x.den ^ overtake.x.num) << 20) ^
           (long long)(overtake.time.den ^ overtake.time.num);
  }
};

struct Ship {
  long long x, v;
};

struct Range {
  bool operator<(const Range& other) const {
    return (r - l) < (other.r - other.l);
  }
  int length() { return r - l + 1; }
  int l, r;
};

const int MAXN = 2e4;
std::unordered_set<Overtake, overtake_hash> ovt;
std::vector<Overtake> race[MAXN + 1];

int main() {
  for (int caseNumber = 13; caseNumber <= 18; caseNumber++) {
    std::vector<long long> X = rnd.IntDistinctArray(MAXN, 1, 1e6);
    std::sort(X.begin(), X.end());
    std::vector<long long> V(MAXN);
    Range bestSubarray = {0, 0};
    int l = 0, r = 0;
    V[0] = rnd.Int(1, 1e6);
    r++;
    std::vector<std::pair<int, Overtake>> currOvt;
    while (r < MAXN) {
      int overallFail = true;
      for (int itCnt = 0; itCnt < 1; itCnt++) {
        V[r] = rnd.Int(1, 1e6);
        bool failedTest = false;
        for (int i = l; i < r; i++) {
          if (V[i] <= V[r]) continue;
          int dx = X[r] - X[i];
          int dv = V[i] - V[r];
          Overtake overtake = {Fraction(dx, dv),
                               Fraction(X[i] * dv + V[i] * dx, dv)};
          if (ovt.count(overtake)) {
            failedTest = true;
            break;
          } else {
            currOvt.push_back({i, overtake});
          }
        }
        if (!failedTest) {
          overallFail = false;
          break;
        } else {
          currOvt.clear();
        }
      }
      if (overallFail) {
        for (auto c : race[l]) {
          ovt.erase(c);
        }
        l++;
      } else {
        for (auto [i, c] : currOvt) {
          race[i].push_back(c);
          ovt.insert(c);
        }
        currOvt.clear();
        Range newSubarray = {l, r};
        bestSubarray = std::max(bestSubarray, newSubarray);
        r++;
      }
    }

    l = bestSubarray.l;
    r = bestSubarray.r;

    std::ofstream output;
    output.open("cases/case" + std::to_string(caseNumber) + ".in");

    output << bestSubarray.length() << '\n';
    for (int i = l; i <= r; i++) {
      output << X[i] << ' ' << V[i] << '\n';
    }

    output.close();
    for (int i = 0; i < MAXN; i++) {
      race[i].clear();
      race[i].shrink_to_fit();
    }
    ovt.clear();
  }
  return 0;
}