import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        caseName = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(
            lines[-1], "", "Se esperaba un salto de línea al final del archivo"
        )
        lines.pop()

        # Verifica que la primera línea contenga un entero n
        regex = re.compile(r"^\d+$")
        self.assertTrue(
            regex.match(lines[0]),
            "Se esperaban un entero en la primera línea",
        )
        n = int(lines[0])

        # En las siguientes n lineas vendrán dos parejas de enteros
        self.assertTrue(len(lines[1:]) == n + 1, f"Se esperaban {n+1} líneas")
        regex = re.compile(r"^\d+ \d+$")
        self.assertTrue(
            all(regex.match(line) for line in lines[1:]),
            f"Se esperaban dos enteros en las siguientes {n+1} líneas",
        )

        A = [list(map(int, line.split())) for line in lines[1:]]
        P = [a[0] for a in A]
        M = [a[1] for a in A]

        max_n = 5000
        max_ai = 1e6

        self.assertTrue(1 <= n <= max_n, "n está fuera de los límites")
        self.assertTrue(
            all(1 <= p <= max_ai for p in P),
            "Algún pi está fuera de los límites",
        )
        self.assertTrue(
            all(1 <= m <= max_ai for m in M),
            "Algún mi está fuera de los límites",
        )

        if 'sub1' in caseName:
            # $n \leq 10$
            self.assertTrue(n <= 10, "n debe ser menor o igual a 10")
        elif 'sub2' in caseName:
            # Todos los valores de $p_i$ son distintos entre sí.
            self.assertTrue(len(set(P)) == n + 1,
                            "Todos los valores de pi deben ser distintos")
            # $P$ es menor que cualquier $p_i$.
            self.assertTrue(all(P[0] < p for p in P[1:]),
                            "P debe ser menor que cualquier pi")
            # $M$ es menor que cualquier $m_i$.
            self.assertTrue(all(M[0] < m for m in M[1:]),
                            "M debe ser menor que cualquier mi")
        elif 'sub3' in caseName:
            # Todos los valores de $p_i$ son distintos entre sí.
            self.assertTrue(len(set(P)) == n + 1,
                            "Todos los valores de pi deben ser distintos")
        elif 'sub4' in caseName:
            pass
        else:
            self.fail(f"Invalid case name: {caseName}")


if __name__ == "__main__":
    validatortest.main()
