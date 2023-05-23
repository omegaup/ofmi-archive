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

        # Verifica que la segunda línea contenga n paréntesis.
        regex = re.compile(r"^(\(|\)|])+$")
        self.assertTrue(
            regex.match(lines[1]),
            f"Se esperaban {n} parentesis en la segunda línea",
        )
        S = lines[1]
        self.assertEqual(
            len(S),
            n,
            f"Se esperaban {n} parentesis en la segunda línea",
        )

        max_n = 1e6

        self.assertTrue(1 <= n <= max_n, "n está fuera de los límites")

        if 'sub1' in caseName:
            # No hay ningún caracter `]` en $S$.
            self.assertTrue(']' not in S, "No se esperaba el caracter ]")
        elif 'sub2' in caseName:
            # Hay exactamente un caracter `]` en $S$
            self.assertTrue(S.count(']') == 1, "Se esperaba un caracter ]")
        elif 'sub3' in caseName:
            # Se te asegura que la cadena siempre se podrá balancear
            comodines = sum(1 for c in S if c == ']')
            last_comodin_extra = sum(1 if c == '(' else -1 for c in S)
            suma = 0
            for c in S:
                if c == '(':
                    suma += 1
                elif c == ')':
                    suma -= 1
                else:
                    suma -= 1
                    comodines -= 1
                    if comodines == 0 and last_comodin_extra > 0:
                        suma -= last_comodin_extra
                self.assertTrue(suma >= 0, "La cadena no se puede balancear")
            self.assertTrue(suma == 0, "La cadena no se puede balancear")
        elif 'sub4' in caseName:
            # No hay restricciones adicionales
            pass
        else:
            self.fail(f"Subcaso desconocido: {caseName}")


if __name__ == "__main__":
    validatortest.main()
