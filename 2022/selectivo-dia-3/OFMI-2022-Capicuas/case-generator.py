import random
import os

baseString = """
{A} {B}
""".strip(" \t\n\r")


def generaCaso(caseName, points, maxN):
    if random.randint(0, 1):
        A = random.randint(1, maxN)
        B = random.randint(A, maxN)
    else:
        B = random.randint(1, maxN)
        A = random.randint(1, B)

    case = {
        'A': A,
        'B': B,
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


def main():
    random.seed(13243532534)

    with open('testplan', "w") as testplan:
        testplan.write("sub1.sample 0\n")

    # Subtarea 1
    for i in range(10):
        puntos = 10 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            maxN=int(10**3))

    # Subtarea 2
    for i in range(10):
        puntos = 30 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            maxN=int(10**6))

    # Subtarea 3
    for i in range(10):
        puntos = 60 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            maxN=int(10**12))


if __name__ == "__main__":
    main()
