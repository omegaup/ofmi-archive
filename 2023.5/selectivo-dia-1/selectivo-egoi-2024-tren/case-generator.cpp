#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

enum Strategy {
  kForceLargeMaxSum,
  kForceSmallMaxSum,
  kSubtask1Possible,
  kSubtask1Impossible,
  kSubtask2,
  kSubtask3,
  kSubtask4,
};

struct RandomGenerator {
  RandomGenerator(const std::vector<long long>& sequence)
      : seed(sequence.begin(), sequence.end()), engine(seed) {}

  long long Integer(long long l, long long r) {
    std::uniform_int_distribution<long long> distribution(l, r);
    return distribution(engine);
  }

  std::seed_seq seed;
  std::mt19937_64 engine;
};

struct TestMetadata {
  std::string filename;
  Strategy strategy;
  int n, c, score;
};

struct Testcase {
  static constexpr long long kLargeValues = 1000000000;
  static constexpr long long kSmallValues = 1000;

  Testcase(const TestMetadata& metadata, RandomGenerator& random)
      : c(metadata.c), arr(metadata.n) {
    auto CreateArray = [&](long long max_value) {
      const auto r = std::min(metadata.n / 3ll, max_value / c) + 1;

      long long sum = 0;
      for (int i = 0; i < metadata.n; ++i) {
        arr[i] = random.Integer(0, c * r - 1) - sum;
        arr[i] = std::max(0ll, std::min(arr[i], max_value));
        sum = std::max(0ll, sum + arr[i] - c);
      }
    };

    switch (metadata.strategy) {
      case kForceLargeMaxSum:
        for (int i = 0; i < metadata.n; ++i) arr[i] = kLargeValues;
        break;
      case kForceSmallMaxSum:
        for (int i = 0; i < metadata.n; ++i) arr[i] = kSmallValues;
        break;
      case kSubtask1Possible:
        arr[0] = random.Integer(0, metadata.c - 1);
        break;
      case kSubtask1Impossible:
        arr[0] = random.Integer(metadata.c, kLargeValues);
        break;
      case kSubtask2:
      case kSubtask3:
        CreateArray(kSmallValues);
        break;
      case kSubtask4:
        CreateArray(kLargeValues);
        break;
    }
  }

  void ToFile(const std::string& filename) {
    std::ofstream file(filename);
    file << arr.size() << ' ' << c << '\n';
    for (const auto a : arr) file << a << ' ';
    file << '\n';
    file.close();
  }

  long long c;
  std::vector<long long> arr;
};

int main() {
  const std::vector<TestMetadata> metadata_arr = {
      {"sub1.case01", kSubtask1Possible, 1, 1, 8},
      {"sub1.case02", kSubtask1Possible, 1, 777, 0},
      {"sub1.case03", kSubtask1Possible, 1, 97179, 0},
      {"sub1.case04", kSubtask1Possible, 1, 1000000000, 0},
      {"sub1.case05", kSubtask1Impossible, 1, 1, 0},
      {"sub1.case06", kSubtask1Impossible, 1, 777, 0},
      {"sub1.case07", kSubtask1Impossible, 1, 97179, 0},
      {"sub1.case08", kSubtask1Impossible, 1, 1000000000, 0},
      {"sub2.case01", kSubtask2, 8, 5, 22},
      {"sub2.case02", kSubtask2, 19, 10, 0},
      {"sub2.case03", kSubtask2, 100, 100, 0},
      {"sub2.case04", kSubtask2, 777, 404, 0},
      {"sub2.case05", kForceSmallMaxSum, 1000, 1, 0},
      {"sub2.case06", kSubtask2, 1000, 1, 0},
      {"sub2.case07", kSubtask2, 1000, 50, 0},
      {"sub2.case08", kSubtask2, 1000, 117, 0},
      {"sub2.case09", kSubtask2, 1000, 300, 0},
      {"sub2.case10", kSubtask2, 1000, 777, 0},
      {"sub3.case01", kSubtask3, 2000, 1, 23},
      {"sub3.case02", kSubtask3, 5000, 1, 0},
      {"sub3.case03", kSubtask3, 7997, 1, 0},
      {"sub3.case04", kSubtask3, 12345, 1, 0},
      {"sub3.case05", kSubtask3, 50000, 1, 0},
      {"sub3.case06", kSubtask3, 99999, 1, 0},
      {"sub3.case07", kForceSmallMaxSum, 100000, 1, 0},
      {"sub3.case08", kSubtask3, 100000, 1, 0},
      {"sub3.case09", kSubtask3, 100000, 1, 0},
      {"sub3.case10", kSubtask3, 100000, 1, 0},
      {"sub4.case01", kSubtask4, 2000, 1000, 47},
      {"sub4.case02", kSubtask4, 5000, 7777777, 0},
      {"sub4.case03", kSubtask4, 20000, 9999999, 0},
      {"sub4.case04", kSubtask4, 50000, 10000000, 0},
      {"sub4.case05", kSubtask4, 100000, 17, 0},
      {"sub4.case06", kSubtask4, 100000, 117, 0},
      {"sub4.case07", kSubtask4, 100000, 2024, 0},
      {"sub4.case08", kSubtask4, 100000, 100000, 0},
      {"sub4.case09", kSubtask4, 100000, 9876543, 0},
      {"sub4.case10", kSubtask4, 100000, 100000000, 0},
      {"sub4.case11", kSubtask4, 100000, 1000000000, 0},
      {"sub4.case12", kForceLargeMaxSum, 100000, 1, 0},
  };

  RandomGenerator random({907133, -8095939, 50763409, 3581});

  std::ofstream testplan("testplan");
  testplan << "sub2.sample 0\n";

  for (const auto& metadata : metadata_arr) {
    Testcase(metadata, random).ToFile("cases/" + metadata.filename + ".in");
    testplan << metadata.filename << ' ' << metadata.score << '\n';
  }
  testplan.close();
  return 0;
}
