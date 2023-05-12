import random
import os
import math

baseString = """
{s}
{piezas}
""".strip(" \t\n\r")


def generaCaso(caseName, points, maxN):
    lowerBound = random.randint(1, int(math.ceil(math.sqrt(maxN))))
    if random.randint(0, 1) == 0 and maxN > 10:
        lowerBound *= random.randint(1, int(math.sqrt(maxN)))
    n = random.randint(1, maxN // lowerBound)
    # Use only those to get more density on special characters
    availableLetters = "pdszdbacfhgiuo"
    s = "".join(random.choices(availableLetters, k=n))

    m = n + random.randint(0, maxN - n)
    piezas = s * lowerBound
    piezas += "".join(random.choices(availableLetters, k=m-len(piezas)))

    if "sub1" in caseName:
        for c in "pdszdb":
            s = s.replace(c, random.choice("acfhgiuo"))

    list_piezas = list(piezas)
    random.shuffle(list_piezas)
    for i in range(len(piezas)):
        if list_piezas[i] in "p" and random.randint(0, 2) == 0:
            list_piezas[i] = "q"
        elif list_piezas[i] in "q" and random.randint(0, 2) == 0:
            list_piezas[i] = "p"
        elif list_piezas[i] in "d" and random.randint(0, 2) == 0:
            list_piezas[i] = "b"
        elif list_piezas[i] in "b" and random.randint(0, 2) == 0:
            list_piezas[i] = "d"
        elif list_piezas[i] in "s" and random.randint(0, 2) == 0:
            list_piezas[i] = "z"
        elif list_piezas[i] in "z" and random.randint(0, 2) == 0:
            list_piezas[i] = "s"

    piezas = ''.join(list_piezas)

    case = {
        's': s,
        'piezas': piezas,
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
        testplan.write("")

    # Subtarea 1
    for i in range(10):
        puntos = 20 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            maxN=100000)

    # Subtarea 2
    for i in range(10):
        puntos = 10 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            maxN=10)

    with open('testplan', "a") as testplan:
        testplan.write("sub3.sample 0\n")

    # Subtarea 3
    for i in range(10):
        puntos = 70 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            maxN=100000)


if __name__ == "__main__":
    main()
