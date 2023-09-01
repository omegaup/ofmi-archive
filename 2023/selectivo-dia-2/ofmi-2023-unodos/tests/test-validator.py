import re
import sys
import unittest
from omegaup.validator import validatortest


def has_cycle(adj):
    # Initialize a stack for DFS
    stack = []
    # Dictionary to keep track of visited nodes
    visited = {}
    # Perform DFS for each node in the graph
    for node in adj:
        if node not in visited:
            # Start a new DFS from the current node
            stack.append((node, None))  # (current_node, parent_node)
            while stack:
                current_node, parent = stack.pop()
                if current_node in visited:
                    # If the current node is already visited, it forms a cycle
                    return True
                visited[current_node] = True
                # Add unvisited neighbors to the stack
                for neighbor in adj[current_node]:
                    if neighbor != parent:
                        stack.append((neighbor, current_node))
    # No cycle found
    return False


class Test(unittest.TestCase):
    def test(self):
        caseName = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(
            lines[-1], "", "Se esperaba un salto de línea al final del archivo"
        )
        lines.pop()

        # Verifica que la primera línea contenga dos enteros n y m
        regex = re.compile(r"^\d+ \d+$")
        self.assertTrue(
            regex.match(lines[0]),
            "Se esperaban dos enteros en la primera línea",
        )
        n, m = map(int, lines[0].split())

        # En cada una de las siguientes m lineas vendrán tres enteros
        self.assertTrue(len(lines[1:]) == m, f"Se esperaban {m} líneas")
        regex = re.compile(r"^\d+ \d+ \d+$")
        self.assertTrue(
            all(regex.match(line) for line in lines[1:]),
            f"Se esperaban tres enteros en las siguientes {m} líneas",
        )

        A = [list(map(int, line.split())) for line in lines[1:]]
        U = [a[0] for a in A]
        V = [a[1] for a in A]
        T = [a[2] for a in A]

        max_n = 10**5
        max_m = 2 * (10 ** 5)

        self.assertTrue(1 <= n <= max_n, "n está fuera de los límites")
        self.assertTrue(0 <= m <= max_m, "m está fuera de los límites")
        self.assertTrue(all(1 <= u <= n for u in U),
                        "algun U_i está fuera de los límites")
        self.assertTrue(all(1 <= v <= n for v in V),
                        "algun V_i está fuera de los límites")
        self.assertTrue(all(t in {1, 2} for t in T),
                        "algun T_i está fuera de los límites")

        aristas = {(min(u, v), max(u, v)) for u, v in zip(U, V)}
        self.assertTrue(len(aristas) == m, "Hay aristas repetidas")

        if 'sub1' in caseName:
            # $n \leq 5$
            self.assertTrue(n <= 5, "n debe ser menor o igual a 5")
            # $m \leq 14$
            self.assertTrue(m <= 14, "m debe ser menor o igual a 14")
        elif 'sub2' in caseName:
            # $T_i = 1$ para toda $0 \leq i \leq n-1$
            self.assertTrue(all(t == 1 for t in T),
                            "T debe ser 1 para todo i")
        elif 'sub3' in caseName:
            pass
        elif 'sub4' in caseName:
            # Cada vértice tendrá a lo más dos aristas incidentes.
            adj = {nodo: [] for nodo in range(1, n+1)}
            for u, v in zip(U, V):
                adj[u] += [v]
                adj[v] += [u]
            self.assertTrue(all(len(adj[nodo]) <= 2 for nodo in range(1, n+1)),
                            "Cada vértice debe tener a lo más" +
                            " dos aristas incidentes")
            # El grafo no tendrá ciclos.
            if has_cycle(adj):
                self.fail("El grafo no debe tener ciclos")
        elif 'sub5' in caseName:
            pass
        else:
            self.fail(f"Invalid case name: {caseName}")


if __name__ == "__main__":
    validatortest.main()
