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

        # En la primera línea dos enteros $n$ y $k$
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        n, k = map(int, lines[0].split())

        # En la segunda línea vendrán $x$ y $y$
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[1]), "Line 2: expected two integers")
        x, y = map(int, lines[1].split())

        self.assertTrue(1 <= n <= 10**6, "n out of bounds")
        self.assertTrue(1 <= k <= 2 * 10**5, "k out of bounds")
        self.assertTrue(1 <= x <= n, "queen out of bounds")
        self.assertTrue(1 <= y <= n, "queen out of bounds")

        # Las siguientes k lineas tendran c, x_i y y_i, donde c es T, A, o C.
        reg = re.compile(r"^(T|A|C) (\d+) (\d+)$")
        raw_pieces = lines[2:]
        self.assertTrue(len(raw_pieces) == k, "there is no exactly k pieces")
        self.assertTrue(all(reg.match(raw_piece) for raw_piece in raw_pieces),
                        "the line for a piece has a different format")
        pieces = zip(*(raw_piece.split() for raw_piece in raw_pieces))
        k_i, x_i, y_i = pieces
        k_i = list(k_i)
        x_i = list(x_i)
        y_i = list(y_i)
        x_i = list(map(int, x_i))
        y_i = list(map(int, y_i))

        # Límites
        self.assertTrue(all(1 <= xi <= n for xi in x_i), "x_i out of bounds")
        self.assertTrue(all(1 <= yi <= n for yi in y_i), "y_i out of bounds")

        x_i.append(x)
        y_i.append(y)
        self.assertTrue(len(set(list(zip(x_i, y_i)))) == (k + 1),
                        "repeated positions")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(n == 8, "Sub1: n must be 8")
        elif "sub2" in caseName:
            self.assertTrue({'T'} == set(k_i), "Sub2: all pieces must be T")
        elif "sub3" in caseName:
            self.assertTrue(set(k_i).issubset({'T', 'A'}),
                            "Sub3: all pieces must be T or A")
        elif "sub4" in caseName:
            # Sin restricciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")

        # Cada subtarea tiene todos sus casos agrupados.
        reg = re.compile(r"^sub(\d+)\.(\w+)$")
        self.assertTrue(reg.match(caseName), "case must be grouped")


if __name__ == "__main__":
    validatortest.main()
