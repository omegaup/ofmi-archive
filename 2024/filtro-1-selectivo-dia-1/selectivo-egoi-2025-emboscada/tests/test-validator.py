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

        # En la primera línea, dos enteros n y k
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        n, k = map(int, lines[0].split())

        # Límites generales
        self.assertTrue(1 <= n <= 10**5, "1 <= n <= 10^5")
        self.assertTrue(0 <= k <= 10**9, "0 <= k <= 10^9")

        # En la segunda línea vendrán n enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected n integers")
        T = list(map(int, lines[1].split()))
        self.assertEqual(len(T), n, "Line 2: expected n integers")

        # Límites T_i
        self.assertTrue(all(1 <= Ti <= 10**9 for Ti in T), "1 <= Ti <= 10^9")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(1 <= n <= 100, "Sub1: 1 <= n <= 100")
            self.assertTrue(0 <= k <= 500, "Sub1: 0 <= k <= 500")
            self.assertTrue(all(1 <= Ti <= 100 for Ti in T),
                            "Sub1: 1 <= Ti <= 100")
        elif "sub2." in caseName:
            self.assertTrue(0 <= k <= n, "Sub2: 0 <= k <= n")
        elif "sub3." in caseName:
            self.assertTrue(0 <= k <= 5 * 10**5, "Sub3: 0 <= k <= 5 * 10^5")
        elif "sub4." in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
