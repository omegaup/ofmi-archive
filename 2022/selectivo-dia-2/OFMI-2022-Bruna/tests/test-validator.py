#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914
# too-many-statements
# pylint: disable=R0915

import sys
import re
import unittest
from collections import deque
from omegaup.validator import validatortest


class Test(unittest.TestCase):

    def test(self):
        case_name = sys.argv[1]
        if not any(f'sub{i}' in case_name for i in range(1, 7)):
            self.fail(f"Invalid case name: {case_name}")

        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        regex = re.compile(r'^(\d+) (\d+)$')
        self.assertTrue(regex.match(lines[0]))

        # Verificar tamaño de archivo

        lines[0] = lines[0].split(' ')
        n = int(lines[0][0])
        q = int(lines[0][1])

        self.assertEqual(len(lines), q + 2)

        # Definir limites

        lim_n = 1e5
        lim_q = 1e5
        lim_x = 1e9

        if 'sub1' in case_name:
            lim_x = 1
        elif 'sub3' in case_name:
            lim_n = 1e3
            lim_q = 1e3

        self.assertTrue(1 <= n <= lim_n)
        self.assertTrue(1 <= q <= lim_q)

        # Verificar que los números del arreglo cumplan los límites
        # y sean exactamente N números

        arr = lines[1].split(' ')

        ints = [int(v) for v in arr]

        self.assertEqual(len(ints), n)
        self.assertTrue(all(
            -1 <= v <= n
            for v in ints
        ))

        # Verificar que solo existe una raíz y ningún 0

        self.assertEqual(ints.count(+0), 0)
        self.assertEqual(ints.count(-1), 1)

        # Verificar que nadie sea su propio padre

        self.assertTrue(all(
            value != index + 1
            for index, value in enumerate(ints)
        ))

        # Verificar que sea un árbol
        self.assertTrue(isTree(ints))

        if 'sub5' in case_name:
            # Verificar que sea una linea
            self.assertEqual(len(set(ints)), len(ints))

        reg_query1 = re.compile(r'^(\d+) (\d+) (\d+)$')
        reg_query2 = re.compile(r'^(\d+) (\d+)$')

        count = 0
        flag = True
        for line in lines[2:]:
            count += 1
            if reg_query1.match(line):

                # Verificar que solo hay una query del tipo Update
                # y está al inicio en sub2
                if 'sub2' in case_name:
                    self.assertEqual(count, 1)

                # Verificar que solo hay una query del tipo Update al inicio
                if 'sub4' in case_name:
                    self.assertTrue(flag)

                arr = line.split(' ')
                self.assertEqual(int(arr[0]), 1)
                self.assertTrue(1 <= int(arr[1]) <= n)
                self.assertTrue(1 <= int(arr[2]) <= lim_x)

            elif reg_query2.match(line):

                # Verificar que solo hay una query del tipo Update
                # y está al inicio en sub2
                if 'sub2' in case_name:
                    self.assertGreater(count, 1)

                arr = line.split(' ')
                self.assertEqual(int(arr[0]), 2)
                self.assertTrue(1 <= int(arr[1]) <= n)

                flag = False

            else:
                self.fail(f"Invalid query type: {line}")


def isTree(ints):
    # Verificar que no existan ciclos y todos sean conexos
    n = len(ints)
    grado = [0] * (n + 1)
    adyacencias = [[] for _ in range(n + 1)]

    raiz = 0
    for index, value in enumerate(ints):
        if value == -1:
            raiz = index + 1
        else:
            adyacencias[value].append(index + 1)

    stack = deque()
    stack.append(raiz)
    while len(stack) != 0:
        nodo = stack.pop()
        grado[nodo] += 1
        for v in adyacencias[nodo]:
            stack.append(v)

    return grado.count(1) == n


if __name__ == '__main__':
    validatortest.main()
