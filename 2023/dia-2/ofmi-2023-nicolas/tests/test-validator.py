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
        self.assertEqual(lines[-1], '', "unexpected trailing characters")
        lines.pop()

        # En la primera línea dos enteros X y L
        reg = re.compile(r'^[1-9]\d* [1-9]\d*$')
        self.assertTrue(reg.match(lines[0]), "input does not match regex")
        X, L = map(int, lines[0].split())

        # Asegurar que estén en el rango correcto
        self.assertLessEqual(X, 10**3, "X is too large")
        self.assertLessEqual(L, 10**3, "L is too large")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            # L = 1
            self.assertEqual(L, 1, "L should be 1 for subtask 1")
        elif "sub2" in caseName:
            # X = 1
            self.assertEqual(X, 1, "X should be 1 for subtask 2")
        elif "sub3" not in caseName and "sub4" not in caseName:
            self.fail(f'Invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
