#!/usr/bin/python
# -*- coding: utf-8 -*-
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

        # En la primera línea, un entero N
        regex = re.compile(r'^(\d+)$')
        self.assertTrue(regex.match(lines[0]))
        N = int(lines[0])

        # En la segunda línea un arreglo A_i de N enteros
        a_is = [int(x) for x in lines[1].split(' ')]
        self.assertEqual(len(a_is), N)

        # En la tercera línea un entero Q y un entero X
        self.assertTrue(lines[2][-1] != ' ')
        qAndX = lines[2].split(' ')
        Q = int(qAndX[0])
        X = int(qAndX[1])

        # Límites
        self.assertTrue(1 <= N <= 1e5)
        self.assertTrue(1 <= Q <= 1e6)
        self.assertTrue(1 <= X <= 1e9)

        # Ninguna cobaya pasa más de 16 segundos sin saltar
        self.assertTrue(all(1 <= ai <= 16 for ai in a_is))

        # Verificar limites para subtareas
        # Tomamos el nombre del caso
        caseName = sys.argv[1]

        if 'sub1' in caseName:
            # N <= 100, Q <= 1,000, X <= 50
            self.assertLessEqual(N, 100)
            self.assertLessEqual(Q, 1000)
            self.assertLessEqual(X, 50)
        elif 'sub2' in caseName:
            # X = 1
            self.assertTrue(X == 1)
        elif 'sub3' in caseName:
            # N <= 100, Q <= 10,000
            self.assertLessEqual(N, 100)
            self.assertLessEqual(Q, 1e4)
        elif 'sub4' in caseName:
            # Q <= 10,000
            self.assertLess(Q, 1e4)
        elif 'sub5' not in caseName:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
