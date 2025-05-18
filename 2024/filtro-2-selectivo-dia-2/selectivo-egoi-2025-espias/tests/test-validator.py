import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.strip().split("\n")
        self.assertEqual(len(lines), 2, "unexpected number of lines")

        # En la primera linea un entero `n`
        reg = re.compile(r"^(\d+)$")
        self.assertTrue(reg.match(lines[0]), "invalid first line")

        # 2 <= n <= 10^6
        n = int(lines[0])
        self.assertTrue(2 <= n <= 10**6, "n out of range")

        # En la siguiente linea, `n` enteros `u_i`
        reg = re.compile(f"^(\\d+)( \\d+){{{n - 1}}}$")
        self.assertTrue(reg.match(lines[1]), "invalid second line")

        edges = [int(edge) for edge in lines[1].split(" ")]

        # 1 <= u_i <= n
        self.assertTrue(
            all(1 <= u <= n for u in edges),
            "u_i out of range"
        )

        # Un espia no se espia a si mismo
        for i in range(n):
            self.assertNotEqual(edges[i], i + 1, "invalid edge")

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # La `i`-esima espia tiene como objetivo a la espia `1` o `i + 1`
            self.assertEqual(edges[0], 2, "invalid edge")
            self.assertTrue(
                all((edges[i] == 1 or edges[i] == i + 2)
                    for i in range(1, n - 1)),
                "invalid edge"
            )
            self.assertEqual(edges[n - 1], 1, "invalid edge")
        elif 'sub2' in caseName:
            node_count = 0
            appear = [False for i in range(n)]

            # Toda espia es seguida exactamente por una espia
            for edge in edges:
                if not appear[edge - 1]:
                    appear[edge - 1] = True
                    node_count += 1

            self.assertEqual(node_count, n, "each node must appear once")
        elif 'sub3' in caseName:
            pass
        else:
            self.fail(f"invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
