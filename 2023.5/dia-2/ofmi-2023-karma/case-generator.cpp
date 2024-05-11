#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

// Subtasks limits
const int total_subtasks = 5;
int number_of_cases[total_subtasks + 1] = {
    // La cantidad de casos por subtarea tiene que ser par
    0,
    10,  // 1
    10,  // 2
    10,  // 3
    10,  // 4
    16,  // 5
};
int n_limit[total_subtasks + 1] = {
    0,
    (int)3e5,  // 1
    (int)1e3,  // 2
    (int)3e5,  // 3
    (int)3e5,  // 4
    (int)3e5,  // 5
};
int k_LLimit[total_subtasks + 1] = {
    0,
    (int)-(1e9),  // 1
    (int)-(1e9),  // 2
    0,            // 3
    -100,         // 4
    (int)-(1e9),  // 5
};
int k_RLimit[total_subtasks + 1] = {
    0,
    (int)1e9,  // 1
    (int)1e9,  // 2
    1,         // 3
    100,       // 4
    (int)1e9,  // 5
};
int subtask_points[total_subtasks + 1] = {
    0,
    10,  // 1
    20,  // 2
    10,  // 3
    20,  // 4
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
      M = 1 (Jessie y Tiro al Blanco siempre serán el primer equipo en la fila)
  Subtarea 2 (20 puntos):
      1 <= N <= 1000
  Subtarea 3 (10 puntos):
      0 <= k_i <= 1 ((La dificultad de las rutinas es 0 o 1)
  Subtarea 4 (20 puntos):
      -100 <= k_i <= 100$ ((La dificultad de las rutinas está entre -100 y 100)
  Subtarea 5 (40 puntos):
      Sin restricciones adicionales
  */

  std::ofstream testplan("testplan", std::ifstream::in);
  std::vector<std::string> sample_cases(3);
  sample_cases[0] = "sample-sub1";
  sample_cases[1] = "sample2-sub5";
  sample_cases[2] = "sample3-sub4";
  for (auto sample_case_name : sample_cases)
    testplan << sample_case_name << " 0\n";
  std::ofstream input;

  // Number of subtask
  for (int subtask = 1; subtask <= total_subtasks; subtask++) {
    // Number of case
    for (int case_number = 1; case_number <= number_of_cases[subtask];
         case_number++) {
      std::string case_name = "cases/sub" + std::to_string(subtask) + "_" +
                              std::to_string(case_number + (case_number % 2)) +
                              "." + std::to_string(case_number);
      // Open case file
      input.open(case_name + ".in");

      int N, M;
      // Half of the cases have random size (kinda)
      if (case_number <= number_of_cases[subtask] / 2) {
        if (subtask == 2) {
          N = get_random(1, n_limit[subtask]);
        } else {
          N = get_random(n_limit[subtask] >> 1, n_limit[subtask]);
        }
      } else
        N = n_limit[subtask];  // Limit size

      std::vector<int> K(N);
      // Generate array
      if (subtask == 1) {
        // En la sutarea 1 se tiene que M = 1
        if (case_number & 1) {
          for (int i = 0; i < N; i++) {
            K[i] = get_random(k_LLimit[subtask], k_RLimit[subtask]);
          }
          // Nos aseguramos que al menos uno sea mayor a 0
          K[get_random(0, N - 1)] = get_random(1, k_RLimit[subtask]);
        } else {
          // Todos son menores o iguales a 0
          for (int i = 0; i < N; i++) {
            K[i] = get_random(k_LLimit[subtask], 0);
          }
        }
        M = 1;
      } else {
        // Asignamos numeros random dentro de los limites
        for (int i = 0; i < N; i++) {
          K[i] = get_random(k_LLimit[subtask], k_RLimit[subtask]);
        }
        // En la mitad de los casos si se podra y en la otra mitad
        // no, asi que contamos cuantos menores o iguales a 0 para poder
        // asignarle un valor a M de tal manera que se cumpla lo que
        // queremos
        int cnt = 0;
        for (int i = 0; i < N; i++) {
          cnt += (K[i] > 0);
        }
        while (cnt == 0 || cnt == N) {
          cnt = 0;
          for (int i = 0; i < N; i++) {
            K[i] = get_random(k_LLimit[subtask], k_RLimit[subtask]);
            cnt += (K[i] > 0);
          }
        }
        if (case_number & 1) {
          // Caso impar si tiene solucion
          M = get_random(1, cnt);
        } else {
          // Caso par no tiene solucion
          M = get_random(cnt + 1, N);
        }
      }

      // Print case
      input << N << ' ' << M << '\n';
      input << K[0];
      for (int i = 1; i < N; i++) {
        input << ' ' << K[i];
      }
      input << '\n';
      input.close();

      // Edit testplan
      case_name = case_name.substr(6);
      testplan << case_name << ' ';
      if (case_number & 1) {
        double points =
            (double)subtask_points[subtask] / (double)number_of_cases[subtask];
        testplan << 2 * points << '\n';
      } else {
        testplan << "0\n";
      }
    }
  }
  testplan.close();
  return 0;
}