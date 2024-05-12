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

        # En la primera línea viene un entero $n$ ($1 \leq n \leq 10^6$)
        reg = re.compile(r'^(\d+)$')
        self.assertTrue(reg.match(lines[0]), "Line 1 must contain an integer")
        n = int(lines[0])
        self.assertTrue(1 <= n <= 10**18, "Invalid n")

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # $1 \leq n \leq 20$
            self.assertTrue(1 <= n <= 20, "Invalid n for subtask 1")
        elif 'sub2' in caseName:
            # $1 \leq n \leq 10^6$
            self.assertTrue(1 <= n <= 10**6, "Invalid n for subtask 2")
        elif 'sub3' in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
