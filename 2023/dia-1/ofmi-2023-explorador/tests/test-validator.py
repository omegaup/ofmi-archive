import re
import sys
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        caseName = sys.argv[1]
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea dos enteros N y M
        reg = re.compile(r"^\d+ \d+$")
        self.assertTrue(
            reg.match(lines[0]),
            "[input does not match regex] Two integers "
            "N and M were expected in the first line",
        )
        N, M = [int(num) for num in lines[0].split(' ')]

        # Verifica que sigan N lineas
        len_lines = len(lines) - 1
        self.assertEqual(
            len_lines,
            N,
            f"{N} lines of input were expected, {len_lines} given",
        )

        # Verifica que cada una de las N lineas contenga M enteros
        reg = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            all([reg.match(line) for line in lines[0:-1]]),
            "[input does not match regex] space-separated integers "
            "were expected without space at the end",
        )
        mdo = [list(map(int, line.split())) for line in lines[1:-1]]
        self.assertTrue(
            all([len(row) == M for row in mdo]),
            f"{M} integers were expected per line",
        )

        # Verifica que cada entrada este en {0, 1, 2, 3}
        valid_set = {0, 1, 2, 3}
        self.assertTrue(
            all([value in valid_set for row in mdo for value in row]),
            "The elements of the matrix should be 0, 1, 2 or 3",
        )

        if "sub1" in caseName:
            self.assertEqual(N, 1, "The value of N should be 1 for subtask 1")

        # Rangos de N y M
        max_N = 500
        max_M = 500
        self.assertTrue(1 <= N <= max_N, f"N should be in range [1, {max_N}]")
        self.assertTrue(1 <= M <= max_M, f"M should be in range [1, {max_M}]")


if __name__ == "__main__":
    validatortest.main()
