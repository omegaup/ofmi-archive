import re
import sys
import unittest
from omegaup.validator import validatortest


def match_n_integers(line: str, n: int):
    int_reg = re.compile(r"^\d+$")

    integers = []
    for token in line.split():
        if not int_reg.match(token):
            return None
        integers.append(int(token))

    if len(integers) != n:
        return None
    return integers


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            lines = handle.read().split("\n")

        self.assertEqual(lines[-1], "", "unexpected trailing characters")
        lines.pop()

        # En la primera línea un entero n
        self.assertTrue(re.match(r"^(\d+)$", lines[0]),
                        "Line 1: expected one integer")
        n = int(lines[0])

        # 1 <= n <= 2 * 10**5
        self.assertTrue(1 <= n <= 2 * 10**5, "1 <= n <= 2 * 10**5")

        # En la segunda línea vendrán n enteros
        T = match_n_integers(lines[1], n)
        self.assertTrue(T, "Line 2: expected n integers")

        # 1 <= T_i <= 10**9
        self.assertTrue(all(1 <= Ti <= 10**9 for Ti in T), "1 <= T_i <= 10**9")

        caseName = sys.argv[1]
        if "sub1." in caseName:
            self.assertTrue(all(1 <= Ti <= 3 for Ti in T),
                            "Sub1: 1 <= T_i <= 3")
        elif "sub2." in caseName:
            self.assertTrue(len(T) == len(set(T)),
                            "Sub2: all sizes T_i must be unique")
        elif "sub3." in caseName:
            self.assertTrue(all(1 <= Ti <= 10**6 for Ti in T),
                            "Sub3: 1 <= T_i <= 10**6")
        elif "sub4." in caseName:
            pass
        else:
            self.fail("Invalid subtask")


if __name__ == "__main__":
    validatortest.main()
