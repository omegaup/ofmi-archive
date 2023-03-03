import re
import sys
import unittest
from omegaup.validator import validatortest


# Verifica que la matriz sea espiral de afuera hacia adentro o de adentro hacia
# afuera.
def spiralMatrix(matrix, kind='both'):
    if kind == 'both':
        return spiralMatrix(matrix, 'inside-out') or \
            spiralMatrix(matrix, 'outside-in')
    N = len(matrix)
    max_value = (N + 1) // 2
    for k in range(max_value):
        x = k + 1 if kind == 'outside-in' else max_value - k
        for i in range(k, N - k):
            if matrix[k][i] != x or matrix[N - k - 1][i] != x or \
               matrix[i][k] != x or matrix[i][N - k - 1] != x:
                return False
    return True


class Test(unittest.TestCase):
    def test(self):
        caseName = sys.argv[1]
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '',
                         'Se esperaba un salto de línea al final del archivo')
        lines.pop()

        # Verifica que la primera línea contenta un entero N.
        regex = re.compile(r'^\d+$')
        self.assertTrue(regex.match(lines[0]),
                        'Se esperaba un entero N en la primera línea')

        N = int(lines[0])
        self.assertTrue(1 <= N <= 800, 'N está fuera de los límites')
        self.assertTrue(N % 2 == 1, 'N debe ser impar')

        # Verifica que después hayan N líneas con N enteros.
        self.assertEqual(len(lines) - 1, N,
                         f'Se esperaban {N} líneas después de la segunda '
                         'línea')

        regex = re.compile(r'^\d+( \d+)*$')
        matrix = []
        for i in range(1, N + 1):
            self.assertTrue(regex.match(lines[i]),
                            f'Se esperaban {N} enteros separados por un '
                            f'espacio en la línea {i+1}')
            row = list(map(int, lines[i].split()))
            self.assertEqual(len(row), N,
                             f'Se esperaban {N} enteros separados por un '
                             f'espacio en la línea {i+1}')
            matrix.append(row)

        if 'sub1' in caseName:
            # Subtarea 1. 1 <= N <= 3.
            self.assertTrue(1 <= N <= 3, 'N está fuera de los límites')
        elif 'sub2' in caseName:
            # Subtarea 2. La matriz siempre es espiral.
            self.assertTrue(spiralMatrix(matrix), "La matriz debe ser espiral")
        elif 'sub3' in caseName:
            # Subtarea 3. Solo habrán matrices no espirales y espirales de
            # afuera hacia adentro
            self.assertFalse(spiralMatrix(matrix, 'inside-out'),
                             "No puede haber matrices de adentro hacia afuera")
        elif 'sub4' in caseName:
            # Subtarea 4. Solo habrán matrices no espirales y espirales de
            # adentro hacia afuera.
            self.assertFalse(spiralMatrix(matrix, 'outside-in'),
                             "No puede haber matrices de afuera hacia adentro")


if __name__ == '__main__':
    validatortest.main()
