#!/usr/bin/python
# -*- coding: utf-8 -*-
import re
import sys
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '', "unexpected trailing characters")
        lines.pop()

        # Checar n, m
        reg = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(reg.match(lines[0]), "first line do not match regex")
        n, m = map(int, lines[0].split(' '))

        # Checar que hayan n líneas
        matriz = lines[1:]
        self.assertEqual(len(matriz), n, "matrix should contain n lines")
        for i in range(n):
            nums = [int(x) for x in matriz[i].split(' ')]
            self.assertEqual(
                len(nums), m, "line {} should contain m integers".format(i))
            self.assertTrue(all(-100 <= x <= 100 for x in nums),
                            "limits in line {} are wrong".format(i))

        # Asegurar subtareas
        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(n == 1 and 1 <= m <= 100,
                            "limits are wrong for first subtask")
        elif "sub2" in caseName:
            self.assertTrue(1 <= n <= 10 and 1 <= m <= 10,
                            "limits are wrong for second subtask")
        elif "sub3" in caseName:
            self.assertTrue(1 <= n <= 100 and 1 <= m <= 100,
                            "limits are wrong for third subtask")
        elif "sub4" in caseName:
            self.assertTrue(n == 100 and m == 100,
                            "limits are wrong for fourth subtask")
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
