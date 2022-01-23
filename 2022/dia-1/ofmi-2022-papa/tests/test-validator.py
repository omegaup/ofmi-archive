#!/usr/bin/python
# -*- coding: utf-8 -*-
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

        # Verificar el número de líneas
        self.assertEqual(len(lines), 1, "input should only have one line")

        # Verificar que sean 3 enteros separados por espacio
        # en el rango 1-3
        reg = re.compile(r'^[1-3] [1-3] [1-3]$')
        self.assertTrue(reg.match(lines[0]), "input does not match regex")


if __name__ == '__main__':
    validatortest.main()
