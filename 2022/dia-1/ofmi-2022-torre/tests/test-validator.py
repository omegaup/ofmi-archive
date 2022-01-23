#!\usr/bin/python
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
        # Verificamos que haya 3 lineas
        self.assertEqual(len(lines), 3)

        # Leemos las líneas
        reg = re.compile(r'^(\d+ \d+)$')
        self.assertTrue(all(reg.match(line) for line in lines))
        N, M = [int(x) for x in lines[0].split(' ')]
        A, B = [int(x) for x in lines[1].split(' ')]
        JA, JB = [int(x) for x in lines[2].split(' ')]

        # Verificamos que las posiciones sean distintas
        self.assertTrue(A != JA or B != JB)

        if A != 0 or B != 0:
            self.assertTrue(1 <= A <= N)
            self.assertTrue(1 <= B <= M)

        if JA != 0 or JB != 0:
            self.assertTrue(1 <= JA <= N)
            self.assertTrue(1 <= JB <= M)

        caseName = sys.argv[1]

        # Verificamos límites por cada subtarea
        if 'sub1' in caseName:
            self.assertTrue(3 <= N <= 10)
            self.assertTrue(3 <= M <= 10)
        elif 'sub2' in caseName:
            self.assertTrue(10 < N <= 1000)
            self.assertTrue(10 < M <= 1000)
        elif 'sub3' in caseName:
            self.assertTrue(1000 < N <= 100000)
            self.assertTrue(1000 < M <= 100000)
        else:
            self.fail(f'Invalidad test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
