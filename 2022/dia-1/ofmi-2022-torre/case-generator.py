import random
import os

baseString = """
{n} {m}
{i_juanito} {j_juanito}
{i_tapia} {j_tapia}
""".strip(" \t\n\r")


def generaCaso(caseName, points, n, m):
    i_juanito = random.randint(1, n)
    j_juanito = random.randint(1, m)
    i_tapia = random.randint(1, n)
    j_tapia = random.randint(1, m)

    while (i_tapia == i_juanito and j_tapia == j_juanito):
        i_tapia = random.randint(1, n)
        j_tapia = random.randint(1, m)

    if random.choices([0, 1], weights=(85, 15))[0] == 1:
        if random.choice([0, 1]) == 0:
            i_juanito = j_juanito = 0
        else:
            i_tapia = j_tapia = 0

    case = {
        'n': n,
        'm': m,
        'i_juanito': i_juanito,
        'j_juanito': j_juanito,
        'i_tapia': i_tapia,
        'j_tapia': j_tapia,
    }
    caseString = baseString.format(**case)
    casePath = os.path.join('cases', caseName + ".in")
    with open(casePath, 'w') as f:
        f.write(caseString + "\n")

    # Create empty .out
    open(os.path.join('cases', caseName + '.out'), 'w').close()

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


with open('testplan', "w") as testplan:
    testplan.write("example.sub1 0\n")

random.seed(1553998939)

# Subtarea 1
for i in range(10):
    min_sz = 3
    max_sz = 10
    puntos = 20 if i == 0 else 0
    generaCaso(
        "sub1.{}".format(i),
        puntos,
        random.randint(min_sz, max_sz),
        random.randint(min_sz, max_sz),
    )

# Subtarea 2
for i in range(20):
    min_sz = 11
    max_sz = 1000
    puntos = 40 if i == 0 else 0
    generaCaso(
        "sub2.{}".format(i),
        puntos,
        random.randint(min_sz, max_sz),
        random.randint(min_sz, max_sz),
    )

random.seed(1553998937)
# Subtarea 3
for i in range(20):
    min_sz = 1001
    if i // 15 == 0:
        max_sz = 10000
    else:
        min_sz = 10000
        max_sz = 100000
    puntos = 40 if i == 0 else 0
    generaCaso(
        "sub3.{}".format(i),
        puntos,
        random.randint(min_sz, max_sz),
        random.randint(min_sz, max_sz),
    )
