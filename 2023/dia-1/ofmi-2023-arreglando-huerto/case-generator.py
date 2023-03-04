import random
import os


def policy1(n, b, m):
    # sum(A) = sum(B)
    for _ in range(int(n * 3)):
        i = random.randint(0, n-1)
        x = random.randint(0, b[i])
        j = i+1 if i == 0 else (
            i-1 if i == n-1 else random.choice([i-1, i+1]))
        while b[j]+x > m:
            i = random.randint(0, n-1)
            x = random.randint(0, b[i])
            j = i+1 if i == 0 else (
                i-1 if i == n-1 else random.choice([i-1, i+1]))
        b[i] -= x
        b[j] += x


def policy2(n, b, m):
    for i in range(n):
        x = random.randint(0, b[i])
        j = random.randint(0, n-1)
        while b[j]+x > m:
            j = random.randint(0, n-1)
        b[i] = b[i] - x
        b[j] = b[j] + x
    random.shuffle(b)


def generaCaso(caseName, points, maxN, sub1, possible):
    n = random.randint(1, maxN)
    summ = n * random.randint(10000, 100000)
    m = int(10**5)
    vals = range(0, m)
    a = []
    for _ in range(n):
        x = random.randint(0, min(m, summ))
        a.append(x)
        summ = summ - x
    random.shuffle(a)
    b = a.copy()

    if random.choice([True, False]):
        policy1(n, b, m)
    else:
        policy2(n, b, m)

    if not possible:
        suma = sum(a)
        b = random.choices(vals, k=n)
        while suma == sum(b):
            b[0] = random.choice(vals)

    if sub1:
        # A es no creciente
        # B es no decreciente
        a.sort(reverse=True)
        b.sort()

    with open(os.path.join('cases', caseName + '.in'), "w") as f:
        f.write(str(n) + '\n')
        f.write((' '.join([str(x) for x in a])) + '\n')
        f.write((' '.join([str(x) for x in b])) + '\n')

    # Empty .out
    open(os.path.join('cases', caseName + '.out'), "w").close()

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


def main():
    random.seed(984107431)
    with open('testplan', "w") as testplan:
        testplan.write("sample.sub2 0\n")

    # Subtarea 1 (18 puntos, A >, B <, 10^4)
    for i in range(6):
        puntos = 18 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            int(10000),
            True,
            True)

    # Subtarea 2 (37 puntos, 10^3)
    for i in range(10):
        puntos = 37 if i == 0 else 0
        possible = i >= 2
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            1000,
            False,
            possible)

    # Subtarea 3 (45 puntos, 10^4)
    for i in range(15):
        puntos = 45 if i == 0 else 0
        possible = i >= 3
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            int(10000),
            False,
            possible)


if __name__ == "__main__":
    main()
