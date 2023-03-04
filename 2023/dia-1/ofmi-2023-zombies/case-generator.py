import random
import os


def generaCaso(caseName, points, maxN, maxD, maxA):
    n = random.randint(1, maxN)
    d = random.randint(1, maxD)
    zombies = random.sample(range(1, maxA), n)

    with open(os.path.join('cases', caseName + '.in'), "w") as f:
        f.write(str(n) + ' '+str(d)+'\n')
        f.write((' '.join([str(x) for x in zombies])) + '\n')

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


def main():
    random.seed(123)

    with open('testplan', "w") as testplan:
        testplan.write("sample.sub3 0\n")

    caseNumber = 1
    # Subtarea 1
    for _ in range(5):
        puntos = 1
        generaCaso(f"{caseNumber}.sub1", puntos, int(10**5), 1, int(10**9))
        caseNumber += 1

    # Subtarea 2
    for _ in range(5):
        puntos = 1
        generaCaso(f"{caseNumber}.sub2", puntos, 1, int(10**9), int(10**9))
        caseNumber += 1

    # Subtarea 3
    for _ in range(10):
        puntos = 2
        generaCaso(f"{caseNumber}.sub3", puntos, 100, 100, 100)
        caseNumber += 1

    # Subtarea 4
    for _ in range(10):
        puntos = 7
        generaCaso(
            f"{caseNumber}.sub4", puntos, int(10**5), int(10**9), int(10**9)
        )
        caseNumber += 1


if __name__ == "__main__":
    main()
