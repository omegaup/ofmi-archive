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

        # En la primera línea, tres enteros $n$, $m$ y $q$
        reg = re.compile(r"^(\d+) (\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected three integers")
        n, m, q = map(int, lines[0].split())

        # Luego, vendrán $n$ pares de líneas
        # fmt: off
        T = lines[1: 1 + 2 * n]
        self.assertTrue(len(T) == 2 * n, "expected 2N lines")
        T = [(T[i], T[i + 1]) for i in range(0, 2 * n, 2)]
        #   donde la primera línea contiene un entero $p_i$
        reg = re.compile(r"^(\d+)$")
        self.assertTrue(
            all(reg.match(ti) for (ti, _) in T),
            "expected one integer ti",
        )
        T = [(int(ti), Pi) for (ti, Pi) in T]
        #   y la siguiente línea contiene $p_i$ enteros separados con espacios.
        #   Si ti = 0, la linea debe estar vacia
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            all(reg.match(Ti) if ti > 0 else Ti == ""
                for (ti, Ti) in T),
            "expected only integers for ti",
        )
        T = [(ti, list(map(int, Pi.split()))) for (ti, Pi) in T]
        self.assertTrue(
            all(len(Pi) == len(set(Pi)) == ti for (ti, Pi) in T),
            "expected ti distinct integers",
        )

        # En la siguientes $q$ líneas vendrá un entero $k_i$
        reg = re.compile(r"^(\d+)$")
        # fmt: off
        Q = lines[1 + 2 * n:]
        self.assertTrue(all(reg.match(ki) for ki in Q), "expected q integers")
        Q = list(map(int, Q))
        self.assertTrue(len(Q) == q, "expected q integers")

        # Límites
        self.assertTrue(1 <= n <= 10**4, "n out of bounds")
        self.assertTrue(1 <= m <= 10**5, "m out of bounds")
        self.assertTrue(1 <= q <= n + 1, "q out of bounds")
        self.assertTrue(all(0 <= ti <= m for (ti, _) in T), "ti out of bounds")
        self.assertTrue(
            sum(ti for (ti, _) in T) <= 10**5,
            "sum of ti should be at most 10^5",
        )
        self.assertTrue(all(0 <= ki <= n for ki in Q), "ki out of bounds")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(m == 1, "Sub1: m must be 1")
        elif "sub2" in caseName:
            self.assertTrue(n == 1, "Sub2: n must be 1")
        elif "sub3" in caseName:
            self.assertTrue(q == 1, "Sub3: q must be 1")
            self.assertTrue(Q[0] == 1, "Sub3: k_1 must be 1")
        elif "sub4" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")

        # Cada subtarea tiene todos sus casos agrupados.
        reg = re.compile(r"^sub(\d+)\.(\w+)$")
        self.assertTrue(reg.match(caseName), "case must be grouped")


if __name__ == "__main__":
    validatortest.main()
