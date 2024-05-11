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

        # Tres líneas en la entrada
        self.assertTrue(len(lines) == 3, "expected 3 lines")

        # En la primera línea un entero $n$
        reg = re.compile(r'^\d+$')
        self.assertTrue(reg.match(lines[0]), "Line 1: expected integer")
        n = int(lines[0])

        # En la segunda línea $n$ enteros positivos
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected n integers")

        A = list(map(int, lines[1].split()))
        self.assertTrue(len(A) == n, "Line 2: expected n integers")

        # En la tercera línea $n$ enteros positivos
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(reg.match(lines[2]), "Line 3: expected n integers")

        T = list(map(int, lines[2].split()))
        self.assertTrue(len(T) == n, "Line 3: expected n integers")

        # Todos los Ti son diferentes
        self.assertTrue(len(set(T)) == n, "Todos los Ti deben ser diferentes")

        # Límites
        self.assertTrue(1 <= n <= 3 * 10**5, "n fuera de límites")
        self.assertTrue(all(1 <= a <= 10**9 for a in A), "A fuera de límites")
        self.assertTrue(all(0 <= t < n for t in T), "T fuera de límites")

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # $1 \leq n \leq 100$
            self.assertTrue(1 <= n <= 100, "Sub 1: n fuera de límites")
        elif 'sub2' in caseName:
            # $1 \leq n \leq 10^4$
            self.assertTrue(1 <= n <= 5 * 10**3, "Sub 2: n fuera de límites")
        elif 'sub3' in caseName:
            # $1 \leq n \leq 10^4$
            self.assertTrue(
                all(T[i] == i for i in [0, n-1]), "Sub 3: T inválida")
        elif 'sub4' in caseName:
            # $A_i = 1$ para toda $0 \leq i < n$
            self.assertTrue(
                all(a == 1 for a in A), "Sub 4: A inválida")
        elif 'sub5' in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
