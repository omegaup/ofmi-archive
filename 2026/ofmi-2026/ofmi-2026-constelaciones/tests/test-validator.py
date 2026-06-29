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
        self.assertEqual(len(lines), 2, "Expected exactly two lines of input")

        # En la primera línea vendrá un entero $n$
        reg_n = re.compile(r"^(\d+)$")
        self.assertTrue(reg_n.match(lines[0]), "Line 1: expected one integer")
        n = int(lines[0])
        self.assertTrue(1 <= n <= 100_000, "n out of bounds")

        reg_d = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg_d.match(lines[1]),
                        "Line 2: expected space separated integers")

        d = list(map(int, lines[1].split()))
        self.assertEqual(len(d), n, "Line 2: expected exactly n integers")

        # Límites globales
        self.assertTrue(all(0 <= d_i <= n - 1 for d_i in d),
                        "D_i out of bounds")
        self.assertTrue(sum(d) <= 500_000, "Sum of D_i out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(all(0 <= d_i <= 1 for d_i in d),
                            "Sub1: D_i out of bounds")
        elif "sub2" in caseName:
            self.assertTrue(all(0 <= d_i <= 2 for d_i in d),
                            "Sub2: D_i out of bounds")
        elif "sub3" in caseName:
            self.assertTrue(all(d_i == d[0] for d_i in d),
                            "Sub3: D_i must be equal")
        elif "sub4" in caseName:
            self.assertTrue(1 <= n <= 100, "Sub4: n out of bounds")
        elif "sub5" in caseName:
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")

        # Cada subtarea tiene todos sus casos agrupados.
        reg = re.compile(r"^\d+_sub(\d+)\.(\w+)$")
        self.assertTrue(reg.match(caseName), "Case must be grouped")


if __name__ == "__main__":
    validatortest.main()
