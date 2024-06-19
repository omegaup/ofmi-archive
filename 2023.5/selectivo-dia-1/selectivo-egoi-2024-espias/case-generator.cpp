#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

enum Strategy {
  kAlwaysNext,
  kConnected,
  kFullRandom,
  kNextOrBegin,
  kPermutation,
  kSingleLoop,
};

struct RandomGenerator {
  RandomGenerator(const std::vector<long long>& sequence)
      : seed(sequence.begin(), sequence.end()), engine(seed) {}

  long long Integer(long long l, long long r) {
    std::uniform_int_distribution<long long> distribution(l, r);
    return distribution(engine);
  }

  long long CoinToss(long long a, long long b) {
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(engine) ? a : b;
  }

  void Permutation(std::vector<long long>& arr) {
    std::shuffle(arr.begin(), arr.end(), engine);
  }

  std::seed_seq seed;
  std::mt19937_64 engine;
};

bool IsValidPermutation(const std::vector<long long>& arr) {
  for (int i = 0; i < arr.size(); ++i)
    if (arr[i] == i + 1) return false;
  return true;
}

struct TestMetadata {
  std::string filename;
  Strategy strategy;
  int n, score;
};

struct Testcase {
  Testcase(const TestMetadata& metadata, RandomGenerator& random)
      : arr(metadata.n) {
    switch (metadata.strategy) {
      case kAlwaysNext:
        arr[metadata.n - 1] = 1;
        for (int i = 0; i < metadata.n - 1; ++i) arr[i] = i + 2;
        break;
      case kConnected: {
        std::vector<long long> permutation(metadata.n);
        for (int i = 0; i < metadata.n; ++i) permutation[i] = i;
        random.Permutation(permutation);

        int k = random.Integer(2, metadata.n - 1);
        for (int i = 1; i < k; ++i)
          arr[permutation[i - 1]] = permutation[i] + 1;
        arr[permutation[k - 1]] = permutation[0] + 1;

        for (int i = k; i < metadata.n; ++i)
          arr[permutation[i]] = permutation[random.Integer(0, i - 1)] + 1;
        break;
      }
      case kFullRandom:
        for (int i = 0; i < metadata.n; ++i)
          arr[i] = (i + random.Integer(1, metadata.n - 1)) % metadata.n + 1;
        break;
      case kNextOrBegin:
        arr[0] = 2, arr[metadata.n - 1] = 1;
        for (int i = 1; i < metadata.n - 1; ++i)
          arr[i] = random.CoinToss(1, i + 2);
        break;
      case kPermutation:
        for (int i = 0; i < metadata.n; ++i) arr[i] = i + 1;

        while (!IsValidPermutation(arr)) random.Permutation(arr);
        break;
      case kSingleLoop: {
        std::vector<long long> permutation(metadata.n);
        for (int i = 0; i < metadata.n; ++i) permutation[i] = i;
        random.Permutation(permutation);

        for (int i = 1; i < metadata.n; ++i)
          arr[permutation[i - 1]] = permutation[i] + 1;
        arr[permutation[metadata.n - 1]] = permutation[0] + 1;
        break;
      }
    }
  }

  void ToFile(const std::string& filename) {
    std::ofstream file(filename);
    file << arr.size() << '\n';
    for (long long a : arr) file << a << ' ';
    file << '\n';
    file.close();
  }

  std::vector<long long> arr;
};

int main() {
  const std::vector<TestMetadata> metadata_arr = {
      {"sub1.case01", kNextOrBegin, 7, 17},
      {"sub1.case02", kNextOrBegin, 8, 0},
      {"sub1.case03", kNextOrBegin, 13, 0},
      {"sub1.case04", kNextOrBegin, 17, 0},
      {"sub1.case05", kNextOrBegin, 23, 0},
      {"sub1.case06", kNextOrBegin, 100, 0},
      {"sub1.case07", kNextOrBegin, 777, 0},
      {"sub1.case08", kNextOrBegin, 919, 0},
      {"sub1.case09", kNextOrBegin, 1000, 0},
      {"sub1.case10", kNextOrBegin, 1001, 0},
      {"sub1.case11", kNextOrBegin, 2024, 0},
      {"sub1.case12", kNextOrBegin, 5000, 0},
      {"sub1.case13", kNextOrBegin, 100000, 0},
      {"sub1.case14", kNextOrBegin, 555555, 0},
      {"sub1.case15", kNextOrBegin, 1000000, 0},
      {"sub1.case16", kAlwaysNext, 100000, 0},
      {"sub2.case01", kPermutation, 6, 34},
      {"sub2.case02", kPermutation, 7, 0},
      {"sub2.case03", kPermutation, 8, 0},
      {"sub2.case04", kPermutation, 10, 0},
      {"sub2.case05", kPermutation, 19, 0},
      {"sub2.case06", kPermutation, 57, 0},
      {"sub2.case07", kPermutation, 100, 0},
      {"sub2.case08", kPermutation, 777, 0},
      {"sub2.case09", kPermutation, 1000, 0},
      {"sub2.case10", kPermutation, 12345, 0},
      {"sub2.case11", kPermutation, 50000, 0},
      {"sub2.case12", kPermutation, 100000, 0},
      {"sub2.case13", kPermutation, 500000, 0},
      {"sub2.case14", kPermutation, 1000000, 0},
      {"sub2.case15", kPermutation, 1000000, 0},
      {"sub2.case16", kSingleLoop, 6, 0},
      {"sub2.case17", kSingleLoop, 1000, 0},
      {"sub2.case18", kSingleLoop, 1000000, 0},
      {"sub3.case01", kConnected, 8, 49},
      {"sub3.case02", kConnected, 777, 0},
      {"sub3.case03", kConnected, 1003, 0},
      {"sub3.case04", kConnected, 500000, 0},
      {"sub3.case05", kConnected, 1000000, 0},
      {"sub3.case06", kConnected, 1000000, 0},
      {"sub3.case07", kFullRandom, 5, 0},
      {"sub3.case08", kFullRandom, 13, 0},
      {"sub3.case09", kFullRandom, 69, 0},
      {"sub3.case10", kFullRandom, 777, 0},
      {"sub3.case11", kFullRandom, 1000, 0},
      {"sub3.case12", kFullRandom, 4321, 0},
      {"sub3.case13", kFullRandom, 10000, 0},
      {"sub3.case14", kFullRandom, 20000, 0},
      {"sub3.case15", kFullRandom, 100000, 0},
      {"sub3.case16", kFullRandom, 200000, 0},
      {"sub3.case17", kFullRandom, 500000, 0},
      {"sub3.case18", kFullRandom, 1000000, 0},
      {"sub3.case19", kFullRandom, 1000000, 0},
      {"sub3.case20", kFullRandom, 1000000, 0},
  };

  RandomGenerator random({15485867, -104395303, 533000401});

  std::ofstream testplan("testplan");
  testplan << "sub1.case00 0\n";
  testplan << "sub2.case00 0\n";

  for (const auto& metadata : metadata_arr) {
    Testcase(metadata, random).ToFile("cases/" + metadata.filename + ".in");
    testplan << metadata.filename << ' ' << metadata.score << '\n';
  }
  testplan.close();
  return 0;
}
