#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import re
import unittest

from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        regex = re.compile(r'^(\d+)$')
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        lines = original_input.split('\n')
        self.assertEqual(lines[-1], '')
        lines.pop()

        self.assertTrue(regex.match(lines[0]))

        # Tener el número N, cantidad de palabras

        N = int(lines[0])
        self.assertTrue(1 <= N <= 1000)

        arr = lines[1].split(' ')

        self.assertEqual(len(lines), 2)

        # Asegurar que cada palabra tenga a lo más 10 letras y sean N palabras
        self.assertEqual(len(arr), N, "word count mismatch")
        self.assertTrue(all(
            1 <= len(v) <= 10
            for v in arr
        ))

        # Asegurar que las letras de cada palabra sean a-z
        self.assertTrue(all(v.isalpha() and v.islower() for v in arr),
                        "all words should be lowercase")

        # Verificar límites para subtareas

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            self.assertEqual(N, 1)

        elif 'sub2' in caseName:
            # Toda sílaba termina exactamente en una vocal
            vowels = "aeiou"
            k = 3
            for word in arr:
                # Separar cada palabra en sílabas
                sep = [word[i:i+k] for i in range(0, len(word), k)]
                # Revisamos la última posición de cada sílaba
                for sil in sep:
                    if len(sil) == 1:
                        self.assertTrue(
                            sil[-1] in vowels,
                            f'"{word}" does not have a vowel ' +
                            f'at the last position of the syllable "{sil}"')
                    else:
                        self.assertTrue(
                            sil[-1] in vowels and sil[-2] not in vowels,
                            f'"{word}" does not have a vowel ' +
                            f'at the last position of the syllable "{sil}"')

        elif 'sub3' in caseName:
            # Ninguna sílaba tiene dos vocales juntas
            vowels = "aeiou"
            k = 3
            for word in arr:
                # Separar cada palabra en sílabas
                sep = [word[i:i+k] for i in range(0, len(word), k)]
                # Revisamos cada sílaba
                for sil in sep:
                    self.assertFalse(
                        any(sil[i] in vowels and sil[i+1] in vowels
                            for i in range(len(sil)-1)),
                        f'"{word}" has two adjacent vowels ' +
                        f'in syllable "{sil}"')

        elif 'sub4' not in caseName:
            self.fail(f'invalid test name: {caseName}')


if __name__ == '__main__':
    validatortest.main()
