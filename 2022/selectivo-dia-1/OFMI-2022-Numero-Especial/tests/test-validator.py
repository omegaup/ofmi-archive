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

        reg = re.compile(r'^(\d+ \d+ \d+)$')
        self.assertTrue(reg.match(lines[0]), "first line not match regex")
        nums = [int(x) for x in lines[0].split(' ')]
        self.assertTrue(all(x > 0 for x in nums),
                        "numbers should be greater than 0")
        self.assertTrue(nums[2] > 1, "k should be greater than 1")

        # Asegurar subtareas
        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(all(1 <= x < 100 for x in nums),
                            "values are wrong for first subtask")
        elif "sub2" in caseName:
            self.assertTrue(nums[1] == 1,
                            "values are wrong for second subtask")
        elif "sub3" in caseName:
            self.assertTrue(all(x <= 10**15 for x in nums),
                            "values are wrong for third subtask")
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
