#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

enum Strategy : unsigned {
  kNone = 0,
  kAllOvertakes = 1 << 0,
  kOneQuery = 1 << 1,
  kSameSpeedsButOne = 1 << 2,
};

struct RandomGenerator {
  RandomGenerator(const std::vector<long long>& sequence)
      : seed(sequence.begin(), sequence.end()), engine(seed) {}

  long long Integer(long long l, long long r) {
    std::uniform_int_distribution<long long> distribution(l, r);
    return distribution(engine);
  }

  template <typename T>
  void Permutation(std::vector<T>& arr) {
    std::shuffle(arr.begin(), arr.end(), engine);
  }

  std::seed_seq seed;
  std::mt19937_64 engine;
};

struct TestMetadata {
  std::string filename;
  unsigned strategy;
  int n, score;
};

struct Fraction {
  Fraction(long long n, long long d) : num(n), den(d) {
    const auto common_divisor = std::gcd(num, den);
    num /= common_divisor;
    den /= common_divisor;
  }

  bool operator==(const Fraction& other) const {
    return num == other.num && den == other.den;
  }

  long long num, den;
};

struct Overtake {
  bool operator==(const Overtake& other) const {
    return time == other.time && x == other.x;
  }

  Fraction time, x;
};

struct Ship {
  long long x, v;
};

namespace std {

template <>
struct hash<Overtake> {
  size_t operator()(const Overtake& overtake) const {
    return std::hash<long long>()(overtake.time.num ^ overtake.time.den ^
                                  overtake.x.num ^ overtake.x.den);
  }
};

}  // namespace std

struct Testcase {
  static constexpr long long kMaxM = 1e4;
  static constexpr long long kMaxOvertakes = 1e8;
  static constexpr long long kMaxValue = 1e9;

  Testcase(const TestMetadata& metadata, RandomGenerator& random)
      : arr(metadata.n) {
    const auto kMaxV = std::min<long long>(metadata.n * 100, kMaxValue);
    const auto kMaxX = std::min<long long>(metadata.n * 10000, kMaxValue);

    if (metadata.strategy & kSameSpeedsButOne) {
      auto v = random.Integer(1, kMaxV);
      for (int i = 0; i < metadata.n; ++i) arr[i].v = v;

      while (v == arr[0].v) v = random.Integer(1, kMaxV);
      if (v < arr[0].v)
        arr[metadata.n - 1].v = v;
      else
        arr[0].v = v;
    } else {
      std::vector<long long> speeds(metadata.n);
      for (int i = 0; i < metadata.n; ++i) speeds[i] = random.Integer(1, kMaxV);

      std::sort(speeds.begin(), speeds.end());
      for (int i = 0; i < metadata.n; ++i)
        arr[i].v = speeds[metadata.n - i - 1];
    }

    std::vector<long long> permutation;
    permutation.reserve(metadata.n);

    if (metadata.strategy & kAllOvertakes) {
      for (int i = 0; i < metadata.n; ++i) permutation.push_back(i);
    } else if (metadata.strategy & kSameSpeedsButOne) {
      const auto k = random.Integer(0, metadata.n - 1);

      if (arr[0].v > arr[1].v) {
        for (int i = 1; i < metadata.n; ++i) permutation.push_back(i);
        permutation.insert(permutation.begin() + k, 0);
      } else {
        for (int i = metadata.n - 2; i >= 0; --i) permutation.push_back(i);
        permutation.insert(permutation.begin() + k, metadata.n - 1);
      }
    } else {
      long long remaining_overtakes = kMaxOvertakes;
      std::vector<long long> overtakes(metadata.n - 1);

      for (int i = 0; i < metadata.n - 1; ++i) {
        overtakes[i] = random.Integer(
            0, std::min<long long>(metadata.n - 1, remaining_overtakes));
        remaining_overtakes -= overtakes[i];
      }

      random.Permutation(overtakes);
      permutation.push_back(metadata.n - 1);

      for (int i = metadata.n - 2; i >= 0; --i) {
        const auto k = std::min<size_t>(overtakes[i], permutation.size());
        permutation.insert(permutation.end() - k, i);
      }
    }

    bool is_valid = false;
    while (!is_valid) {
      is_valid = true;
      {
        std::set<long long> positions;
        for (int i = 0; i < metadata.n; ++i) {
          auto x = random.Integer(0, kMaxX);
          while (positions.count(x)) x = random.Integer(0, kMaxX);
          positions.insert(x);
        }

        int i = 0;
        for (const auto x : positions) arr[permutation[i++]].x = x;
      }

      std::cout << "Trying permutation\n";
      std::unordered_set<Overtake> overtakes;
      overtakes.reserve(kMaxOvertakes);

      for (int i = 1; is_valid && i < metadata.n; ++i) {
        for (int j = 0; j < i && arr[j].v > arr[i].v; ++j) {
          if (arr[i].x < arr[j].x) continue;

          const auto dx = arr[i].x - arr[j].x;
          const auto dv = arr[j].v - arr[i].v;

          const Overtake overtake{Fraction(dx, dv),
                                  Fraction(arr[j].x * dv + arr[j].v * dx, dv)};

          is_valid &= !overtakes.count(overtake);
          if (!is_valid) break;
          overtakes.insert(overtake);
        }
      }

      if (is_valid)
        std::cout << "Generated " << overtakes.size() << " overtakes\n";
      m = std::min<long long>(overtakes.size(), kMaxM);
    }

    if (metadata.strategy & kOneQuery) m = 1;
    random.Permutation(arr);
  }

  void ToFile(const std::string& filename) {
    std::ofstream file(filename);
    file << arr.size() << ' ' << m << '\n';
    for (const auto& ship : arr) file << ship.x << ' ' << ship.v << '\n';
    file.close();
  }

  std::vector<Ship> arr;
  long long m;
};

int main() {
  const std::vector<TestMetadata> metadata_arr = {
      {"2_sub1.case01", kOneQuery, 10, 12},
      {"2_sub1.case02", kOneQuery, 100, 0},
      {"2_sub1.case03", kAllOvertakes | kOneQuery, 1000, 0},
      {"2_sub1.case04", kAllOvertakes | kOneQuery, 5000, 0},
      {"2_sub1.case05", kOneQuery, 10000, 0},
      {"2_sub1.case06", kOneQuery, 100000, 0},
      {"3_sub2.case01", kSameSpeedsButOne, 10, 23},
      {"3_sub2.case02", kSameSpeedsButOne, 100, 0},
      {"3_sub2.case03", kSameSpeedsButOne, 1000, 0},
      {"3_sub2.case04", kSameSpeedsButOne, 10000, 0},
      {"3_sub2.case05", kSameSpeedsButOne, 100000, 0},
      {"3_sub2.case06", kSameSpeedsButOne, 100000, 0},
      {"1_sub3.case01", kNone, 10, 25},
      {"1_sub3.case02", kAllOvertakes, 100, 0},
      {"1_sub3.case03", kNone, 200, 0},
      {"1_sub3.case04", kNone, 500, 0},
      {"1_sub3.case05", kAllOvertakes, 1000, 0},
      {"1_sub3.case06", kAllOvertakes, 1000, 0},
      {"1_sub3.case07", kNone, 1000, 0},
      {"1_sub3.case08", kNone, 1000, 0},
      {"4_sub4.case01", kAllOvertakes, 2000, 40},
      {"4_sub4.case02", kAllOvertakes, 5000, 0},
      {"4_sub4.case03", kNone, 10000, 0},
      {"4_sub4.case04", kNone, 50000, 0},
      {"4_sub4.case05", kNone, 100000, 0},
      {"4_sub4.case06", kNone, 100000, 0},
      {"4_sub4.case07", kNone, 100000, 0},
      {"4_sub4.case08", kNone, 100000, 0},
  };

  RandomGenerator random({-2978303, 7501379, -8641351});

  std::ofstream testplan("testplan");
  testplan << "1_sub3.sample 0\n";

  for (const auto& metadata : metadata_arr) {
    Testcase(metadata, random).ToFile("cases/" + metadata.filename + ".in");
    testplan << metadata.filename << ' ' << metadata.score << '\n';
  }
  testplan.close();
  return 0;
}
