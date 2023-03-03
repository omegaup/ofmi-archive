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

        # Verifica que la primera línea contenga dos enteros n, d
        regex = re.compile(r"^\d+ \d+$")
        self.assertTrue(
            regex.match(lines[0]),
            "Se esperaban dos enteros separados por un espacio "
            + "en la primera línea",
        )
        n, d = map(int, lines[0].split())

        # Verifica que la segunda línea contenga n enteros.
        regex = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            regex.match(lines[1]),
            f"Se esperaban {n} enteros separados por espacios "
            + "en la segunda línea",
        )
        a = list(map(int, lines[1].split()))
        self.assertEqual(
            len(a),
            n,
            f"Se esperaban {n} enteros separados "
            + "por espacios en la segunda línea",
        )

        maxn = 1e5
        maxd = 1e9
        maxai = 1e9
        if "sub1" in caseName:
            # Subtarea 1: d = 1
            maxd = 1
        elif "sub2" in caseName:
            # Subtarea 2: n = 1
            maxn = 1
        elif "sub3" in caseName:
            # Subtarea 3: 1 <= n <= 100, 1 <= d, a_i <= 100
            maxn = 100
            maxd = 100
            maxai = 100

        self.assertTrue(1 <= n <= maxn, "n está fuera de los límites")
        self.assertTrue(1 <= d <= maxd, "d está fuera de los límites")
        self.assertTrue(
            all(1 <= ai <= maxai for ai in a),
            "Algún ai está fuera de los límites",
        )


if __name__ == "__main__":
    validatortest.main()
