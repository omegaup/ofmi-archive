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

        # En la primera línea dos enteros $t$ y $h$
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        t, h = map(int, lines[0].split())

        # En la segunda línea vendrán $t$ enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected t integers")
        H = list(map(int, lines[1].split()))
        self.assertTrue(len(H) == t, "Line 2: expected t integers")

        # En la tercera línea vendrán $h$ enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[2]), "Line 3: expected h integers")
        P = list(map(int, lines[2].split()))
        self.assertTrue(len(P) == h, "Line 3: expected h integers")

        # Límites
        self.assertTrue(1 <= t <= 10**5, "t out of bounds")
        self.assertTrue(1 <= h <= 10**5, "h out of bounds")
        self.assertTrue(all(1 <= hi <= h for hi in H), "H_i out of bounds")
        self.assertTrue(all(1 <= pj <= 1_000 for pj in P), "P_j out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(all(pj == 1 for pj in P), "Sub1: P_j must be 1")
        elif "sub2" in caseName:
            self.assertTrue(t == 1, "Sub2: t must be 1")
        elif "sub3" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
