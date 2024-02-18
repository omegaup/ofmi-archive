import random
import os
import numpy as np

casos_por_subtarea = [6, 8, 6, 6, 12]


def generaCaso(caseName, subtarea, points, n, maxVal):
    A = []
    if subtarea != 4:
        for _ in range(n):
            x = random.randint(1, maxVal)
            A.append(x)
    else:
        A = np.full(n, 1)

    T = [*range(n)]

    if subtarea != 3:
        random.shuffle(T)

    with open(os.path.join('cases', caseName + '.in'), "w") as f:
        f.write(str(n) + '\n')
        f.write((' '.join([str(x) for x in A])) + '\n')
        f.write((' '.join([str(x) for x in T])) + '\n')

    # Empty .out
    open(os.path.join('cases', caseName + '.out'), "w").close()

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


# This helper function will generate a number that is linearly increasing
# with the case number. This is useful to make cases bigger as the case_number
def linear_incremental(subtarea, case_number, min_number, max_number):
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    # pendiente * casos_subtarea = max_number
    pendiente = (max_number - min_number) // casos_subtarea
    return min_number + pendiente * (case_number + 1)


def main():
    random.seed(974805103)
    with open('testplan', "w") as testplan:
        testplan.write("sub1.sample 0\n")

    maxVal = 1000000000

    # Subtarea 1 (15 puntos, n <= 100), valores chiquitos
    for i in range(3):
        puntos = 15 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            1,
            puntos,
            linear_incremental(1, i, 0, 100),
            int(100))

    # Subtarea 1, valores sin restricciones
    for i in range(3, 6):
        generaCaso(
            "sub1.{}".format(i),
            1,
            0,
            linear_incremental(1, i, 0, 100),
            maxVal)

    # Subtarea 2 (30 puntos, n <= 5000)
    for i in range(8):
        puntos = 30 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            2,
            puntos,
            linear_incremental(2, i, 100, 5000),
            maxVal)

    # Subtarea 3 (15 puntos, las persnas se lanzan de izquierda a derecha)
    for i in range(6):
        puntos = 15 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            3,
            puntos,
            linear_incremental(3, i, 0, 300000),
            maxVal)

    # Subtarea 4 (15 puntos, todas las personas tienen un 1)
    for i in range(6):
        puntos = 15 if i == 0 else 0
        generaCaso(
            "sub4.{}".format(i),
            4,
            puntos,
            linear_incremental(4, i, 0, 300000),
            maxVal)

    # Subtarea 5 (25 puntos, n <= 3 * 10^5)
    for i in range(12):
        puntos = 25 if i == 0 else 0
        generaCaso(
            "sub5.{}".format(i),
            5,
            puntos,
            linear_incremental(5, i, 10000, 300000),
            maxVal)


if __name__ == "__main__":
    main()
