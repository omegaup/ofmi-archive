import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().strip().split("\n")

        # En la primera línea vendrá un entero $n$.
        self.assertTrue(re.match(r"^\d+$", lines[0]),
                        "Line 1: expected one integer")
        n = int(lines[0])

        # En la segunda línea vendrán $n$ enteros.
        self.assertTrue(re.match(f"^\\d+( \\d+){{{n - 1}}}$", lines[1]),
                        "Line 2: expected n integers")
        M = list(map(int, lines[1].split()))

        # Checks de límites generales.
        self.assertTrue(1 <= n <= 10**5, "1 <= n <= 10^5")
        self.assertTrue(all(1 <= Mi <= 10**9 for Mi in M), "1 <= Mi <= 10^9")
        self.assertLessEqual(sum(M), 10**9, "sum of Mi <= 10^9")

        # La subtarea 1 **NO** tiene sus casos agrupados.
        # Todas las demás subtareas tienen sus casos agrupados.
        caseName = sys.argv[1]
        if not re.match(r"^sub1", caseName):
            self.assertTrue(re.match(r"^sub\d+\.(\w|-)+$", caseName),
                            "Case must be grouped")

        # Checks de limites de cada subtarea.
        if re.match(r"^sub1", caseName):
            self.assertTrue(1 <= n <= 2, "Sub1: 1 <= n <= 2")
        elif re.match(r"^sub2", caseName):
            self.assertTrue(1 <= n <= 100, "Sub2: 1 <= n <= 100")
            self.assertLessEqual(sum(M), 10**4, "Sub2: sum of Mi <= 10^4")
        elif re.match(r"^sub3", caseName):
            self.assertTrue(1 <= n <= 1000, "Sub3: 1 <= n <= 1000")
        else:
            # Sin restricciones adicionales.
            self.assertTrue(re.match(r"^sub4", caseName),
                            f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
