#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914

import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(
            lines[-1], '',
            "Se esperaba un salto de línea al final del archivo")
        lines.pop()

        # Leer N y  M
        reg = re.compile(r"^\d+ \d+$")
        self.assertTrue(
            reg.match(lines[0]),
            "[input does not match regex] Two integers "
            "N and M were expected in the first line",
        )

        N, M = map(int, lines[0].split())

        # Verifica que sigan N lineas
        len_lines = len(lines) - 1
        self.assertEqual(
            len_lines,
            N,
            f"{N} lines of input were expected, {len_lines} given",
        )

        # Verifica que cada una de las N lineas contenga M enteros
        reg = re.compile(r"^-?\d+( -?\d+)*$")
        self.assertTrue(
            all([reg.match(line) for line in lines[1:]]),
            "[input does not match regex] space-separated integers "
            "were expected without space at the end",
        )
        mdo = [list(map(int, line.split())) for line in lines[1:]]
        self.assertTrue(
            all([len(row) == M for row in mdo]),
            f"{M} integers were expected per line",
        )

        # Verifica que cada elemento este en limite
        self.assertTrue(
            all([-1 <= value <= 1e6 for row in mdo for value in row]),
            "The elements of the matrix should be between -1 and 10^6",
        )

        # Verificar que solo haya un monton de lechuga

        self.assertEqual(
            len([value for row in mdo for value in row if value >= 2]), 1,
            "There should only be one lettuce"
        )

        # Límites
        self.assertTrue(2 <= N <= 1000, "N should be bewteen 2 and 1000")
        self.assertTrue(2 <= M <= 1000, "M should be bewteen 2 and 1000")

        # Verificar condiciones de subtareas
        caseName = sys.argv[1]

        if 'sub1' in caseName:
            # Verifica que cada elemento este en limite
            self.assertTrue(
                all([value > -1 for row in mdo for value in row]),
                "In task 1 should not be walls",)
        elif 'sub2' not in caseName:
            self.fail("Invalid case name")


if __name__ == '__main__':
    validatortest.main()
