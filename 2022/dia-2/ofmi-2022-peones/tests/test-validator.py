#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914

import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        # Leer N y M
        regex_two_ints = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex_two_ints.match(lines[0]))
        N, M = map(int, lines[0].split(' '))

        # Límites
        self.assertTrue(3 <= N <= 100)
        self.assertTrue(3 <= M <= 100)

        # Checar tamaño de entrada
        self.assertEqual(len(lines), N + 2)

        # Procesar matriz
        matrix = [row.split(' ') for row in lines[1:N + 1]]
        for row in matrix:
            # Tamaño correcto
            self.assertEqual(len(row), M)

            # 0 espacio vacío, 1 peón negro
            self.assertTrue(all(
                element in ['0', '1']
                for element in row
            ))

        # Sólo un peón negro por columna
        self.assertTrue(all(
            [row[column] for row in matrix].count('1') == 1
            for column in range(M)
        ), "there should only be one black pawn per column")

        # Posición del peón blanco despejada
        self.assertEqual(matrix[-1][0], '0', "starting cell should be white")

        # Posición final
        self.assertTrue(regex_two_ints.match(lines[-1]))
        x, y = map(int, lines[-1].split(' '))
        self.assertTrue(1 <= x <= N, "target row out of bounds")
        self.assertTrue(1 <= y <= M, "target col out of bounds")

        # Verificar condiciones de subtareas
        caseName = sys.argv[1]

        if 'sub1' in caseName:
            # Todos los peones negros deben estar en la primer fila
            # Y la posición final no está en la primer columna
            self.assertEqual(matrix[0].count('1'),
                             M,
                             "all black pawns should be on top")
            self.assertNotEqual(y, 1, "unexpected target column")

        elif 'sub2' in caseName:
            # La posición final esta en la esquina superior derecha
            self.assertEqual(x, 1, "unexpected target row")
            self.assertEqual(y, M, "unexpected target column")

        elif 'sub3' in caseName:
            # La posición final esta en la primer columna
            self.assertEqual(y, 1, "target column should be 1")

        elif 'sub4' in caseName or 'sub5' in caseName:
            # Solo importa decir si se puede o no llegar a la posción final
            # La posición final no esta en la primer columna
            self.assertNotEqual(y, 1, "target column should not be 1")
        else:
            self.fail(f'Invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
