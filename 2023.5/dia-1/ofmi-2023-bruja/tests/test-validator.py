import re
import sys
import unittest
from omegaup.validator import validatortest


# Regresa True si todos los valores iguales aparecen
# consecutivamente. Regresa False en otro caso
def consecutive(n: int, k: list):
    previous = set()
    for i in range(1, n):
        # Si ya aparecio antes, entonces no son consecutivos
        if k[i] in previous:
            return False
        # Si se va a cambiar de valor, agregamos k[i] a
        # los elementos previos
        if(i + 1 < n and k[i] != k[i + 1]):
            previous.add(k[i])
    return True


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        self.assertTrue(len(lines) == 2, "Se esperaban dos lineas")

        # En la primera línea un entero n.
        reg = re.compile(r"^\d+$")
        self.assertTrue(
            reg.match(lines[0]),
            "Se esperaba un entero en la primera linea"
        )
        n = int(lines[0])

        # Verifica que la segunda línea contenga
        # n enteros separados por un espacio.
        regex = re.compile(r"^-?\d+( -?\d+)" + "{" + f"{n - 1}" + "}$")
        self.assertTrue(
            regex.match(lines[1]),
            f"Se esperaban {n} enteros separados por un espacio "
            + "en la segunda linea"
        )
        k = list(map(int, lines[1].split()))

        # Checar límites

        # $1 \leq n \leq 10^6$
        self.assertTrue(
            1 <= n <= 10**6,
            "Se esperaba 1 <= n <= 10^6"
        )

        # $-10^9 \leq f_i \leq 10^9$
        self.assertTrue(
            all(map(lambda x: -10**9 <= x <= 10**9, k)),
            "Se esperaba -10^9 <= f[i] <= 10^9",
        )

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # Revisa que todos los elementos
            # de un mismo valor sean consecutivos
            self.assertTrue(
                consecutive(n, k),
                "Se esperaba que todos los valores "
                + "iguales f_i aparezcan consecutivos"
                )
        elif 'sub2' in caseName:
            # $0 \leq f_i \leq 10^3$
            self.assertTrue(
                all(map(lambda x: 0 <= x <= 10**3, k)),
                "Se esperaba 0 <= f[i] <= 10^3"
                )
        elif 'sub3' in caseName:
            # $-10^4 \leq f_i \leq 10^4$
            self.assertTrue(
                all(map(lambda x: -10**4 <= x <= 10**4, k)),
                "Se esperaba -10^4 <= f[i] <= 10^4"
                )
        elif 'sub4' in caseName:
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
