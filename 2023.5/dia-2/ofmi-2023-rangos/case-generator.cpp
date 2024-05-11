#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

// Subtasks limits
const int total_subtasks = 6;
int number_of_cases[total_subtasks + 1] = {
    0,
    10,  // 1
    10,  // 2
    15,  // 3
    20,  // 4
    15,  // 5
    15,  // 6
};
int n_limit[total_subtasks + 1] = {
    0,
    8,         // 1
    (int)1e3,  // 2
    (int)1e5,  // 3
    (int)1e3,  // 4
    (int)1e5,  // 5
    (int)1e5   // 6
};
int p_limit[total_subtasks + 1] = {
    0,
    (int)1e6,  // 1
    (int)1e9,  // 2
    (int)1e9,  // 3
    (int)1e9,  // 4
    (int)1e6,  // 5
    (int)1e9   // 6
};
int subtask_points[total_subtasks + 1] = {
    0,
    8,   // 1
    10,  // 2
    10,  // 3
    37,  // 4
    15,  // 5
    20   // 6
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
  Subtarea 1 (8 puntos)
      1 <= N <= 8
      1 <= L_i, R_i, P_i <= 1e6
  Subtarea 2 (10 puntos)
      1 <= N <= 1e3
      y se te asegura que los rangos
      no se intersecan entre ellos.
  Subtarea 3 (10 puntos)
      Todos los rangos son del mismo tamaño.
  Subtarea 4 (37 puntos)
      1 <= N <= 1e3
  Subtarea 5 (15 puntos)
      1 <= L_i, R_i, P_i <= 1e6
  Subtarea 6 (20 puntos)
      Sin consideraciones adicionales.
  */
  std::ofstream testplan("testplan", std::ifstream::in);
  testplan << "sub1.sample 0\n";
  std::ofstream input;

  // Number of subtask
  for (int subtask = 1; subtask <= total_subtasks; subtask++) {
    /*
    En visto de que hacer casos a lo random no da
    muchos casos con solucion, haremos que al menos
    la mitad de los casos si tengan solucion
    */
    std::vector<int> solution_case(number_of_cases[subtask]);
    std::iota(solution_case.begin(), solution_case.end(), 1);
    std::shuffle(solution_case.begin(), solution_case.end(), rnd);
    std::set<int> cws;  // cases with solution
    for (int i = 0; i <= number_of_cases[subtask] / 2; i++) {
      cws.insert(solution_case[i]);
    }

    // Number of case
    for (int case_number = 1; case_number <= number_of_cases[subtask];
         case_number++) {
      std::string casename = "cases/sub" + std::to_string(subtask) + "." +
                             std::to_string(case_number);
      // Open case file
      input.open(casename + ".in");

      int N;
      // Half of the cases have random size
      if (case_number > number_of_cases[subtask] / 2) {
        N = get_random(1, n_limit[subtask]);
      } else
        N = n_limit[subtask];  // Limit size

      std::vector<int> P(N), L(N), R(N);
      // Generate ranges
      if (subtask == 2) {
        // Los rangos no se pueden intersectar
        std::vector<int> values(2 * N);
        // Genera 2N numeros random distintos
        std::set<int> nums;
        for (int i = 0; i < 2 * N; i++) {
          values[i] = get_random(1, p_limit[subtask]);
          while (nums.count(values[i])) {
            values[i] = get_random(1, p_limit[subtask]);
          }
          nums.insert(values[i]);
        }
        // Los ordena y crea un rango con cada
        // pareja de numeros que estan juntos
        // asegurando asi que no se intersecten
        std::sort(values.begin(), values.end());
        std::vector<std::pair<int, int>> ranges(N);
        for (int i = 0; i < N; i++) {
          ranges[i] = {values[2 * i], values[2 * i + 1]};
        }
        // Se randomiza el orden en el que aparecen
        std::shuffle(ranges.begin(), ranges.end(), rnd);
        for (int i = 0; i < N; i++) {
          L[i] = ranges[i].first;
          R[i] = ranges[i].second;
        }
      } else if (subtask == 3) {
        // Los rangos tienen que ser del mismo tamaño

        // Obtener la longitud
        int length = get_random(1, p_limit[subtask] / (get_random(1, N)));
        for (int i = 0; i < N; i++) {
          // Generar L tal que L + length - 1
          // no se salga del limite
          L[i] = get_random(1, p_limit[subtask] - length + 1);
          R[i] = L[i] + length - 1;
        }
      } else {
        for (int i = 0; i < N; i++) {
          // Asigna valores random a los rangos
          L[i] = get_random(1, p_limit[subtask]);
          R[i] = get_random(1, p_limit[subtask]);
          // Se asegura de que L < R
          if (L[i] > R[i]) std::swap(L[i], R[i]);
        }
      }
      // Genera los puntos
      if (cws.count(case_number)) {
        // Entonces haremos que tenga solucion
        for (int i = 0; i < N; i++) {
          // Escogemos un punto al azar dentro del rango
          P[i] = get_random(L[i], R[i]);
        }
        // Randomizamos el orden
        std::shuffle(P.begin(), P.end(), rnd);
      } else {
        for (int i = 0; i < N; i++) {
          P[i] = get_random(1, p_limit[subtask]);
        }
      }

      input << N << '\n';
      input << P[0];
      for (int i = 1; i < N; i++) {
        input << ' ' << P[i];
      }
      input << '\n';
      for (int i = 0; i < N; i++) {
        input << L[i] << ' ' << R[i] << '\n';
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