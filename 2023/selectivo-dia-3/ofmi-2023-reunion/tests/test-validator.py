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

        # Verificar que hayan tres líneas
        self.assertEqual(len(lines), 3, "Se esperaban tres líneas")

        # Verifica que la primera línea contenga dos enteros n, m
        regex = re.compile(r"^\d+$")
        self.assertTrue(
            regex.match(lines[0]),
            "Se esperaba un entero en la primera línea",
        )
        n = int(lines[0])

        # Verifica que la segunda y tercera línea contengan n enteros.
        regex = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            regex.match(lines[1]) and regex.match(lines[2]),
            f"Se esperaban {n} enteros separados por espacios "
            + "en la segunda y tercera línea",
        )
        X = list(map(int, lines[1].split()))
        V = list(map(int, lines[2].split()))
        self.assertTrue(
            len(X) == len(V) == n,
            f"Se esperaban {n} enteros separados por espacios "
            + "en la segunda y tercera línea",
        )

        max_n = 50000
        min_ai = 1
        max_ai = 1e9

        self.assertTrue(1 <= n <= max_n, "n está fuera de los límites")
        self.assertTrue(
            all(min_ai <= xi <= max_ai for xi in X)
            and all(min_ai <= vi <= max_ai for vi in V),
            "Algún xi o vi está fuera de los límites",
        )

        if 'sub1' in caseName:
            # $n = 2$
            self.assertTrue(n == 2, "n no es igual a 2 en sub1")
        elif 'sub2' in caseName:
            # $n = 3$
            self.assertTrue(n == 3, "n no es igual a 3 en sub2")
        elif 'sub3' in caseName:
            # $V_i = V_j$ para toda $0 \leq i, j \leq n-1$
            self.assertTrue(all(V[0] == vi for vi in V),
                            "No todos los V son iguales en sub3")
        elif 'sub4' in caseName:
            # $n \leq 1,000$
            self.assertTrue(n <= 1000, "n es mayor a 1000 en sub4")
        elif 'sub5' in caseName:
            pass
        else:
            self.fail(f"Subcaso desconocido: {caseName}")


if __name__ == "__main__":
    validatortest.main()
