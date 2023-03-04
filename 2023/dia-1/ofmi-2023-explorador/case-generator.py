import random
import os
import numpy as np

MAX = int(500)


def generaCaso(caseName, points, maxN, maxM, sub2):
    n = random.randint(1, maxN)
    m = random.randint(1, maxM)

    if not sub2 or random.randint(0, 1) == 0:
        world = [random.choices([0, 1, 2, 3], k=m) for _ in range(n)]
    else:
        # Make sure a path exists sometimes
        done = False
        while not done:
            done = True
            world = np.full((n, m), -1, dtype=int)
            i = n - 1
            j = 0
            while i > 1 or j < m - 1:
                a = 100
                b = 100
                c = 5
                d = 5
                if i == 0 or world[i - 1][j] != -1:
                    a = 0
                if j == m - 1 or world[i][j + 1] != -1:
                    b = 0
                if i == n - 1 or world[i + 1][j] != -1:
                    c = 0
                if j == 0 or world[i][j - 1] != -1:
                    d = 0
                if a == 0 and b == 0 and c == 0 and d == 0:
                    done = False
                    break
                pos = random.choices([0, 1, 2, 3], weights=(a, b, c, d))[0]
                world[i][j] = pos
                if pos == 0:
                    i -= 1
                if pos == 1:
                    j += 1
                if pos == 2:
                    i += 1
                if pos == 3:
                    j -= 1
            for i in range(n):
                for j in range(m):
                    if world[i][j] == -1:
                        world[i][j] = random.choice([0, 1, 2, 3])

    with open(os.path.join("cases", caseName + ".in"), "w") as f:
        f.write(str(n) + " " + str(m) + "\n")
        f.write(
            (
                "\n".join(
                    [(" ".join([str(x) for x in world[i]])) for i in range(n)]
                )
            )
            + "\n"
        )

    # Append to testplan
    with open("testplan", "a") as f:
        f.write(caseName + " " + str(points) + "\n")


def main():
    random.seed(132435397534)

    with open("testplan", "w") as testplan:
        testplan.write("sample0.sub3 0\n")
        testplan.write("sample1.sub3 0\n")

    caseNumber = 0

    # Subtarea 1
    puntos = 5
    for _ in range(5):
        generaCaso(f"sub1.{caseNumber}", puntos, 1, MAX, False)
        puntos = 0
        caseNumber += 1

    # Subtarea 2
    puntos = 10
    for _ in range(10):
        generaCaso(f"sub2.{caseNumber}", puntos, MAX, MAX, True)
        puntos = 0
        caseNumber += 1

    # Subtarea 3
    puntos = 5
    for _ in range(17):
        generaCaso(f"{caseNumber}.sub3", puntos, MAX, MAX, False)
        caseNumber += 1


if __name__ == "__main__":
    main()
