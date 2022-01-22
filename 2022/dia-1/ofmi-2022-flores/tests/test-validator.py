#!/usr/bin/python
# -*- coding: utf-8 -*-

# no-self-use
# pylint: disable=R0201

import sys
import re
import unittest

from omegaup.validator import validatortest

MAX_N = 1000
NUM_SUBTAREAS = 3


class Test(unittest.TestCase):

    def parse_integers(self, _str, assert_size=None):
        self.assertEqual(type(_str), str)
        regex_integers = re.compile(r'^(-?\d+)( -?\d+)*$')
        self.assertTrue(regex_integers.match(_str))
        nums = list(map(int, _str.split(' ')))
        if assert_size is not None:
            self.assertEqual(len(nums), assert_size)
        return nums

    def parse_subtarea(self, case_name):
        for i in range(1, NUM_SUBTAREAS + 1):
            if "sub%d" % (i) in case_name:
                return i
        return None

    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        sub_tarea = self.parse_subtarea(sys.argv[1])
        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        # Validar N y M
        n, m = self.parse_integers(lines[0], 2)
        self.assertTrue(1 <= n <= MAX_N)
        self.assertTrue(0 <= m <= 1e5)

        if sub_tarea == 1:
            self.assertTrue(n <= 10)

        # Validar número de lineas
        self.assertEqual(len(lines), 2 * n + 3)

        # Validar coordenadas de entrada y salida
        entrada_x, entrada_y = self.parse_integers(lines[1], 2)
        salida_x, salida_y = self.parse_integers(lines[2], 2)

        if sub_tarea == 1:
            self.assertTrue((0 <= entrada_x <= 100),
                            "start coords out of bounds")
            self.assertTrue((0 <= entrada_y <= 100),
                            "start coords out of bounds")
            self.assertTrue((0 <= salida_x <= 100), "end coords out of bounds")
            self.assertTrue((0 <= salida_y <= 100), "end coords out of bounds")

        self.assertTrue((-1e5 <= entrada_x <= 1e5),
                        "normal start coords out of bounds")
        self.assertTrue((-1e5 <= entrada_y <= 1e5),
                        "normal start coords out of bounds")
        self.assertTrue((-1e5 <= salida_x <= 1e5),
                        "normal end coords out of bounds")
        self.assertTrue((-1e5 <= salida_y <= 1e5),
                        "normal end coords out of bounds")

        if sub_tarea == 2:
            self.assertEqual(entrada_y, 0)
            self.assertEqual(salida_y, 0)

        # Validar las N lineas de las coordenadas de cada tallo
        flower_coords = set()
        for line in lines[3:3+n]:
            x, y = self.parse_integers(line, 2)
            if sub_tarea == 1:
                self.assertTrue((0 <= x <= 100), "flower coords out of bounds")
                self.assertTrue((0 <= y <= 100), "flower coords out of bounds")
            self.assertTrue((-1e5 <= x <= 1e5),
                            "normal flower coords out of bounds")
            self.assertTrue((-1e5 <= y <= 1e5),
                            "normal flower coords out of bounds")
            flower = (x, y)
            self.assertTrue(flower not in flower_coords)
            flower_coords.add(flower)
            if sub_tarea == 2:
                self.assertEqual(y, 0)

        # Validar la longitud máxima de cada planta
        for line in lines[3+n:]:
            longitud_maxima = self.parse_integers(line, 1)[0]
            self.assertTrue(-1 <= longitud_maxima <= 200000)
            if sub_tarea == 3:
                self.assertEqual(longitud_maxima, -1)


if __name__ == '__main__':
    validatortest.main()
