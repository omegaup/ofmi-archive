import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea se proporcionan tres enteros $N$, $S$ y $T$.
        reg = re.compile(r"^(\d+) (\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected three integers")
        N, S, T = map(int, lines[0].split())

        # En la segunda línea se incluyen $N$ enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected N integers")
        A = list(map(int, lines[1].split()))
        self.assertTrue(len(A) == N, "Line 2: expected N integers")

        # Límites
        self.assertTrue(1 <= S <= N <= 10**5, "1 <= S <= N <= 10**5")
        self.assertTrue(all(0 <= Ai <= 1_000 for Ai in A), "Ai out of bounds")
        self.assertTrue(0 <= T <= N, "T out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(T == 0, "Sub1: T must be 0")
        elif "sub2" in caseName:
            self.assertTrue(T == N, "Sub2: T must be N")
            self.assertTrue(
                len(set(A)) == 1,
                "Sub2: All elements in A should be equal",
            )
        elif "sub3" in caseName:
            self.assertTrue(1 <= N <= 100, "Sub3: N out of bounds")
            self.assertTrue(T == N, "Sub3: T must be N")
        elif "sub4" in caseName:
            self.assertTrue(1 <= N <= 5000, "Sub4: N out of bounds")
            self.assertTrue(T == N, "Sub4: T must be N")
        elif "sub5" in caseName:
            self.assertTrue(T == N, "Sub5: T must be N")
        elif "sub6" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
