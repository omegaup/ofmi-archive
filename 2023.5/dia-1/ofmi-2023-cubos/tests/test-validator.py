import re
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()
        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()
        self.assertTrue(
            len(lines) == 1,
            "Se esperaba una sola linea"
        )
        self.assertTrue(
            re.match(r"^-?\d+$", lines[0]),
            "Se esperaba un entero"
        )
        n = int(lines[0])
        # Checar que 1 <= n <= 50
        self.assertTrue(
            1 <= n <= 50,
            "N debe ser un entero entre 1 y 50"
        )


if __name__ == '__main__':
    validatortest.main()
