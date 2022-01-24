# !/usr/bin/python
#  -*- coding: utf-8 -*-

import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        regex = re.compile(r'^(\d+)$')
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        self.assertTrue(regex.match(lines[0]))

        # Tener el número N

        N = int(lines[0])

        # Verificar el número de lineas
        self.assertEqual(len(lines), 2)

        # Verificar que los números del arreglo cumplan los limites
        # y sean exactamente N números

        arr = lines[1].split(' ')

        ints = [int(v) for v in arr]

        self.assertEqual(len(ints), N)
        self.assertTrue(all(
            1 <= v <= 1e9
            for v in ints
        ))

        # Verificar límites para subtareas

        caseName = sys.argv[1]

        if 'sub1' in caseName:
            self.assertTrue(1 <= N <= 3)
        elif 'sub2' in caseName:
            # Se te asegura que si la puja es mayor a la puja última
            # puja válida, entonces es mayor o igual a las dos últimas
            # pujas, y viceversa.

            # Esto se cumple si todos los números son potencia de dos
            self.assertTrue(all(
                v & (v - 1) == 0
                for v in ints
            ))

            # Y además,
            # el siguiente número mayor o igual sea estrictamente mayor
            sigIdx = min([i if i > 0 and x >= ints[0]
                          else len(ints)+1
                          for i, x in enumerate(ints)])
            self.assertTrue(sigIdx > len(ints) or ints[sigIdx] > ints[0])

            self.assertTrue(1 <= N <= 1e5)
        elif 'sub3' in caseName:
            self.assertTrue(1 <= N <= 1e5)
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
