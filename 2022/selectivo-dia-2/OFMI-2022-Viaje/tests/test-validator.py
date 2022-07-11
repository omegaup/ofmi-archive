#!/usr/bin/python
# -*- coding: utf-8 -*-
import re
import sys
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        case_name = sys.argv[1]
        if not any(f'sub{i}' in case_name for i in range(1, 5)):
            self.fail(f"Invalid case name: {case_name}")

        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '', "unexpected trailing characters")
        lines.pop()

        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))
        N, M = map(int, lines[0].split(' '))
        # Verificar el número de líneas
        self.assertEqual(len(lines), N + 3,
                         "input should only have N + 3 lines")

        # Límites
        self.assertTrue(1 <= N <= 200)
        self.assertTrue(1 <= M <= 200)

        if "sub2" in case_name:
            self.assertTrue(
                1 <= N <= 5, "N limits is wrong for second subtask")
            self.assertTrue(
                1 <= M <= 5, "M limits is wrong for second subtask")

        # Checar de manera general
        matrix = [row.split(' ') for row in lines[1:N+1]]
        for row in matrix:
            self.assertEqual(len(row), M)
            self.assertTrue(all(
                0 <= int(element) < N*M or int(element) == -1
                for element in row
            ), "there is at least one value not allowed in the matrix")
        # Checar que sean unicos
        if any(subcase in case_name for subcase in ["sub1", "sub3"]):
            values = set()
            for row in matrix:
                for element in row:
                    value = int(element)
                    # Check -1
                    if value == -1:
                        self.assertTrue("sub1" not in case_name,
                                        "-1 in subtask1 subcase")
                        continue
                    # Check repetition
                    self.assertTrue(value not in values,
                                    "repeated values in sub1 or sub3")
                    values.add(value)

        self.assertTrue(regex.match(lines[N + 1]))
        r1, c1 = map(int, lines[N + 1].split(' '))
        self.assertTrue(0 <= r1 < N)
        self.assertTrue(0 <= c1 < M)

        self.assertTrue(regex.match(lines[N + 2]))
        r2, c2 = map(int, lines[N + 2].split(' '))
        self.assertTrue(0 <= r2 < N)
        self.assertTrue(0 <= c2 < M)


if __name__ == '__main__':
    validatortest.main()
