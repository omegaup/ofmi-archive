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

        # En la primera línea dos enteros n y k
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(
            reg.match(lines[0]),
            "Line 1 must contain two integers",
        )
        n, k = map(int, lines[0].split())

        # $1 \leq n \leq 2*10^5$
        self.assertTrue(1 <= n <= 2 * 10**5, "n out of bounds")
        # $1 \leq k \leq n$
        self.assertTrue(1 <= k <= n, "k out of bounds")

        # En la siguiente línea n enteros $A_i$ separados por espacios
        reg = re.compile(r"^(\d+ )*\d+$")
        self.assertTrue(reg.match(lines[1]), "Line 2 must contain n integers")
        A = list(map(int, lines[1].split()))
        self.assertEqual(len(A), n, "Line 2 must contain n integers")

        # $1 \leq A_i \leq 10^9$
        self.assertTrue(all(1 <= Ai <= 10**9 for Ai in A), "A_i out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            # $A_i = A_j$ para todo $i, j$
            self.assertEqual(len(set(A)), 1, "Sub1: All A_i must be equal")
        elif "sub2" in caseName:
            # $n \leq 20$
            self.assertTrue(n <= 20, "Sub2: n out of bounds")
        elif "sub3" in caseName:
            # $k = 1$
            self.assertEqual(k, 1, "Sub3: k must be 1")
        elif "sub4" in caseName:
            # $k \leq 100$
            self.assertTrue(k <= 100, "Sub4: k out of bounds")
        elif "sub5" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
