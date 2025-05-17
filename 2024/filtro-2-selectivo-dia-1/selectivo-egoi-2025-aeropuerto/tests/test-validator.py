import re
import sys
import unittest
from typing import List
from omegaup.validator import validatortest


def match_m_edges(lines: List[str], m: int):
    if len(lines) != m + 1:
        return False

    tup_reg = re.compile(r"^(\d+) (\d+) (\d+)$")
    valid_edges = 0
    for i in range(1, m + 1):
        token = lines[i]
        if not tup_reg.fullmatch(token):
            return False
        lines[i] = tuple(map(int, token.split()))
        valid_edges += 1
    if not valid_edges == m:
        return False
    return True


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea, dos enteros n y m
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "Line 1: expected two integers")
        N, M = map(int, lines[0].split())

        # Límites generales
        self.assertTrue(2 <= N <= 10**4, "2 <= n <= 10**4")
        self.assertTrue(1 <= M <= 2 * 10**4, "1 <= m <= 2 * 10**4")

        # En la segunda línea vendrán M enteros
        self.assertTrue(match_m_edges(lines, M), "Lines 2+: expected m edges")

        # Límites U_i, V_i y X_i
        # Ningún nodo debe conectarse consigo mismo
        for Ui, Vi, Xi in lines[1:]:
            self.assertTrue(1 <= Ui <= N and 1 <= Vi <= N,
                            "1 <= U_i, V_i <= n")
            self.assertTrue(1 <= Xi <= 10, "1 <= X_i <= 10")
            self.assertNotEqual(Ui, Vi, "U_i != V_i")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(2 <= N <= 10, "Sub1: 2 <= n <= 10")
            self.assertTrue(1 <= M <= 50, "Sub1: 1 <= m <= 50")
        elif "sub2." in caseName:
            edges_per_node = [0] * N
            for Ui, Vi, *_ in lines[1:]:
                edges_per_node[Ui - 1] += 1
                edges_per_node[Vi - 1] += 1
            self.assertTrue(
                all(node_edges == 2 for node_edges in edges_per_node),
                "Sub2: Each node must have exactly two edges"
            )
        elif "sub3." in caseName:
            self.assertTrue(
                all(1 <= Xi <= 2 for *_, Xi in lines[1:]),
                "Sub3: 1 <= X_i <= 2"
            )
        elif "sub4." in caseName:
            pass
        else:
            self.fail("Invalid subtask")


if __name__ == "__main__":
    validatortest.main()
