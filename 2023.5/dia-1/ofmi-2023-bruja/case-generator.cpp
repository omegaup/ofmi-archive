#include <time.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

/// Numeros aleatorios bit por bit
long long ale(long long a, long long b) {
  long long f = 0;
  for (long long i = 1, con = 0; con < 63; i *= 2, con++)
    f += (rand() % 2) ? i : 0;
  return f % (b - a + 1) + a;
}

/// Solucion 100A
int solve_100A(int n, int nums[]) {
  std::set<int> diferentes;
  for (int i = 0; i < n; ++i) diferentes.insert(nums[i]);
  return diferentes.size();
}

int main() {
  srand(time(NULL));
  /**
      Testplan por caso:
      - subtarea 1: 3 puntos.
      - subtarea 2: 2 puntos.
      - subtarea 3: 2 puntos.
      - subtarea 4: 3 puntos.
  */
  std::ofstream testplan("testplan");
  testplan << "sample-sub1 0\nsample2-sub2 0\nsample3-sub3 0\n";
  std::ofstream input, output;

  /// Generamos 40 casos mas. Los casos de ejemplo no les asignaremos puntos.
  for (int case_number = 1; case_number <= 40; ++case_number) {
    std::cerr << "Generando caso " << case_number << "\n";

    int subtask;
    if (case_number <= 5)
      subtask = 1;
    else if (case_number <= 15)
      subtask = 2;
    else if (case_number <= 25)
      subtask = 3;
    else
      subtask = 4;

    std::string case_name = "cases/sub" + std::to_string(subtask) + "-" +
                            std::to_string(case_number);
    input.open(case_name + ".in");
    output.open(case_name + ".out");

    /// Fijamos algunos tamanios y generamos el resto aleatoriamente
    int n;
    if (case_number <= 2)
      n = case_number;
    else if (case_number <= 6)
      n = 1e2;  /// subtarea 2
    else if (case_number <= 8)
      n = 1e3;  /// subtarea 2
    else if (case_number <= 15)
      n = 1e4;  /// subtarea 3
    else if (case_number <= 24)
      n = 1e5;  /// subtarea 4
    else
      n = ale(1, 2e5);  /// cualquier subtarea

    /// Genera los numeros f_i dependiendo de las subtareas
    int nums[n];
    for (int i = 0; i < n; ++i) {
      if (subtask == 1)
        nums[i] = ale(0, 10);
      else if (subtask == 2)
        nums[i] = ale(0, 1e3);
      else if (subtask == 3)
        nums[i] = ale(-1e4, 1e4);
      else
        nums[i] = ale(-1e9, 1e9);
    }
    // Forzando que falle la subtarea 1
    if (n >= 100 && subtask != 1) {
      nums[n - 1] = nums[0];
      nums[n - 2] = nums[1];
    }

    /// Para la subtarea 1 todos los f_i iguales deben
    /// estar consecutivos y en el rango -10^9 <= f_i <= 10^9
    if (subtask == 1) {
      /// Ponemos todos los numeros iguales juntos
      std::sort(nums, nums + n);

      /// sumamos el valor add a cada bloque de numeros
      /// iguales. De esta manera tenemos -10^9 <= f_i <= 10^9
      int add = ale(-1e8, 1e8);    /// add cambia en cada bloque
      std::set<int> previous_add;  /// Para no repetir valores de add
      nums[0] += add;
      for (int i = 1; i < n; ++i) {
        while (nums[i] + add != nums[i - 1] && previous_add.count(add))
          add = ale(-1e8, 1e8);  /// Cambiamos de bloque
        previous_add.insert(add);
        nums[i] += add;
      }
    }

    /// Imprimimos los casos en los archivos

    /// input
    input << n << '\n' << nums[0];
    for (int i = 1; i < n; ++i) input << ' ' << nums[i];
    input << '\n';

    /// output
    output << solve_100A(n, nums) << '\n';

    /// testplan
    case_name = case_name.substr(6);
    testplan << case_name << ' ';
    if (subtask == 1)
      testplan << "3\n";
    else if (subtask == 2)
      testplan << "2\n";
    else if (subtask == 3)
      testplan << "2\n";
    else
      testplan << "3\n";

    input.close();
    output.close();
  }
}
