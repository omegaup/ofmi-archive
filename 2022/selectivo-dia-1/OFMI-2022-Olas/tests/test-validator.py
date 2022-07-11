#!/usr/bin/python
# -*- coding: utf-8 -*-
import re
import sys
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        case_name = sys.argv[1]
        if not any(f'sub{i}' in case_name for i in range(1, 3)):
            self.fail(f"Invalid case name: {case_name}")

        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '', "unexpected trailing characters")
        lines.pop()

        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))
        N, K = map(int, lines[0].split(' '))
        # Verificar el número de líneas
        self.assertEqual(len(lines), 2,
                         "input should only have 2 lines")

        self.assertTrue(1 <= K <= N,
                        "K limits is wrong for first subtask")

        # Límites
        if "sub1" in case_name:
            self.assertTrue(1 <= N <= 20,
                            "N limits is wrong for first subtask")
        else:
            self.assertTrue(1 <= N <= 100,
                            "N limits is wrong for second subtask")

        array = [int(x) for x in lines[1].split()]

        self.assertEqual(len(array), N, "Len(Array) different of N")
        self.assertTrue(
            all(-10**9 <= value <= 10**9 for value in array),
            "A_i limits is wrong")


if __name__ == '__main__':
    validatortest.main()
