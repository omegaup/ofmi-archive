import re
import sys
import unittest
from omegaup.validator import validatortest


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def fraction(num, den):
    div = gcd(num, den)
    return (num // div, den // div)


class Test(unittest.TestCase):
    def test(self):
        with open("data.in", "r") as handle:
            original_input = handle.read()

        lines = original_input.strip().split("\n")

        # En la primera linea dos enteros `n` y `m`
        reg = re.compile(r"^(\d+) (\d+)$")
        self.assertTrue(reg.match(lines[0]), "invalid first line")

        (n, m) = [int(number) for number in lines[0].split(" ")]

        # 2 <= n <= 10^5
        self.assertTrue(2 <= n <= 10**5, "n out of range")

        # 1 <= m <= 10^4
        self.assertTrue(1 <= m <= 10**4, "m out of range")

        # La entrada tiene `n + 1` lineas
        self.assertEqual(len(lines), n + 1, "unexpected number of lines")

        ships = []

        # Las siguientes `n` lineas, dos enteros `x_i` y `v_i`
        reg = re.compile(r"^(\d+) (\d+)$")
        for i in range(1, n + 1):
            self.assertTrue(reg.match(lines[i]), "invalid ship data")

            (x_i, v_i) = [int(number) for number in lines[i].split(" ")]

            # 0 <= x_i <= 10^9
            self.assertTrue(0 <= x_i <= 10**9, "x_i out of range")

            # 1 <= v_i <= 10^9
            self.assertTrue(1 <= v_i <= 10**9, "v_i out of range")

            ships.append((x_i, v_i))

        ships.sort(key=lambda ship: ship[0])

        # No hay dos naves en la misma posicion
        self.assertTrue(all((ships[i - 1][0] != ships[i][0])
                            for i in range(1, n)),
                        "two ships at the same starting position")

        if n <= 1000:
            passings = dict()
            for i in range(n - 1):
                for j in range(i + 1, n):
                    if ships[i][1] <= ships[j][1]:
                        # La nave `i` no podra rebasar a la nave `j`
                        continue

                    (x1, v1) = ships[i]
                    (x2, v2) = ships[j]

                    # Tiempo en el que `i` rebasa a `j`
                    t = fraction(x2 - x1, v1 - v2)

                    # Posicion donde `i` rebasa a `j`
                    x = fraction(x1 * (v1 - v2) + v1 * (x2 - x1), v1 - v2)

                    # Tres naves nunca se encontraran en la misma posicion
                    self.assertFalse((t, x) in passings,
                                     "three ships at the same position")

                    passings[(t, x)] = True

            # No se pediran mas cruces de los que existen
            self.assertLessEqual(m, len(passings), "m out of range")

        caseName = sys.argv[1]
        if 'sub1' in caseName:
            # m = 1
            self.assertEqual(m, 1, "m out of range")
        elif 'sub2' in caseName:
            # Todas las naves tienen la misma velocidad, excepto una
            max_count = 1
            speed_map = dict()

            for ship in ships:
                speed = ship[1]
                if speed in speed_map:
                    speed_map[speed] += 1
                else:
                    speed_map[speed] = 1
                max_count = max(max_count, speed_map[speed])

            self.assertEqual(max_count, n - 1,
                             "more than one ship with different speed")
        elif 'sub3' in caseName:
            # n <= 1,000
            self.assertLessEqual(n, 1000, "n out of range")
        elif 'sub4' in caseName:
            pass
        else:
            self.fail(f"invalid subtask {caseName}")


if __name__ == "__main__":
    validatortest.main()
