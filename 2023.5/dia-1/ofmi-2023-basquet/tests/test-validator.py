import re
import unittest
from omegaup.validator import validatortest


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.split("\n")
        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        self.assertTrue(len(lines) == 1, "Se esperaba una única línea")

        # Una única línea con 5 enteros
        reg = re.compile(r"^\d+ \d+ \d+ \d+ \d+$")
        self.assertTrue(reg.match(lines[0]), "Se esperaban 5 enteros")

        # Límites
        # $1 \leq Ai \leq 100$
        A = list(map(int, lines[0].split()))
        self.assertTrue(
            all(1 <= Ai <= 100 for Ai in A),
            "Se esperaba 1 <= Ai <= 100",
        )
        # Todos los números son distintos
        self.assertTrue(
            len(A) == len(set(A)),
            "Se esperaban números distintos",
        )


if __name__ == "__main__":
    validatortest.main()
