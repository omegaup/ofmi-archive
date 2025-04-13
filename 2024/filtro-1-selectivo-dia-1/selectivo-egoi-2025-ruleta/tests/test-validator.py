import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea contiene dos enteros, n y k
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        n, k = map(int, lines[0].split())

        # En la segunda línea se incluye una cadena de n caracteres
        reg = re.compile(r"^[PS]+$")
        self.assertTrue(len(lines) == 2 and reg.match(lines[1]),
                        "Line 2: expected string with only P and S characters")
        self.assertEqual(len(lines[1]), n, "Line 2: string length should be n")

        # Límites generales
        self.assertTrue(1 <= k <= n <= 10**6, "1 <= k <= n <= 10^6")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(1 <= n <= 1000, "Sub1: 1 <= n <= 1000")
        elif "sub2." in caseName:
            self.assertTrue(k == 1, "Sub2: k must be 1")
        elif "sub3." in caseName:
            self.assertTrue(k == 2, "Sub3: k must be 2")
        elif "sub4." in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
