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

        # Verifica que la primera línea contenga dos enteros n, m
        regex = re.compile(r"^\d+ \d+$")
        self.assertTrue(
            regex.match(lines[0]),
            "Se esperaban dos enteros separados por un espacio "
            + "en la primera línea",
        )
        n, m = map(int, lines[0].split())

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

        max_n = 1e6
        max_m = 1e9
        min_ai = 0
        max_ai = 1

        self.assertTrue(2 <= n <= max_n, "n está fuera de los límites")
        self.assertTrue(1 <= m <= max_m, "m está fuera de los límites")
        self.assertTrue(
            all(min_ai <= ai <= max_ai for ai in a),
            "Algún ai está fuera de los límites",
        )

        if 'sub1' in caseName:
            # $n, m \leq 1,000$
            self.assertTrue(n <= 1000, "n está fuera de los límites")
            self.assertTrue(m <= 1000, "m está fuera de los límites")
        elif 'sub2' in caseName:
            # $n \leq 20$
            self.assertTrue(n <= 20, "n está fuera de los límites")
        elif 'sub3' in caseName:
            # $n$ es potencia de dos y además, $A_{n-1} = 1$ y $A_i = 0$
            # para todo $0 \leq i < n - 1$
            self.assertTrue(n & (n - 1) == 0, "n no es potencia de dos")
            self.assertTrue(a[-1] == 1, "A_{n-1} != 1")
            self.assertTrue(all(ai == 0 for ai in a[:-1]), "A_i != 0")
        elif 'sub4' in caseName:
            # Sin condiciones adicionales
            pass
        else:
            self.fail(f"Subcaso desconocido: {caseName}")


if __name__ == "__main__":
    validatortest.main()
