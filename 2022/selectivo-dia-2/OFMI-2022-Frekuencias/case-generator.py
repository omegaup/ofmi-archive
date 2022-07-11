import random
import os
import string


def generaCaso(caseName, points, N, validChars):
    n = random.randint(1, N)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, "w+") as f:
        f.write(str(n) + '\n')
        sample = random.choices(validChars, k=n)
        f.write(''.join(sample) + '\n')

    # Empty .out
    open(os.path.join('cases', caseName + '.out'), "w+").close()

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


if __name__ == "__main__":
    with open('testplan', "w+") as testplan:
        testplan.write("sample.sub1 0\n")

    random.seed(10)

    # Subtarea 1
    for i in range(10):
        puntos = 25 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            N=99, validChars=list(string.ascii_lowercase)[:(i+1)*2])

    # Subtarea 2
    for i in range(10):
        puntos = 45 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            N=10**5, validChars=['a', 'b'])

    # Subtarea 3
    for i in range(10):
        puntos = 30 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            N=10**5, validChars=list(string.ascii_lowercase))
