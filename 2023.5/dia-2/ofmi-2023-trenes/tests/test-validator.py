import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea hay dos enteros N y K
        reg = re.compile(r'^\d+ \d+$')
        self.assertTrue(reg.match(lines[0]), "Line 1: expected 2 integers")
        N, K = map(int, lines[0].split())

        # En la segunda línea N enteros positivos
        reg = re.compile(r'^\d+( \d+)*$')
        self.assertTrue(reg.match(lines[1]), "Line 2: expected N integers")
        T = list(map(int, lines[1].split()))
        self.assertTrue(len(T) == N, "Line 2: expected N integers")

        # En la tercera linea un entero Q
        reg = re.compile(r'^\d+$')
        self.assertTrue(reg.match(lines[2]), "Line 3: expected an integer")
        Q = int(lines[2])

        # En las siguientes Q lineas se describen las preguntas
        reg = re.compile(r'^(a|b) \d+ (N|S) \d+$')
        self.assertTrue(
            all(reg.match(line) for line in lines[3:]),
            "The query format is not correct",
        )
        P = [tuple(line.split(' ')) for line in lines[3:]]
        self.assertTrue(len(P) == Q, "Expected Q lines")

        # Checar los limites
        self.assertTrue(1 <= N <= 2*(10**5), "N out of bounds")
        self.assertTrue(1 <= K <= 10**9, "K out of bounds")
        self.assertTrue(all(1 <= t <= 10**9 for t in T), "t out of bounds")
        self.assertTrue(1 <= Q <= 10**5, "Q out of bounds")

        self.assertTrue(
            all(1 <= int(lst[1]) <= N for lst in P),
            "e expected to be in [1, N]",
        )
        self.assertTrue(
            all(0 <= int(p[3]) <= K for p in P),
            "d expected to be in [0, K]",
        )

        self.assertTrue(
            all(int(p[3]) > 0 for p in P
                if p[0] == "a"), "'a' query but d = 0"
        )

        # Subtareas
        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # Todas las queries son de tipo 'a'
            self.assertTrue(
                all(p[0] == "a" for p in P),
                "Expected only 'a' queries",
            )
        elif 'sub2' in caseName:
            # $n, k, Q \leq 100$
            # $T \leq 1000$
            self.assertTrue(N <= 100, "N out of bounds")
            self.assertTrue(K <= 100, "K out of bounds")
            self.assertTrue(Q <= 100, "Q out of bounds")
            self.assertTrue(sum(T) <= 1000, "T out of bounds")
        elif 'sub3' in caseName:
            # $n \leq 100$
            # $k, Q \leq 1000$
            # $T \leq 10^6$
            # $T / k \leq 1000$
            self.assertTrue(N <= 100, "N out of bounds")
            self.assertTrue(K <= 1000, "K out of bounds")
            self.assertTrue(Q <= 1000, "Q out of bounds")
            self.assertTrue(sum(T) <= 1000000, "T out of bounds")
            self.assertTrue(sum(T)/K <= 1000, "T/K out of bounds")
        elif 'sub4' in caseName:
            # $n \leq 10^6$
            # $k, Q \leq 1000$
            # $T \leq 10^6$
            # $T / k \leq 1000$
            self.assertTrue(K <= 1000, "K out of bounds")
            self.assertTrue(Q <= 1000, "Q out of bounds")
            self.assertTrue(sum(T) <= 1000000, "T out of bounds")
            self.assertTrue(sum(T)/K <= 1000, "T/K out of bounds")
        elif 'sub5' in caseName:
            # Sin consideraciones adicionales
            pass
        else:
            self.fail(f'Invalid subtask {caseName}')


if __name__ == '__main__':
    validatortest.main()
