import re
import sys
import heapq
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea dos enteros, n y q
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        n, q = map(int, lines[0].split())

        # Siguientes $q$ líneas
        self.assertTrue(len(lines) == q + 1, "Line 2+: expected q events")

        # Cada línea tiene exactamente un +/- seguido de un espacio y un entero
        reg = re.compile(r"^(\+|\-) (\d+)$")
        self.assertTrue(all(reg.match(line) for line in lines[1:]),
                        "Invalid event format \"+/- R_i\"")

        # Límites generales
        self.assertTrue(1 <= n <= 10**9, "1 <= n <= 10^9")
        self.assertTrue(2 <= q <= 2 * 10**5, "2 <= q <= 2 * 10^5")

        types = [line.split()[0] for line in lines[1:]]
        self.assertIn('-', types, "There should be at least one '-' event")

        R = [int(line.split()[1]) for line in lines[1:]]
        self.assertTrue(all(1 <= Ri <= n for Ri in R), "1 <= R_i <= n")

        collection = dict()
        for (event_type, R_i) in zip(types, R):
            if event_type == '+':
                collection[R_i] = collection.get(R_i, 0) + 1
            else:
                if R_i not in collection:
                    self.fail("Invalid '-' event without '+'")
                collection[R_i] -= 1
                if collection[R_i] == 0:
                    del collection[R_i]

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(1 <= n <= 100, "Sub1: 1 <= n <= 100")
        elif "sub2." in caseName:
            has_removed = False
            for (event_type, R_i) in zip(types, R):
                if event_type == '+' and has_removed:
                    self.fail("Sub2: '+' found after '-'")
                if event_type == '-':
                    has_removed = True

        elif "sub3." in caseName:
            missing = list(range(1, q + 1))
            for (event_type, R_i) in zip(types, R):
                if event_type == '+':
                    self.assertTrue(R_i == missing[0],
                                    "Sub3: Invalid '+' of non-minimum R_i")
                    heapq.heappop(missing)
                else:
                    heapq.heappush(missing, R_i)

        elif "sub4." in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
