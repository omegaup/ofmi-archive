import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().strip().split("\n")

        # En la primera línea vendrán cuatro enteros $a$, $b$, $c$ y $d$.
        self.assertTrue(re.match(r"^\d+ \d+ \d+ \d+$", lines[0]),
                        "Line 1: expected four integers")
        (a, b, c, d) = list(map(int, lines[0].split()))

        # Checks de límites generales.
        self.assertTrue(0 <= a <= 100, "0 <= a <= 100")
        self.assertTrue(0 <= b <= 100, "0 <= b <= 100")
        self.assertTrue(0 <= c <= 100, "0 <= c <= 100")
        self.assertTrue(0 <= d <= 100, "0 <= d <= 100")

        # Sin restricciones adicionales.
        caseName = sys.argv[1]
        self.assertTrue(re.match(r"^sub1_", caseName),
                        f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
