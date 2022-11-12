#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914
# too-many-statements
# pylint: disable=R0915

import sys
import re
import unittest
from collections import deque
from omegaup.validator import validatortest


class Test(unittest.TestCase):

    def test(self):
        case_name = sys.argv[1]
        if not any(f'sub{i}' in case_name for i in range(1, 6)):
            self.fail(f"Invalid case name: {case_name}")

        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))

        # Verificar tamaño de archivo

        lines[0] = lines[0].split(' ')
        n = int(lines[0][0])
        k = int(lines[0][1])

        self.assertEqual(len(lines), k + 1)

        # Definir limites

        lim_n = 35
        lim_k = lim_n + 1

        if 'sub1' in case_name:
            lim_n = 4
        elif 'sub2' in case_name:
            lim_n = 10
        elif 'sub3' in case_name:
            lim_n = 25
        elif 'sub4' in case_name:
            lim_k = 0

        self.assertTrue(1 <= n <= lim_n)
        self.assertTrue(0 <= k <= lim_k)

        regex2 = re.compile(r'^(\d+) (\d+)$')
        for line in lines[1:]:
            self.assertTrue(regex2.match(line))
            arr = line.split(' ')
            self.assertTrue(1 <= int(arr[0]) <= n and 1 <= int(arr[1]) <= n)

if __name__ == '__main__':
    validatortest.main()
