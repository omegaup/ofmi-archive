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

        self.assertTrue(len(lines) == 2, "Se esperaban dos líneas")

        # En la primera línea dos enteros n y m.
        reg = re.compile(r'^\d+ \d+$')
        self.assertTrue(
            reg.match(lines[0]),
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
        k = list(map(int, lines[1].split()))
        self.assertEqual(
            len(k),
            n,
            f"Se esperaban {n} enteros separados "
            + "por espacios en la segunda línea",
        )

        # Checar límites

        # $1 \leq n \leq 10^6$
        self.assertTrue(
            1 <= n <= 3*(10**5),
            "Se esperaba 1 <= n <= 10^6",
        )
        # $1 \leq m \leq n$
        self.assertTrue(
            1 <= m <= n,
            "Se esperaba 1 <= m <= n",
        )
        # $-10^9 \leq k_i \leq 10^9$
        self.assertTrue(
            all(map(lambda x: -10**9 <= x <= 10**9, k)),
            "Se esperaba -10^9 <= k[i] <= 10^9",
        )

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # $m = 1$
            self.assertTrue(m == 1, "Se esperaba m = 1")
        elif 'sub2' in caseName:
            # $1 \leq N \leq 1000$
            self.assertTrue(
                1 <= n <= 1000,
                "Se esperaba n <= 1000",
            )
        elif 'sub3' in caseName:
            # $0 \leq k_i \leq 1$
            self.assertTrue(
                all(map(lambda x: x in [0, 1], k)),
                "Se esperaba 0 <= k[i] <= 1",
            )
        elif 'sub4' in caseName:
            # $-100 \leq k_i \leq 100$
            self.assertTrue(
                all(map(lambda x: -100 <= x <= 100, k)),
                "Se esperaba -100 <= k[i] <= 100",
            )
        elif 'sub5' in caseName:
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
