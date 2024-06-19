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

        # En la primera linea un entero N
        reg = re.compile(r"^[1-9][0-9]*$")
        self.assertTrue(reg.match(lines[0]), "line 1: expected integer N")

        # 1 <= N <= 10^5
        N = int(lines[0])
        self.assertTrue(1 <= N <= 10**5, "line 1: N out of range")

        # En las siguiente linea una permutation P de N enteros
        reg = re.compile(r"^[1-9][0-9]*( [1-9][0-9]*)*$")
        self.assertTrue(reg.match(lines[1]), "line 2: expected N integers")
        P = list(map(int, lines[1].split()))
        self.assertEqual(len(P), N, "line 2: expected N integers")

        # 1 <= P[i] <= N
        self.assertTrue(
            all(1 <= P[i] <= N for i in range(N)), "line 2: P[i] out of range"
        )
        self.assertEqual(len(P), len(set(P)), "line 2: P is not a permutation")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            # n <= 3
            self.assertTrue(N <= 3, "sub1: N out of range")
        elif "sub2" in caseName:
            # n <= 1000
            self.assertTrue(N <= 1000, "sub2: N out of range")
        elif "sub3" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
