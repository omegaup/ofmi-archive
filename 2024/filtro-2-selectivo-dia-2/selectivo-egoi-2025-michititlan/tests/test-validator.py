import re
import sys
import unittest
from omegaup.validator import validatortest


def match_integer_pair(line: str):
    int_reg = re.compile(r"^(-?\d+) (-?\d+)$")
    if not int_reg.fullmatch(line):
        return None
    return [int(token) for token in line.split()]


def validate_coordinates(X: int, Y: int):
    return -1000 <= X <= 1000 and -1000 <= Y <= 1000


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea, un entero
        reg = re.compile(r"^\d+$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected one integer")
        n = int(lines[0])

        # Límites generales
        self.assertTrue(1 <= n <= 2 * 10**4, "1 <= n <= 2 * 10**4")

        # En cada una de las siguientes n líneas, vendrá una pareja de enteros
        P = []
        lines.reverse()
        lines.pop()
        while len(lines) > 0:
            tup = match_integer_pair(lines[-1])
            if tup:
                P.append(tup)
            lines.pop()
        self.assertEqual(len(P), n, "expected n pairs of integers")

        # Límites X_i y Y_i
        self.assertTrue(
            all(validate_coordinates(X_i, Y_i) for X_i, Y_i in P),
            "-1000 <= Xi, Yi <= 1000"
        )

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertEqual(
                len({X_i for X_i, *_ in P}), 1,
                "Sub1: Xi = Xj for all 1 <= i < j <= N"
            )
        elif "sub2." in caseName:
            self.assertTrue(1 <= n <= 20, "Sub2: 1 <= n <= 20")
        elif "sub3." in caseName:
            self.assertTrue(1 <= n <= 200, "Sub3: 1 <= n <= 200")
        elif "sub4." in caseName:
            self.assertTrue(1 <= n <= 2000, "Sub4: 1 <= n <= 2000")
        elif "sub5." in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail("Invalid subtask")


if __name__ == "__main__":
    validatortest.main()
