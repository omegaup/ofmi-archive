# !/usr/bin/python
#  -*- coding: utf-8 -*-

import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(
            lines[-1],
            '',
            "Se esperaba un salto de línea al final del archivo"
        )
        lines.pop()

        # La primera línea tiene dos enteros separados por un espacio
        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(
            regex.match(lines[0]),
            "Se esperaban 2 enteros separados por espacios en la primera línea"
        )

        # Verificar el número de lineas
        self.assertEqual(len(lines), 2)

        # N y M
        N, M = [int(num) for num in lines[0].split()]

        # La segunda línea tiene tres enteros separados por un espacio
        regex = re.compile(r'^(-?\d+) (-?\d+) (-?\d+)$')
        self.assertTrue(
            regex.match(lines[1]),
            "Se esperaban 3 enteros separados por espacios en la segunda línea"
        )

        # P, A y B
        P, A, B = [int(num) for num in lines[1].split()]

        # $1 <= N, M, A, B <= 10^6$ $1 <= P <= M$
        self.assertTrue(1 <= N <= 1e6, "N está fuera de los límites")
        self.assertTrue(1 <= M <= 1e6, "M está fuera de los límites")
        self.assertTrue(-1e6 <= A <= 1e6, "A está fuera de los límites")
        self.assertTrue(-1e6 <= B <= 1e6, "B está fuera de los límites")
        self.assertTrue(B != 0, "B no puede ser cero")
        self.assertTrue(-1e6 <= P <= 1e6, "P está fuera de los límites")
        self.assertTrue(N % 2 == 0, "N debe ser par")

        # Verificar nombres de subtareas
        caseName = sys.argv[1]
        if 'sub1' in caseName:
            self.assertTrue(A == 0 and B == 1, "El tiro debe ser recto")

        elif 'sub2' in caseName:
            # El tiro del contrincante no falla

            # Calcular rango de pendientes de acuerdo el caso
            if 0 <= P <= M:
                # En medio
                pendiente_superior = (M - P) / (N / 2)
                pendiente_inferior = -P / (N / 2)
            elif P < 0:
                # Abajo
                pendiente_superior = (M - P) / (N / 2)
                pendiente_inferior = -P / N
            else:
                # Arriba
                pendiente_superior = (M - P) / N
                pendiente_inferior = -P / (N / 2)

            # Checar si no falla
            self.assertTrue(pendiente_inferior <= A / B, "Pendiente baja")
            self.assertTrue(A / B <= pendiente_superior, "Pendiente alta")

        elif 'sub3' in caseName:
            # El tiro debe empezar dentro de la mesa
            self.assertTrue(0 <= P <= M)

        elif not any(sub in caseName for sub in ['sub1', 'sub4']):
            self.fail(f'Invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
