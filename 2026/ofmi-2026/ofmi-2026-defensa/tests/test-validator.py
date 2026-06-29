import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().strip().split("\n")

        # En la primera línea vendrán dos enteros $n$ y $k$.
        self.assertTrue(re.match(r"^\d+ \d+$", lines[0]),
                        "Line 1: expected two integers")
        (n, k) = list(map(int, lines[0].split()))

        # En las siguientes $k$ líneas vendrán tres enteros $Li$, $Ri$ y $Ei$.
        L = [0] * k
        R = [0] * k
        E = [0] * k
        for i in range(k):
            self.assertTrue(re.match(r"^\d+ \d+ \d+$", lines[i + 1]),
                            f"Line {i + 2}: expected three integers")
            (L[i], R[i], E[i]) = list(map(int, lines[i + 1].split()))

        # En la siguiente línea vendrá un entero $q$.
        self.assertTrue(re.match(r"^\d+$", lines[k + 1]),
                        f"Line {k + 2}: expected one integer")
        q = int(lines[k + 1])

        # En las siguientes $q$ líneas vendrá un entero $Xi$.
        X = [0] * q
        for i in range(q):
            self.assertTrue(re.match(r"^\d+$", lines[i + k + 2]),
                            f"Line {i + k + 3}: expected one integer")
            X[i] = int(lines[i + k + 2])

        # Checks de límites generales.
        self.assertTrue(1 <= n <= 10**9, "1 <= n <= 10^9")
        self.assertTrue(1 <= k <= 10**5, "1 <= k <= 10^5")
        self.assertTrue(all(1 <= Li <= Ri <= n for (Li, Ri) in zip(L, R)),
                        "1 <= Li <= Ri <= n")
        self.assertTrue(all(1 <= Ei <= 10**9 for Ei in E), "1 <= Ei <= 10^9")
        self.assertLessEqual(sum(E), 10**9, "sum of Ei <= 10^9")
        self.assertTrue(1 <= q <= 10**5, "1 <= q <= 10^5")
        self.assertTrue(all(1 <= Xi <= 10**9 for Xi in X), "1 <= Xi <= 10^9")

        # Cada subtarea tiene todos sus casos agrupados.
        # Si los casos no estan agrupados esto se puede borrar.
        caseName = sys.argv[1]
        self.assertTrue(re.match(r"^sub\d+\.(\w|-)+$", caseName),
                        "Case must be grouped")

        # Checks de limites de cada subtarea.
        if re.match(r"^sub1", caseName):
            self.assertTrue(1 <= n <= 100, "Sub1: 1 <= n <= 100")
            self.assertTrue(all(Ei == 1 for Ei in E), "Sub1: Ei == 1")
        elif re.match(r"^sub2", caseName):
            self.assertTrue(1 <= k <= 2, "Sub2: 1 <= k <= 2")
            self.assertTrue(all(Ei == 1 for Ei in E), "Sub2: Ei == 1")
        elif re.match(r"^sub3", caseName):
            self.assertTrue(1 <= n <= 10**6, "Sub3: 1 <= n <= 10^6")
            self.assertTrue(all(Li == Ri for (Li, Ri) in zip(L, R)),
                            "Sub3: Li == Ri")
            self.assertTrue(all(Ei == 1 for Ei in E), "Sub3: Ei == 1")
        elif re.match(r"^sub4", caseName):
            self.assertTrue(1 <= n <= 10**6, "Sub4: 1 <= n <= 10^6")
            self.assertTrue(all(Ei == 1 for Ei in E), "Sub4: Ei == 1")
            self.assertEqual(q, 1, "Sub4: q == 1")
        elif re.match(r"^sub5", caseName):
            self.assertTrue(1 <= n <= 10**6, "Sub5: 1 <= n <= 10^6")
            self.assertTrue(all(Ei == 1 for Ei in E), "Sub5: Ei == 1")
        elif re.match(r"^sub6", caseName):
            self.assertTrue(all(Ei == 1 for Ei in E), "Sub6: Ei == 1")
        else:
            # Sin restricciones adicionales.
            self.assertTrue(re.match(r"^sub7", caseName),
                            f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
