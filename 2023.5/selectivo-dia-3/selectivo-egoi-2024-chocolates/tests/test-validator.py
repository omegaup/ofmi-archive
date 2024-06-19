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

        # En la primera línea tres enteros n, m y k
        reg = re.compile(r"^(\d+) (\d+) (\d+)$")
        self.assertTrue(
            reg.match(lines[0]),
            "Line 1 must contain three integers",
        )
        n, m, k = map(int, lines[0].split())

        # En la siguiente línea vendrán n enteros separados por espacios
        reg = re.compile(r"^(\d+ )*\d+$")
        self.assertTrue(reg.match(lines[1]), "Line 2 must contain n integers")
        A = list(map(int, lines[1].split()))
        self.assertEqual(len(A), n, "Line 2 must contain n integers")

        # $2 \leq n \leq 10^5$
        self.assertTrue(2 <= n <= 10**5, "n out of range")
        # $1 \leq m, k, m*k \leq n$
        self.assertTrue(1 <= m <= n, "m out of range")
        self.assertTrue(1 <= k <= n, "k out of range")
        self.assertTrue(1 <= m * k <= n, "m*k out of range")
        # $1 \leq A_i \leq 10^9$
        self.assertTrue(all(1 <= Ai <= 10**9 for Ai in A), "A_i out of range")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            # $n \leq 1000$, $m = 2$
            self.assertTrue(n <= 1000, "n out of range sub1")
            self.assertTrue(m == 2, "m must be 2 sub1")
        elif "sub2" in caseName:
            # $n \leq 1000$, $m = 3$
            self.assertTrue(n <= 1000, "n out of range sub2")
            self.assertTrue(m == 3, "m must be 3 sub2")
        elif "sub3" in caseName:
            # $n \leq 300$
            self.assertTrue(n <= 300, "n out of range sub3")
        elif "sub4" in caseName:
            # $k = 1$
            self.assertTrue(k == 1, "k must be 1 sub4")
        elif "sub5" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
