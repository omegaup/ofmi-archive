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

        # Verifica que solo existan 3 líneas de entrada
        len_lines = len(lines)
        self.assertEqual(
            len_lines,
            3,
            f"3 lines of input were expected, {len_lines} given")

        # En la primera línea un entero N, el número de eventos
        reg = re.compile(r'^[1-9]\d*$')
        self.assertTrue(
            reg.match(
                lines[0]),
            "[input does not match regex] "
            "An integer N was expected in the first line")
        N = int(lines[0])

        # Verifica que la segunda y tercer línea contenga N enteros.
        regex = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            regex.match(
                lines[1]),
            f"[input does not match regex] "
            f"{N} space-separated integers were expected without "
            f"space at the end")
        A = list(map(int, lines[1].split()))
        len_A = len(A)
        self.assertEqual(
            len_A, N, f"{N} integers were expected, {len_A} given")

        regex = re.compile(r"^\d+( \d+)*$")
        self.assertTrue(
            regex.match(
                lines[2]),
            f"[input does not match regex] "
            f"{N} space-separated integers were "
            f"expected without space at the end")
        B = list(map(int, lines[2].split()))
        len_B = len(B)
        self.assertEqual(
            len_B, N, f"{N} integers were expected, {len_B} given")

        # Verifica que todos los elementos sean no negativos
        self.assertGreaterEqual(
            min(A), 0, "All the elements of A should be non negative")
        self.assertGreaterEqual(
            min(B), 0, "All the elements of B should be non negative")

        # Verifica que todos los elementos sean a lo mas 10^5
        self.assertLessEqual(
            max(A), 1e5, "All the elements of A should be at most 10^5")
        self.assertLessEqual(
            max(B), 1e5, "All the elements of B should be at most 10^5")

        maxn = 1e4
        if "sub1" in caseName:
            # Subtarea 1:

            # siempre es posible
            self.assertEqual(
                sum(A),
                sum(B),
                "It should be possible to transform A into B")

            # A orden descendente y B ascendente
            # +[0] solo es en caso de N = 1, para que no haya problema
            # con la funcion min
            order_A = [A[i] - A[i + 1] for i in range(N - 1)] + [0]
            order_B = [B[i + 1] - B[i] for i in range(N - 1)] + [0]

            self.assertGreaterEqual(
                min(order_A), 0, "Array A should be non-increasing")
            self.assertGreaterEqual(
                min(order_B), 0, "Array B should be non-decreasing")

        elif "sub2" in caseName:
            # Subtarea 2: N <= 10^3
            maxn = 1e3
        elif "sub3" not in caseName:
            self.fail("Unknown case name")

        maxn = int(maxn)
        self.assertTrue(1 <= N <= maxn, f"N should be in range [1, {maxn}]")


if __name__ == '__main__':
    validatortest.main()
