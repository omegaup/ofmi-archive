#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>

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
    return ((long long)(overtake.x.den ^ overtake.x.num) << 32) ^
           (long long)(overtake.time.den ^ overtake.time.num);
  }
};

struct Ship {
  long long x, v;
};

const int MAXN = 2.5e5;
Ship S[MAXN + 1];
std::unordered_set<Overtake, overtake_hash> ovt;

int main(int argc, char* argv[]) {
  std::string filename = argv[1];
  std::ifstream fin;
  fin.open(filename);

  std::string casename = filename.substr(9, filename.size() - 9 - 3);
  std::string caseNumber = casename.substr(9, casename.size() - 9);

  int N;
  fin >> N;
  for (int i = 0; i < N; i++) {
    fin >> S[i].x >> S[i].v;
  }

  bool failedTest = false;
  std::vector<Ship> B;
  long long totalOvertakes = 0;
  for (int i = 0; i < N; i++) {
    bool failedTest = false;
    std::vector<Overtake> ovtJ;
    for (auto s : B) {
      if (S[i].v >= s.v) continue;
      int dx = s.x - S[i].x;
      int dv = S[i].v - s.v;
      Overtake overtake = {Fraction(dx, dv),
                           Fraction(S[i].x * dv + S[i].v * dx, dv)};
      if (ovt.count(overtake)) {
        failedTest = true;
        break;
      } else {
        ovtJ.push_back(overtake);
      }
    }
    if (!failedTest) {
      totalOvertakes += ovtJ.size();
      for (auto c : ovtJ) {
        ovt.insert(c);
      }
      B.push_back(S[i]);
    }
  }

  std::ofstream output;
  output.open("cases/case" + caseNumber + ".in");

  output << B.size() << '\n';
  for (auto s : B) {
    output << s.x << ' ' << s.v << '\n';
  }

  output.close();
  return 0;
}