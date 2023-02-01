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

        # En la primera línea un dos enteros a y b
        reg = re.compile(r'^[1-9]\d*$')
        self.assertTrue(reg.match(lines[0]), "input does not match regex")
        A, B = map(int, lines[0].split(' '))

        # Verificar limites
        self.assertTrue(1 <= A <= 1000, "A is not in range")
        self.assertTrue(1 <= B <= 1000, "B is not in range")


if __name__ == '__main__':
    validatortest.main()
