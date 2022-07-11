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

        # Verificar el número de líneas
        self.assertEqual(len(lines), 2, "input should only have two lines")

        reg = re.compile(r'^\d+$')
        self.assertTrue(reg.match(lines[0]), "first line not match regex")
        N = int(lines[0])

        reg = re.compile(r'^[a-z]+$')
        self.assertTrue(reg.match(lines[1]), "second line not match regex")
        S = lines[1]

        # Asegurar subtareas
        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(
                1 <= N < 100, "N outside of the limits for first subtask")
        elif "sub2" in caseName:
            self.assertTrue(1 <= N <= 100000,
                            "N outside of the limits for second subtask")
            self.assertTrue(
                all(z in "ab" for z in S),
                "Characters should only be a/b for second subtask"
            )
        elif "sub3" in caseName:
            self.assertTrue(1 <= N <= 100000,
                            "N outside of the limits for third subtask")
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
