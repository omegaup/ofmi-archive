import random
import os

baseString = """
{n} {m} {k}
""".strip(" \t\n\r")


def generaCaso(caseName, points, N, M, K):
    n = random.randint(1, N)
    m = random.randint(1, M)
    k = random.randint(1, K)

    case = {'n': n, 'm': m, 'k': k}
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
    with open('testplan', "w+") as testplan:
        testplan.write("sub1.sample 0\n")

    random.seed(10)

    # Subtarea 1
    for i in range(10):
        puntos = 20 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            N=99, M=99, K=99)

    # Subtarea 2
    for i in range(10):
        puntos = 40 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            N=10**15, M=1, K=10**(i//2+1))

    # Subtarea 3
    for i in range(10):
        puntos = 40 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            N=10**15, M=10**15, K=10**(i//2+1))
