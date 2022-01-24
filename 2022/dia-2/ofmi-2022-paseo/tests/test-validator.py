# !/usr/bin/python
#  -*- coding: utf-8 -*-

import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        regex = re.compile(r'^(\d+) (\d+)$')
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        self.assertTrue(regex.match(lines[0]))

        # Verificar el número de lineas
        self.assertEqual(len(lines), 2)

        # Tener los dos números dados N y K

        lines[0] = lines[0].split(' ')
        lines[0][0] = int(lines[0][0])
        lines[0][1] = int(lines[0][1])

        N = lines[0][0]
        K = lines[0][1]

        # Verificar que los números del arreglo cumplan los limites
        # y sean exactamente N números

        arr = lines[1].split(' ')

        ints = [int(v) for v in arr]

        self.assertEqual(len(ints), N)
        self.assertTrue(all(
            1 <= v <= 1000000000
            for v in ints
        ))

        # Verificar limites para subtareas

        caseName = sys.argv[1]

        if 'sub1' in caseName:
            self.assertTrue(K == 2)
        elif 'sub2' in caseName:
            self.assertTrue(K == 3)
        elif 'sub3' in caseName:
            self.assertTrue(1 <= N <= 20)

        # sub 4, cambiar nombre de casos
        self.assertTrue(1 <= N <= 1e5)
        self.assertTrue(1 <= K <= N)


if __name__ == '__main__':
    validatortest.main()
