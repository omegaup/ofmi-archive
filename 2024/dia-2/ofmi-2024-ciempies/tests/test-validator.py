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

        # En la primera línea un entero $n$.
        reg = re.compile(r"^(\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected one integer")
        N = int(lines[0])

        # En la segunda línea se incluyen $n$ enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected n integers")
        A = list(map(int, lines[1].split()))
        self.assertTrue(len(A) == N, "Line 2: expected n integers")

        # Límites
        self.assertTrue(1 <= N <= 2*10**5, "1 <= n <= 2*10**5")
        self.assertTrue(all(1 <= Ai <= 10**9 for Ai in A), "Ai out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(all(Ai % 2 == 0 for Ai in A),
                            "Sub1: Ai is not even")
            self.assertTrue(1 <= N <= 1_000, "Sub1: n out of bounds")
            self.assertTrue(all(1 <= Ai <= 1_000 for Ai in A),
                            "Sub1: Ai out of bounds")
        elif "sub2" in caseName:
            self.assertTrue(all(A[i] <= A[i + 1] for i in range(N - 1)),
                            "Sub2: Ai > Aj")
            self.assertTrue(1 <= N <= 1_000, "Sub2: n out of bounds")
            self.assertTrue(all(1 <= Ai <= 1_000 for Ai in A),
                            "Sub2: Ai out of bounds")
        elif "sub3" in caseName:
            self.assertTrue(1 <= N <= 1_000, "Sub3: n out of bounds")
            self.assertTrue(all(1 <= Ai <= 1_000 for Ai in A),
                            "Sub3: Ai out of bounds")
        elif "sub4" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
