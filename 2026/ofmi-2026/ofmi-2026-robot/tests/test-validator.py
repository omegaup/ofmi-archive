import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().strip().split("\n")

        # En la primera línea vendrá un enteros $n$.
        self.assertTrue(re.match(r"^\d+$", lines[0]),
                        "Line 1: expected one integer")
        n = int(lines[0])

        # En la segunda línea vendrá una cadena de $n$ caracteres ^v<>.
        self.assertTrue(re.match(r"^(\^|v|<|>)+$", lines[1]),
                        "Line 2: expected commands string")
        commands = lines[1]

        # Checks de límites generales.
        self.assertEqual(n, len(commands),
                         "n is different than commands length")
        self.assertTrue(1 <= n <= 10**6, "1 <= n <= 10^6")

        caseName = sys.argv[1]
        self.assertTrue(re.match(r"^sub[1-3]_", caseName),
                        f"Invalid subtask {caseName}")

        if re.match(r"^sub1_", caseName):
            self.assertEqual(n, 1, "Sub1: n must be 1")
        elif re.match(r"^sub2_", caseName):
            self.assertEqual(len(set(commands)), 1,
                             "Sub2: only one unique instruction type")
        elif re.match(r"^sub3_", caseName):
            pass


if __name__ == "__main__":
    validatortest.main()
