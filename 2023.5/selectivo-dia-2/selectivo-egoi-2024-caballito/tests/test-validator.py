import re
import sys
import unittest
from omegaup.validator import validatortest


def is_connected(adj, N):
    stack = []
    vis = {}

    # Perform DFS starting from node 1 and check that all nodes are visited
    stack.append(1)
    count = 0
    vis[1] = True
    while stack:
        curr = stack.pop()
        count = count + 1

        for neighbour in adj[curr]:
            if neighbour not in vis:
                stack.append(neighbour)
                vis[neighbour] = True

    return count == N


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea dos enteros, N y M.
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "invalid first line")
        N, M = map(int, lines[0].split())

        # En la segunda línea tres enteros, X, Y y Z.
        reg = re.compile(r"^(\d+) (\d+) (\d+)$")
        self.assertTrue(reg.match(lines[1]), "invalid second line")
        energies = list(map(int, lines[1].split()))

        # En las siguientes M líneas, dos enteros a,b.
        edges = lines[2:]
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertEqual(len(edges), M, "invalid edge count")

        self.assertTrue(
            all(reg.match(edge) for edge in edges),
            "invalid edge line",
        )

        E = [list(map(int, edge.split())) for edge in edges]
        A = [e[0] for e in E]
        B = [e[1] for e in E]

        # $2 \leq N \leq 10^5$.
        # $1 \leq M \leq 2 * 10^5$.
        # $1 \leq X, Y, Z, \leq 10^5$.
        # $1 \leq u_i, v_i \leq N$.
        max_n = 10**5
        max_m = 2 * 10**5
        max_energy = 10**5

        self.assertTrue(2 <= N <= max_n, "N out of range")
        self.assertTrue(1 <= M <= max_m, "M out of range")
        self.assertTrue(
            all(1 <= e <= max_energy for e in energies),
            "energies out of range"
        )

        # $1 \leq a_i, b_i \leq N$
        self.assertTrue(
            all(1 <= a <= N for a in A),
            "a_i out of range"
        )
        self.assertTrue(
            all(1 <= b <= N for b in B),
            "b_i out of range"
        )

        # No hay aristas repetidas
        edges = {(min(a, b), max(b, a)) for a, b in zip(A, B)}
        self.assertTrue(len(edges) == M, "repeated edges")

        # El grafo es conexo
        adj = {node: [] for node in range(1, N + 1)}
        for a, b in zip(A, B):
            adj[a] += [b]
            adj[b] += [a]

        if not is_connected(adj, N):
            self.fail("graph is not connected")

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # Cada nodo tiene a lo más dos aristas,
            self.assertTrue(
                all(len(adj[node]) <= 2 for node in range(1, N + 1)),
                "nodes should have at most 2 edges"
            )
            # excepto N, que tendrá solo una arista
            self.assertTrue(len(adj[N]) == 1, "node N should have only 1 edge")
        elif 'sub2' in caseName:
            # $N \leq 1000$
            self.assertTrue(1 <= N <= 1000, "n out of range for sub2")
        elif 'sub3' in caseName:
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
