import re
import sys
import unittest
from collections import Counter
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea dos enteros $n$ y $m$
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        n, m = map(int, lines[0].split())

        # En cada una de las siguientes $n$ líneas vendrán
        # $m$ enteros separados por espacios
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            all(reg.match(line) for line in lines[1:]), "Expected n*m integers"
        )
        C = list(list(map(int, line.split())) for line in lines[1:])
        self.assertTrue(len(C) == n, "Invalid matrix: expected n rows")
        self.assertTrue(
            all(len(Ci) == m for Ci in C), "Invalid matrix: expected m rows"
        )

        # Límites
        self.assertTrue(1 <= n <= 1_000, "n out of bounds")
        self.assertTrue(1 <= m <= 1_000, "m out of bounds")
        self.assertTrue(
            all(all(1 <= Cij <= 10**6 for Cij in Ci) for Ci in C),
            "Cij out of bounds",
        )

        freq = Counter(sum(C, []))

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(
                all(f <= 2 for f in freq.values()),
                "Sub1: No color should appear more than twice",
            )
            self.assertTrue(1 <= n <= 10, "Sub1: n out of bounds")
            self.assertTrue(1 <= m <= 10, "Sub1: m out of bounds")
        elif "sub2" in caseName:
            self.assertTrue(
                all(freq[color] < freq[1] for color in freq if color != 1),
                "Sub2: color 1 should be the most frequent",
            )
        elif "sub3" in caseName:
            self.assertTrue(n == 1, "Sub3: n must be 1")
        elif "sub4" in caseName:
            # Sin restricciones adicionales.
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")

        # Cada subtarea tiene todos sus casos agrupados.
        reg = re.compile(r"^sub(\d+)\.(\w+)$")
        self.assertTrue(reg.match(caseName), "Case must be grouped")


if __name__ == "__main__":
    validatortest.main()
