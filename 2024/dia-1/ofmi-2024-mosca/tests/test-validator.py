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

        # En la primera línea dos enteros $n$ y $m$.
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        (n, m) = list(map(int, lines[0].split()))

        # En la segunda línea $m$ enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected m integers")
        P = list(map(int, lines[1].split()))
        self.assertTrue(len(P) == m, "Line 2: expected m integers")

        # En la tercer línea un entero $q$.
        reg = re.compile(r"^(\d+)$")
        self.assertTrue(reg.match(lines[2]), "Line 3: expected one integer")
        q = int(lines[2])

        # Siguientes $q$ líneas, un entero $a_i$.
        A = list(map(int, lines[3:]))
        self.assertTrue(len(A) == q, "expected q queries")
        self.assertTrue(all(1 <= Ai <= n for Ai in A), "1 <= a_i <= n")
        self.assertTrue(
            all(A[i - 1] <= A[i] for i in range(1, len(A))),
            "a_i <= a_j",
        )

        # Límites
        self.assertTrue(1 <= n <= 10**9, "1 <= n <= 10**9")
        self.assertTrue(
            1 <= m <= min(n, 2 * 10**5),
            "1 <= m <= min(n, 2*10**5)",
        )
        self.assertTrue(1 <= q <= 2 * 10**5, "1 <= q <= 2*10**5")
        self.assertTrue(all(1 <= Pi <= n for Pi in P), "1 <= p_i <= n")

        # La suma de los grupos en la lista es exactamente $n$.
        self.assertTrue(sum(P) == n, "Line 2: expected sum to be exactly n")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(m == 2, "Sub1: m must be 2")
        elif "sub2" in caseName:
            self.assertTrue(1 <= n <= 2 * 10**5, "Sub2: 1 <= n <= 2*10**5")
        elif "sub3" in caseName:
            self.assertTrue(1 <= q <= 300, "Sub3: 1 <= q <= 300")
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
