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

        self.assertTrue(len(lines) == 1, "Unexpected number of lines")

        # Única línea con dos enteros n y L
        reg = re.compile(r'^\d+ \d+$')
        self.assertTrue(reg.match(lines[0]), "n and L must be integers")
        n, L = map(int, lines[0].split())

        # Límites
        self.assertTrue(1 <= n <= 300, "n is out of bounds")
        self.assertTrue(2 <= L <= 10**9, "L is out of bounds")

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # $n = 2$
            self.assertTrue(n == 2, "n must be 2")
        elif 'sub2' in caseName:
            # $n$ es potencia de dos.
            self.assertTrue(n & (n - 1) == 0, "n must be a power of two")
            # $L = 2$
            self.assertTrue(L == 2, "L must be 2")
        elif 'sub3' in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
