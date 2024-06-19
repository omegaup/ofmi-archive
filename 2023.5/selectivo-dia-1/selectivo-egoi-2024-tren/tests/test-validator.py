import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.strip().split("\n")
        self.assertEqual(len(lines), 2, "unexpected number of lines")

        # En la primera linea N y C
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(
            reg.match(lines[0]),
            "Line 1 must contain two integers",
        )
        N, C = map(int, lines[0].split())

        # En la linea 2, N enteros A_i separados por espacios
        reg = re.compile(r"^(\d+)( \d+)*$")
        A = list(map(int, lines[1].split()))
        self.assertTrue(
            reg.match(lines[1]) and
            len(A) == N,
            "Expected N integers in line 2"
        )

        # $1 <= N <= 10^5$
        self.assertTrue(1 <= N <= 10**5, "N out of range")
        # $1 <= C <= 10^9$
        self.assertTrue(1 <= C <= 10**9, "C out of range")
        # $0 <= A_i <= 10^9$
        self.assertTrue(all(0 <= Ai <= 10**9 for Ai in A), "A_i out of range")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            # $N = 1$
            self.assertEqual(N, 1, "N must be 1 sub1")
        elif "sub2" in caseName:
            # $N, C, A_i <= 1,000$
            self.assertLessEqual(N, 1000, "N must be <= 1000 sub2")
            self.assertLessEqual(C, 1000, "C must be <= 1000 sub2")
            self.assertTrue(all(Ai <= 1000 for Ai in A),
                            "A_i must be <= 1000 sub2")
        elif "sub3" in caseName:
            # $C = 1$
            self.assertEqual(C, 1, "C must be 1 sub3")
            # $A_i <= 1,000$
            self.assertTrue(all(Ai <= 1000 for Ai in A),
                            "A_i must be <= 1000 sub3")
        elif "sub4" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
