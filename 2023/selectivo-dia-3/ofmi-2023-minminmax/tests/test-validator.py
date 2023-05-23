import re
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
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

        max_n = 1e5
        min_ai = -1e9
        max_ai = 1e9

        self.assertTrue(1 <= n <= max_n, "n está fuera de los límites")
        self.assertTrue(1 <= m <= n, "m está fuera de los límites")
        self.assertTrue(
            all(min_ai <= ai <= max_ai for ai in a),
            "Algún ai está fuera de los límites",
        )


if __name__ == "__main__":
    validatortest.main()
