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

        # Verificar el número de líneas
        self.assertEqual(len(lines), 2, "input should only have two lines")

        # Leer N, B, R y L
        regex_four_ints = re.compile(r'^(\d+) (\d+) (\d+) (\d+)$')
        self.assertTrue(
            regex_four_ints.match(
                lines[0]),
            "Se esperaban 4 enteros separados por espacios "
            "en la primera línea")
        N, B, R, L = map(int, lines[0].split(' '))

        # Límites
        self.assertTrue(1 <= N <= 100000, "N está fuera de los límites")
        self.assertTrue(0 <= B <= 100000, "B está fuera de los límites")
        self.assertTrue(0 <= R <= 100000, "R está fuera de los límites")
        self.assertTrue(0 <= L <= 1000, "L está fuera de los límites")

        # N enteros
        D = list(map(int, lines[1].split(' ')))

        self.assertEqual(
            len(D),
            N,
            f"Se esperaban {N} enteros separados por espacios "
            "en la segunda línea")

        self.assertTrue(all(
            0 <= x <= 1000
            for x in D
        ), "Alguna Di está fuera de los límites")

        # Verificar condiciones de subtareas
        caseName = sys.argv[1]

        if 'sub1' in caseName:
            # N = 1. L > Di para toda i
            self.assertEqual(N, 1)
            self.assertTrue(all(
                L > x
                for x in D
            ))

        elif 'sub2' in caseName:
            # L > Di para toda i
            self.assertTrue(all(
                L > x
                for x in D
            ))

        elif 'sub3' in caseName:
            # (B - R \gt \sum D_i)
            self.assertTrue((B - R) > sum(D))

        elif 'sub4' not in caseName:
            self.fail(f'Invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
