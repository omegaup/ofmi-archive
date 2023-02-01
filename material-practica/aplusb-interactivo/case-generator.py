import os
import random

baseString = """
{A} {B}
""".strip(" \t\n\r")

MAX = int(1000)


def getRandomCase():
    return {
        'A': random.randint(1, MAX),
        'B': random.randint(1, MAX),
    }


cases = 18
pointsPerCase = 5


def main():
    random.seed(3413517)

    with open('testplan', 'w') as f:
        f.write('sample 5' + "\n")
        f.write('sample1 5' + "\n")

    for caseNumber in range(cases):
        # Generate case
        case = getRandomCase()
        # Generate case file
        caseName = f'{caseNumber}'
        caseString = baseString.format(**case)
        casePath = os.path.join('cases', caseName)
        with open(f'{casePath}.in', 'w') as f:
            f.write(f'{caseString}\n')
        # Append to testplan
        with open('testplan', 'a') as f:
            points = pointsPerCase
            f.write(f'{caseName} {points}\n')


if __name__ == '__main__':
    main()
