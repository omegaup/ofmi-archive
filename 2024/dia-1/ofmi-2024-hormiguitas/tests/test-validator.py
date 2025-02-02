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

        # En la primera línea tres enteros $n$, $m$, y $q$
        reg = re.compile(r"^(\d+) (\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected three integers")
        n, m, q = map(int, lines[0].split())

        self.assertTrue(1 <= n <= 10**6, "n out of bounds")
        self.assertTrue(1 <= m <= 10**6, "m out of bounds")
        self.assertTrue(1 <= q <= 2 * 10**5, "q out of bounds")

        # En las siguientes q líneas vendrán 2 enteros
        raw_expeditions = lines[1:]
        self.assertTrue(len(raw_expeditions) == q, "must be q expeditions")

        expeditions = []
        reg = re.compile(r"^(\d+) (\d+)$")
        for raw_expedition in raw_expeditions:
            self.assertTrue(
                reg.match(raw_expedition),
                "Line 2 to q+1: expected 2 integers",
            )
            expeditions.append(list(map(int, raw_expedition.split())))

        u_i, v_i = map(list, zip(*expeditions))

        self.assertTrue(all(1 <= ui <= n for ui in u_i), "u_i out of bounds")
        self.assertTrue(all(1 <= vi <= m for vi in v_i), "v_j out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(q <= 2000, "Sub1: 1 <= q <= 2000")
        elif "sub2" in caseName:
            original_u = list(u_i)
            u_i.sort()
            self.assertTrue(original_u == u_i, "Sub2: u_i < u_j")
        elif "sub3" in caseName:
            self.assertTrue(m == 2, "Sub3: m must be 2")
        elif "sub4" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")

        # Cada subtarea tiene todos sus casos agrupados.
        reg = re.compile(r"^(\d+)_sub(\d+)\.(\w+)$")
        self.assertTrue(reg.match(caseName), "case must be grouped")


if __name__ == "__main__":
    validatortest.main()
