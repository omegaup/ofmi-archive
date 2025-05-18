import re
import sys
import unittest
from omegaup.validator import validatortest


def match_n_integers(line: str, n: int):
    int_reg = re.compile(r"^\d+$")

    integers = []
    for token in line.split():
        if not int_reg.match(token):
            return None
        integers.append(int(token))

    if len(integers) != n:
        return None
    return integers


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea dos enteros n y x
        self.assertTrue(re.match(r"^(\d+) (\d+)$", lines[0]),
                        "Line 1: expected two integers")
        n, x = map(int, lines[0].split())

        # 1 <= n <= 10**4
        self.assertTrue(1 <= n <= 10**4, "1 <= n <= 10**4")

        # 1 <= x <= 10**9
        self.assertTrue(1 <= x <= 10**9, "1 <= x, A_i <= 10**9")

        # En la segunda línea vendrán n enteros
        A = match_n_integers(lines[1], n)
        self.assertTrue(A, "Line 2: expected n integers")

        # 1 <= A_i <= 10**9
        self.assertTrue(all(1 <= Ai <= 10**9 for Ai in A), "1 <= A_i <= 10**9")
        self.assertEqual(len(A), len(set(A)), "A_i must be unique")

        # En la tercer línea vendrá el numero de llamadas que puedes hacer
        self.assertTrue(re.match(r"^(\d+)$", lines[2]),
                        "Line 3: expected one integer")
        k = int(lines[2])

        # A es una rotacion de sus elementos en orden ascendente
        s = A.index(min(A))
        self.assertEqual(A[s:] + A[:s], sorted(A),
                         "A must be a rotation of its sorted elements")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertEqual(k, 10000, "Sub1: k = 10000")
        elif "sub2." in caseName:
            self.assertEqual(k, 60, "Sub2: k = 60")
            self.assertEqual(A, sorted(A),
                             "Sub2: A must be sorted in increasing order")
        elif "sub3." in caseName:
            self.assertEqual(k, 60, "Sub3: k = 60")
        elif "sub4." in caseName:
            self.assertEqual(k, 16, "Sub4: k = 16")
        else:
            self.fail("Invalid subtask")


if __name__ == "__main__":
    validatortest.main()
