#!/usr/bin/python
# -*- coding: utf-8 -*-
import re
import sys
import unittest

from omegaup.validator import validatortest


def isPrime(k):
    if k == 1:
        return False
    for i in range(2, k):
        if k % i == 0:
            return False
    return True


class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '', "unexpected trailing characters")
        lines.pop()

        # Verificar el número de líneas
        self.assertEqual(len(lines), 2, "input should only have two lines")

        reg = re.compile(r'^(\d+ \d+)$')
        self.assertTrue(reg.match(lines[0]), "first line not match regex")
        K, N = [int(x) for x in lines[0].split(' ')]
        self.assertTrue(N <= K,
                        "it is not possible to put so many holes before"
                        " the goal")

        regd = re.compile(r'^\d+$')
        self.assertTrue(all(regd.match(possibleNumber)
                            for possibleNumber in lines[1].split(' ')),
                        "there is a not number in second line")
        array = [int(x) for x in lines[1].split(' ')]

        # Verificar propiedades del arreglo
        self.assertEqual(len(array), N,
                         "different number of holes than expected")
        self.assertTrue(all(1 <= hole <= K for hole in array),
                        "exists at least one hole that is out of the limits")
        self.assertEqual(len(array), len(set(array)),
                         "All elements should be unique in array")

        # Asegurar subtareas
        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertTrue(N == K-1,
                            "limits are wrong for first subtask")
            self.assertTrue(K <= 10**3,
                            "limits are wrong for first subtask")
            self.assertTrue(isPrime(K+1), "k+1 should be prime")
        elif "sub2" in caseName:
            self.assertTrue(N <= min(K, 10**5),
                            "limits are wrong for second subtask")
            self.assertTrue(K <= 10**5,
                            "limits are wrong for second subtask")
        elif "sub3" in caseName:
            self.assertTrue(N <= min(K, 10**5),
                            "limits are wrong for third subtask")
            self.assertTrue(K <= 10**9,
                            "limits are wrong for third subtask")
        else:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
