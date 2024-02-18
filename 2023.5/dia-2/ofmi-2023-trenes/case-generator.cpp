#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// Subtasks limits
const int total_subtasks = 5;
int number_of_cases[total_subtasks + 1] = {
    0,
    10,  // 1
    10,  // 2
    10,  // 3
    10,  // 4
    10,  // 5
};
int n_limit[total_subtasks + 1] = {
    0,
    (int)2e5,  // 1
    (int)1e2,  // 2
    (int)1e2,  // 3
    (int)2e5,  // 4
    (int)2e5,  // 5
};
int k_limit[total_subtasks + 1] = {
    0,
    (int)1e9,  // 1
    (int)1e2,  // 2
    (int)1e3,  // 3
    (int)1e3,  // 4
    (int)1e9,  // 5
};
int t_limit[total_subtasks + 1] = {
    0,
    (int)1e9,  // 1
    (int)1e3,  // 2
    (int)1e6,  // 3
    (int)1e6,  // 4
    (int)1e9,  // 5
};
int q_limit[total_subtasks + 1] = {
    0,
    (int)1e5,  // 1
    (int)1e2,  // 2
    (int)1e3,  // 3
    (int)1e3,  // 4
    (int)1e5,  // 5
};
int order[total_subtasks + 1] = {
    0,
    4,  // 1
    1,  // 2
    2,  // 3
    3,  // 4
    5,  // 5
};
int subtask_points[total_subtasks + 1] = {
    0,
    10,  // 1
    15,  // 2
    18,  // 3
    17,  // 4
    40,  // 5
};

// Random generator
std::mt19937_64 rnd(
    std::chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
  long long x = (rnd() % (r - l + 1));
  return x + l;
}

int main() {
  /*
  Subtarea 1 (10 puntos):
    Solo habrá consultas de tipo 'a'.
  Subtarea 2 (15 puntos):
    N, K, Q <= 100
    T <= 1000
  Subtarea 3 (18 puntos):
    N <= 100
    K, Q <= 1000
    T <= 10^6
    T / K <= 1000
  Subtarea 4 (17 puntos):
    N <= 10^6
    K, Q <= 1000
    T <= 10^6
    T / K <= 1000
  Subtarea 5 (40 puntos):
    Sin restricciones adicionales
  */
  std::ofstream testplan("testplan", std::ifstream::in);
  testplan << "1-sub2.sample 0\n";
  std::ofstream input;

  // Number of subtask
  for (int subtask = 1; subtask <= total_subtasks; subtask++) {
    // Number of case
    for (int case_number = 1; case_number <= number_of_cases[subtask];
         case_number++) {
      std::string casename = "cases/" + std::to_string(order[subtask]) +
                             "-sub" + std::to_string(subtask) + "." +
                             std::to_string(case_number);
      // Open case file
      input.open(casename + ".in");

      int N, K;
      // Half of the cases have random size
      if (case_number < number_of_cases[subtask] / 2) {
        N = get_random(1, n_limit[subtask]);
      } else
        N = n_limit[subtask];  // Limit size

      std::vector<int> T(N, 1);
      if (subtask == 1 || subtask == 5) {
        for (int i = 0; i < N; i++) {
          T[i] = get_random(1, t_limit[subtask]);
        }
        K = get_random(1, k_limit[subtask]);
      } else {
        int total_sum;
        if (case_number < number_of_cases[subtask] / 2) {
          total_sum = get_random(N, t_limit[subtask]);
        } else {
          total_sum = t_limit[subtask];
        }
        for (int i = 0; i < total_sum - N; i++) {
          T[get_random(0, N - 1)]++;
        }

        if (subtask == 3 || subtask == 4) {
          int cota = (total_sum + 1000 - 1) / 1000;
          K = get_random(cota, k_limit[subtask]);
        } else {
          K = get_random(1, k_limit[subtask]);
        }
      }

      // Start printing case
      input << N << ' ' << K << '\n';
      for (int i = 0; i < N; i++) {
        input << T[i] << " \n"[i == N - 1];
      }

      // Number of queries
      int Q;
      if (case_number < number_of_cases[subtask] / 2) {
        Q = get_random(1, q_limit[subtask]);
      } else {
        Q = q_limit[subtask];
      }

      // Print number of queries
      input << Q << '\n';
      std::vector<std::tuple<char, int, char, int>> queries(Q);

      // Generate and print queries
      for (int i = 0; i < Q; i++) {
        char tipo, lado;
        int indice, minutos;
        tipo = "ab"[(subtask == 1 ? 0 : get_random(0, 1))];
        lado = "NS"[get_random(0, 1)];
        indice = get_random(1, N);
        if (tipo == 'a') {
          minutos = get_random(1, K);
        } else {
          minutos = get_random(0, K);
        }
        // Save queries
        queries[i] = {tipo, indice, lado, minutos};
        // Print queries
        input << tipo << ' ' << indice << ' ' << lado << ' ' << minutos << '\n';
      }
      input.close();

      // Edit testplan
      casename = casename.substr(6);
      testplan << casename;
      if (case_number == 1) {
        testplan << ' ' << subtask_points[subtask] << '\n';
      } else
        testplan << " 0\n";
    }
  }
  testplan.close();
  return 0;
}