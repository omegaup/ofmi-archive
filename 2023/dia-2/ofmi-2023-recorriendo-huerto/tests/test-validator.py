#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '', "unexpected trailing characters")
        lines.pop()

        # En la primera línea un entero N, el número de eventos
        reg = re.compile(r'^[1-9]\d*$')
        self.assertTrue(reg.match(lines[0]), "input does not match regex")
        N = int(lines[0])

        # Verificar que el número de eventos sea N
        lines = lines[1:]
        self.assertEqual(len(lines), N, "input should have N events")

        curr = 0  # Posición actual
        atras_calls = 0
        vueltas_calls = 0
        avanzado_calls = 0
        last_event = -1
        adelante_after_atras = False
        for line in lines:
            # Validar que sea un evento válido
            reg = re.compile(r'^([1-2] \d+)|[3-4]$')
            self.assertTrue(reg.match(line), "input does not match regex")
            v = line.split(' ')
            if v[0] == '1':
                x = int(v[1])
                curr += x
                if atras_calls > 0:
                    adelante_after_atras = True
            elif v[0] == '2':
                x = int(v[1])
                curr -= x
                atras_calls += 1
                if curr < 0:
                    self.fail("cannot go down from 0")
            elif v[0] == '3':
                avanzado_calls += 1
            else:
                vueltas_calls += 1
            last_event = int(v[0])

        caseName = sys.argv[1]
        if "sub1" in caseName:
            self.assertEqual(atras_calls, 0, "cannot go back in subtask 1")
        elif "sub2" in caseName:
            self.assertEqual(
                avanzado_calls,
                1,
                "avanzado should be called once in subtask 2")
            self.assertEqual(
                last_event, 3, "last event should be avanzado in subtask 2")
            self.assertEqual(
                vueltas_calls,
                0,
                "cannot call vueltas in subtask 2")
        elif "sub3" in caseName:
            self.assertFalse(adelante_after_atras,
                             "cannot go forward after going back in subtask 3")
        elif "sub4" not in caseName:
            self.fail(f'Invalidad test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
