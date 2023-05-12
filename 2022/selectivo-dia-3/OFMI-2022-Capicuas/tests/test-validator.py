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
        self.assertEqual(len(lines), 1, "input should only have one line")

        reg = re.compile(r'^([1-9]\d* [1-9]\d*)$')
        self.assertTrue(reg.match(lines[0]), "first line not match regex")
        A, B = [int(x) for x in lines[0].split(' ')]

        # Asegurar subtareas
        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(1 <= A <= B <= 1000,
                            "limits are wrong for first subtask")
        elif "sub2" in caseName:
            self.assertTrue(1 <= A <= B <= 10**6,
                            "limits are wrong for second subtask")
        elif "sub3" in caseName:
            self.assertTrue(1 <= A <= B <= 10**12,
                            "limits are wrong for third subtask")
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
