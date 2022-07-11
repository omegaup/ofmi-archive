import random
import os


def generaCaso(caseName, points, N, lim):
    n = random.randint(1, N)
    k = random.randint(1, n)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, "w+") as f:
        f.write(f'{n} {k}\n')
        sample = [str(random.randrange(-lim, lim))
                  for _ in range(n)]
        f.write(' '.join(sample) + '\n')

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
    for i in range(17):
        puntos = 35 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            N=20, lim=10**(i//2 + 1))

    # Subtarea 2
    for i in range(17):
        puntos = 65 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            N=100, lim=10**(i//2 + 1))
