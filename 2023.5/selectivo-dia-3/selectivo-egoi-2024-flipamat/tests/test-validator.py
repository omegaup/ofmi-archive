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

        # En la primera línea dos enteros n y m
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "invalid first line")
        n, m = map(int, lines[0].split())

        # En las siguientes n líneas, m caracteres 1, 0, o X
        mat = lines[1:]
        reg = re.compile(r"^[01X]*$")
        self.assertEqual(len(mat), n, "invalid row count")
        self.assertTrue(
            all(reg.match(row) for row in mat),
            "invalid characters",
        )
        self.assertTrue(
            all(len(row) == m for row in mat),
            "invalid column count",
        )

        # $1 \leq n, m \leq 300$
        self.assertTrue(1 <= n <= 300, "n out of range")
        self.assertTrue(1 <= m <= 300, "m out of range")

        caseName = sys.argv[1]
        if "sub1" in caseName:
            # $n, m \leq 10$
            self.assertTrue(n <= 10, "n out of range for subtask 1")
            self.assertTrue(m <= 10, "m out of range for subtask 1")
        elif "sub2" in caseName:
            # Hay a lo más tres 0s en la matriz
            self.assertTrue(
                sum(row.count("0") for row in mat) <= 3,
                "too many 0s for subtask 2",
            )
        elif "sub3" in caseName:
            # $n, m \leq 100$
            self.assertTrue(n <= 100, "n out of range for subtask 3")
            self.assertTrue(m <= 100, "m out of range for subtask 3")
        elif "sub4" in caseName:
            # Sin consideraciones adicionales
            pass
        else:
            self.fail(f"Invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
