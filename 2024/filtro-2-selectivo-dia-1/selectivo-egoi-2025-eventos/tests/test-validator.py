import re
import sys
import unittest
from typing import List
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def match_n_events(self, lines: List[str], n: int):
        tuple_reg = re.compile(r"^(\d+) (\d+) (\d+)$")

        events = []
        for line in lines:
            self.assertTrue(tuple_reg.match(line),
                            "Line 2+: expected three integers")
            events.append(list(map(int, line.split())))

        if len(events) != n:
            return None
        return events

    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea un entero n
        reg = re.compile(r"^(\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected one integer")
        n = int(lines[0])

        # Límites generales
        self.assertTrue(1 <= n <= 10**5, "1 <= n <= 10**5")

        # En las siguientes n líneas vendrán tres enteros S_i, E_i y V_i
        events = self.match_n_events(lines[1:], n)
        self.assertTrue(events, "Line 2+: expected n events")

        # 0 <= S_i < E_i <= 10**9
        self.assertTrue(all(0 <= Si < Ei <= 10**9 for Si, Ei, *_ in events),
                        "0 <= S_i < E_i <= 10**9")

        # 0 <= V_i <= 100
        self.assertTrue(all(0 <= Vi <= 100 for *_, Vi in events),
                        "0 <= V_i <= 100")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(1 <= n <= 15, "Sub1: 1 <= n <= 15")
        elif "sub2." in caseName:
            self.assertTrue(
                all(events[i - 1][2] == events[i][2] for i in range(1, n)),
                "Sub2: all Vi should be the same")
        elif "sub3." in caseName:
            self.assertTrue(
                all(0 <= Si < Ei <= 10**6 for Si, Ei, *_ in events),
                "Sub3: 0 <= S_i < E_i <= 10**6")
        elif "sub4." in caseName:
            self.assertTrue(1 <= n <= 1000, "Sub4: 1 <= n <= 1000")
        elif "sub5." in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
