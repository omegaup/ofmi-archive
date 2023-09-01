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

        # Verifica que la segunda línea contenga n enteros.
        regex = re.compile(r"^-?\d+( -?\d+)*$")
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

        min_n = 2
        max_n = 1e4
        min_ai = -1e9
        max_ai = 1e9

        self.assertTrue(min_n <= n <= max_n, "n está fuera de los límites")
        self.assertTrue(
            all(min_ai <= ai <= max_ai for ai in a),
            "Algún ai está fuera de los límites",
        )

        if 'sub1' in caseName:
            # n = 2
            self.assertTrue(n == 2, "n debe ser 2 en el subcaso 1")
        elif 'sub2' in caseName:
            # n = 3
            self.assertTrue(n == 3, "n debe ser 3 en el subcaso 2")
        elif 'sub3' in caseName:
            # No hay restricciones adicionales
            pass
        elif 'sub4' in caseName:
            # No hay restricciones adicionales
            pass
        else:
            self.fail(f"Subcaso desconocido: {caseName}")


if __name__ == "__main__":
    validatortest.main()
