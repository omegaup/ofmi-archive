#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <vector>

struct Testcase {
  std::string casename;
  int N, M;
  std::vector<std::string> mat;
  void print() {
    std::ofstream input;
    input.open("cases/" + casename + ".in");
    input << N << ' ' << M << '\n';
    for (int i = 0; i < N; i++) {
      input << mat[i] << '\n';
    }
    input.close();
  }
};

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
};
RandomGen rnd({3395664128, 3526578366, 1616605031, 2832984428});

std::vector<std::string> generateMatrix(int N, int M) {
  std::vector<std::string> mat(N, std::string(N, 'X'));
  std::string str = "11X";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      mat[i][j] = str[rnd.Int(0, 2)];
    }
  }
  return mat;
}

std::vector<std::string> generateXMatrix(int N, int M) {
  std::vector<std::string> mat(N, std::string(N, 'X'));
  return mat;
}

int main() {
  int N = 300, M = 300;
  Testcase t1 = {"sub2_2.3", N, M, generateMatrix(N, M)};
  Testcase t2 = {"sub2_2.4", N, M, generateMatrix(N, M)};
  Testcase t3 = {"sub2_2.5", N, M, generateMatrix(N, M)};
  Testcase t4 = {"sub2_2.6", N, M, generateMatrix(N, M)};
  Testcase t5 = {"sub2_2.7", N, M, generateMatrix(N, M)};
  Testcase t6 = {"sub2_2.8", N, M, generateMatrix(N, M)};
  Testcase t7 = {"sub2_2.9", N, M, generateMatrix(N, M)};
  Testcase t8 = {"sub2_2.10", N, M, generateXMatrix(N, M)};
  Testcase t9 = {"sub2_2.15", N, M, generateXMatrix(N, M)};
  Testcase t10 = {"sub2_2.16", N, M, generateXMatrix(N, M)};
  Testcase t11 = {"sub2_2.17", N, M, generateXMatrix(N, M)};
  Testcase t12 = {"sub2_2.18", N, M, generateXMatrix(N, M)};

  int x1, y1, x2, y2, x3, y3;
  // first case
  x1 = rnd.Int(0, N - 2);
  y1 = rnd.Int(0, M - 1);
  x2 = x1 + 1;
  y2 = y1;
  do {
    x3 = rnd.Int(0, N - 1);
    y3 = rnd.Int(0, M - 1);
  } while ((x3 == x1 && y3 == y1) || (x3 == x2 && y3 == y2));
  t1.mat[x1][y1] = t1.mat[x2][y2] = t1.mat[x3][y3] = '0';
  t1.print();

  // second case
  x1 = rnd.Int(0, N - 1);
  y1 = rnd.Int(0, M - 2);
  x2 = x1;
  y2 = y1 + 1;
  do {
    x3 = rnd.Int(0, N - 1);
    y3 = rnd.Int(0, M - 1);
  } while ((x3 == x1 && y3 == y1) || (x3 == x2 && y3 == y2));
  t2.mat[x1][y1] = t2.mat[x2][y2] = t2.mat[x3][y3] = '0';
  t2.print();

  // third case
  x1 = rnd.Int(0, N - 2);
  y1 = rnd.Int(0, M - 2);
  x2 = x1 + 1;
  y2 = y1;
  x3 = x1;
  y3 = y1 + 1;
  t3.mat[x1][y1] = t3.mat[x2][y2] = t3.mat[x3][y3] = '0';
  t3.print();

  // cuarto caso
  x1 = rnd.Int(0, N - 3);
  y1 = rnd.Int(0, M - 1);
  x2 = x1 + 1;
  y2 = y1;
  x3 = x1 + 2;
  y3 = y1;
  t4.mat[x1][y1] = t4.mat[x2][y2] = t4.mat[x3][y3] = '0';
  t4.print();

  // quinto caso
  x1 = rnd.Int(0, N - 1);
  y1 = rnd.Int(0, M - 3);
  x2 = x1;
  y2 = y1 + 1;
  x3 = x1;
  y3 = y1 + 2;
  t5.mat[x1][y1] = t5.mat[x2][y2] = t5.mat[x3][y3] = '0';
  t5.print();

  // sexto caso
  x1 = rnd.Int(0, N - 2);
  y1 = rnd.Int(0, M - 2);
  x2 = x1 + 1;
  y2 = y1 + 1;
  do {
    x3 = rnd.Int(0, N - 1);
    y3 = rnd.Int(0, M - 1);
  } while ((x3 == x1 && y3 == y1) || (x3 == x2 && y3 == y2));
  t6.mat[x1][y1] = t6.mat[x2][y2] = t6.mat[x3][y3] = '0';
  t6.print();

  // septimo caso
  x1 = rnd.Int(1, N - 1);
  y1 = rnd.Int(0, M - 2);
  x2 = x1 - 1;
  y2 = y1 + 1;
  do {
    x3 = rnd.Int(0, N - 1);
    y3 = rnd.Int(0, M - 1);
  } while ((x3 == x1 && y3 == y1) || (x3 == x2 && y3 == y2));
  t7.mat[x1][y1] = t7.mat[x2][y2] = t7.mat[x3][y3] = '0';
  t7.print();

  // octavo caso
  x1 = rnd.Int(0, N - 1);
  y1 = rnd.Int(0, M - 1);
  do {
    x2 = rnd.Int(0, N - 1);
    y2 = rnd.Int(0, M - 1);
  } while (x2 == x1 && y2 == y1);
  do {
    x3 = rnd.Int(0, N - 1);
    y3 = rnd.Int(0, M - 1);
  } while ((x3 == x1 && y3 == y1) || (x3 == x2 && y3 == y2));
  t8.mat[x1][y1] = t8.mat[x2][y2] = t8.mat[x3][y3] = '0';
  t8.print();

  int x4, y4;

  // noveno caso
  x1 = 0;
  y1 = 0;
  x2 = (N / 2);
  y2 = M - 1;
  x3 = N - 1;
  y3 = 0;
  x4 = (N / 2);
  y4 = 0;
  t9.mat[x1][y1] = t9.mat[x2][y2] = t9.mat[x3][y3] = '0';
  t9.mat[x4][y4] = '1';
  t9.print();

  // decimo caso
  x1 = 0;
  y1 = 0;
  x2 = (N / 2) - 1;
  y2 = M - 1;
  x3 = N - 1;
  y3 = 0;
  x4 = (N / 2);
  y4 = 0;
  t10.mat[x1][y1] = t10.mat[x2][y2] = t10.mat[x3][y3] = '0';
  t10.mat[x4][y4] = '1';
  t10.print();

  // onceavo caso
  x1 = 0;
  y1 = M - 1;
  x2 = N - 1;
  y2 = (M / 2);
  x3 = 0;
  y3 = 0;
  x4 = 0;
  y4 = (M / 2);
  t11.mat[x1][y1] = t11.mat[x2][y2] = t11.mat[x3][y3] = '0';
  t11.mat[x4][y4] = '1';
  t11.print();

  // doceavo caso
  x1 = 0;
  y1 = M - 1;
  x2 = N - 1;
  y2 = (M / 2) - 1;
  x3 = 0;
  y3 = 0;
  x4 = 0;
  y4 = (M / 2);
  t12.mat[x1][y1] = t12.mat[x2][y2] = t12.mat[x3][y3] = '0';
  t12.mat[x4][y4] = '1';
  t12.print();
  return 0;
}