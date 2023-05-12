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

        reg = re.compile(r'^[a-z]+$')
        self.assertTrue(reg.match(lines[0]), "first line not match regex")
        self.assertTrue(reg.match(lines[1]), "second line not match regex")
        n = len(lines[0])
        m = len(lines[1])

        # Asegurar subtareas
        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(1 <= n <= 10**5 and 1 <= m <= 10**5,
                            "limits are wrong for first subtask")
            self.assertTrue(all(c not in "pqbdsz" for c in lines[0]),
                            "first line should not contain pqbdsz")
        elif "sub2" in caseName:
            self.assertTrue(1 <= n <= 10 and 1 <= m <= 10,
                            "limits are wrong for second subtask")
        elif "sub3" in caseName:
            self.assertTrue(1 <= n <= 10**5 and 1 <= m <= 10**5,
                            "limits are wrong for third subtask")
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
