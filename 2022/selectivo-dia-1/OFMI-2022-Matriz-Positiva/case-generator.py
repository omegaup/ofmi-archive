import random
import os

baseString = """
{n} {m}
{matriz}
""".strip(" \t\n\r")


def generaCaso(caseName, points, n, m):
    mat = [[random.randint(-100, 100) for _ in range(m)] for _ in range(n)]

    case = {
        'n': n,
        'm': m,
        'matriz': "\n".join(
            [" ".join([str(x) for x in line]) for line in mat]),
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, "w+") as f:
        f.write(caseString+'\n')

    # Empty .out
    open(os.path.join('cases', caseName + '.out'), "w+").close()

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


if __name__ == "__main__":
    random.seed(132423532534)

    with open('testplan', "w") as testplan:
        testplan.write("")

    # Subtarea 1
    for i in range(10):
        puntos = 10 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            n=1,
            m=random.randint(1, 100))

    with open('testplan', "a") as testplan:
        testplan.write("sub2.sample 0\n")

    # Subtarea 2
    for i in range(10):
        puntos = 30 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            n=random.randint(1, 10),
            m=random.randint(1, 10))

    # Subtarea 3
    for i in range(10):
        puntos = 40 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            n=random.randint(1, 99),
            m=random.randint(1, 99))

    # Subtarea 4
    for i in range(10):
        puntos = 20 if i == 0 else 0
        generaCaso(
            "sub4.{}".format(i),
            puntos,
            n=100,
            m=100)
