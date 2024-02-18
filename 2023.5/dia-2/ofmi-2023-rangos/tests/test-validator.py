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

        # En la primera línea un entero $n$
        reg = re.compile(r'^\d+$')
        self.assertTrue(reg.match(lines[0]), "Line 1: expected integer")
        n = int(lines[0])

        # En la segunda línea $n$ enteros positivos
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected n integers")
        P = list(map(int, lines[1].split()))
        self.assertTrue(len(P) == n, "Line 2: expected n integers")

        # En las siguientes N lineas contienen dos enteros cada una
        reg = re.compile(r'^\d+ \d+$')
        self.assertTrue(
            all(reg.match(line) for line in lines[2:]),
            "Expected 2 integers in each of the following n lines",
        )
        R = [tuple(map(int, line.split())) for line in lines[2:]]
        self.assertTrue(len(R) == n, "Expected n lines")

        # Límites
        self.assertTrue(1 <= n <= 10**5, "n out of bounds")
        self.assertTrue(all(1 <= p <= 10**9 for p in P), "P out of bounds")
        self.assertTrue(
            all(1 <= left <= right <= 10**9 for left, right in R),
            "Range out of bounds",
        )

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # $1 \leq N \leq 8$
            self.assertTrue(1 <= n <= 8, "Sub 1: n out of bounds")
            # $1 \leq L_i, R_i, P_i \leq 10^6$
            self.assertTrue(
                all(1 <= p <= 10**6 for p in P),
                "Sub 1: P out of bounds",
            )
            self.assertTrue(
                all(1 <= left <= right <= 10**6 for left, right in R),
                "Sub 1: Range out of bounds",
            )
        elif 'sub2' in caseName:
            # $1 \leq N \leq 10^3$
            self.assertTrue(1 <= n <= 10**3, "Sub 2: n out of bounds")
            # Los rangos no se intersecan entre ellos
            S = sorted(R)
            self.assertTrue(
                all(S[i][1] < S[i + 1][0] for i in range(len(S) - 1)),
                "Sub 2: Ranges intersect",
            )
        elif 'sub3' in caseName:
            # Todos los rangos son del mismo tamaño.
            T = [right - left + 1 for left, right in R]
            self.assertTrue(len(set(T)) == 1, "Sub 3: Range sizes differ")
        elif 'sub4' in caseName:
            # $1 \leq N \leq 10^3$
            self.assertTrue(1 <= n <= 10**3, "Sub 4: n out of bounds")
        elif 'sub5' in caseName:
            # $1 \leq L_i, R_i, P_i \leq 10^6$
            self.assertTrue(
                all(1 <= p <= 10**6 for p in P),
                "Sub 5: P out of bounds",
            )
            self.assertTrue(
                all(1 <= left <= right <= 10**6 for left, right in R),
                "Sub 5: Range out of bounds",
            )
        elif 'sub6' in caseName:
            # Sin consideraciones adicionales
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
