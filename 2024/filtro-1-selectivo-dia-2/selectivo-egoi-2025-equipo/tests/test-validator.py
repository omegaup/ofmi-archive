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

        # En la primera línea, dos enteros n y k
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        n, k = map(int, lines[0].split())

        # Límites generales
        self.assertTrue(1 <= n <= 2 * 10**6, "1 <= n <= 2 * 10**6")
        self.assertTrue(1 <= k <= 10**9, "1 <= k <= 10**9")

        # En la segunda línea vendrán n enteros
        P = match_n_integers(lines[1], n)
        self.assertTrue(P, "Line 2: expected n integers")

        # Límites P_i
        self.assertTrue(all(1 <= Pi <= 10**9 for Pi in P), "1 <= Pi <= 10**9")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(1 <= n <= 200, "Sub1: 1 <= n <= 200")
        elif "sub2." in caseName:
            self.assertTrue(1 <= n <= 2000, "Sub2: 1 <= n <= 2000")
        elif "sub3." in caseName:
            self.assertTrue(all(P[i - 1] <= P[i] for i in range(1, n)),
                            "Sub3: P must be sorted in non-decreasing order")
        elif "sub4." in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
