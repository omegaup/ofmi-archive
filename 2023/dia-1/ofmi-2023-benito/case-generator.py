import os
import random
from typing import List


def printCase(caseName: str, matrix: List[List[int]]) -> None:
    file = os.path.join("cases", caseName + ".in")
    with open(file, 'w') as testplan:
        n = len(matrix)
        testplan.write(f"{n}\n")
        for row in matrix:
            testplan.write(' '.join(map(str, row)))
            testplan.write('\n')


def makeSpiralMatrix(n: int = None, outsideIn: bool = None) -> List[List[int]]:
    if n is None:
        n = 2 * random.randint(1, 400) - 1
    if outsideIn is None:
        outsideIn = random.choice([True, False])
    max_value = (n + 1) // 2

    matrix = [[0 for _ in range(n)] for _ in range(n)]
    for k in range(max_value):
        x = k + 1 if outsideIn else max_value - k
        for i in range(k, n - k):
            matrix[k][i] = x
            matrix[i][k] = x
            matrix[n - k - 1][i] = x
            matrix[i][n - k - 1] = x

    return matrix


def makeRandomMatrix(n: int = None) -> List[List[int]]:
    if n is None:
        n = 2 * random.randint(1, 400) - 1
    max_value = (n + 1) // 2
    return [[random.randint(1, max_value) for _ in range(n)] for _ in range(n)]


def main():
    # Samples
    with open("testplan", "w") as testplan:
        testplan.write("0.sample 0\n")
        testplan.write("0.sample1 0\n")
        testplan.write("0.sample2 0\n")

    # Subtarea 1. 1 <= n <= 3
    printCase("1.sub1", [[1]])
    printCase("2.sub1.espiral", makeSpiralMatrix(3, True))
    printCase("2.sub1.noespiral", makeRandomMatrix(3))
    printCase("3.sub1.espiral", makeSpiralMatrix(3, False))
    printCase("3.sub1.noespiral", makeRandomMatrix(3))
    with open("testplan", "a") as testplan:
        testplan.write("1.sub1 2\n")
        testplan.write("2.sub1.espiral 4\n")
        testplan.write("2.sub1.noespiral 0\n")
        testplan.write("3.sub1.espiral 4\n")
        testplan.write("3.sub1.noespiral 0\n")

    # Subtarea 2. Se te asegura que la matriz siempre es espiral.
    c = 4
    for _ in range(5):
        printCase(f"{c}.sub2", makeSpiralMatrix())
        # Append to testplan
        with open("testplan", "a") as testplan:
            testplan.write(f"{c}.sub2 2\n")
        c += 1

    # Subtarea 3. Solo habrán matrices no espirales y espirales de afuera hacia
    # adentro
    for _ in range(4):
        printCase(f"{c}.sub3.espiral", makeSpiralMatrix(outsideIn=True))
        printCase(f"{c}.sub3.noespiral", makeRandomMatrix())
        # Append to testplan
        with open("testplan", "a") as testplan:
            testplan.write(f"{c}.sub3.espiral 5\n")
            testplan.write(f"{c}.sub3.noespiral 0\n")
        c += 1

    # Subtarea 4. Solo habrán matrices no espirales y espirales de adentro
    # hacia afuera
    for _ in range(4):
        printCase(f"{c}.sub4.espiral", makeSpiralMatrix(outsideIn=False))
        printCase(f"{c}.sub4.noespiral", makeRandomMatrix())
        with open("testplan", "a") as testplan:
            testplan.write(f"{c}.sub4.espiral 5\n")
            testplan.write(f"{c}.sub4.noespiral 0\n")
        c += 1

    # Subtarea 5. Sin consideraciones adicionales.
    for _ in range(4):
        printCase(f"{c}.sub5.espiral", makeSpiralMatrix())
        printCase(f"{c}.sub5.noespiral", makeRandomMatrix())
        with open("testplan", "a") as testplan:
            testplan.write(f"{c}.sub5.espiral 10\n")
            testplan.write(f"{c}.sub5.noespiral 0\n")
        c += 1


if __name__ == '__main__':
    main()
