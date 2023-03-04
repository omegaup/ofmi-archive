import os
import random

baseString = """
{X} {L}
""".strip(" \t\n\r")

MAX = int(10**3)


def sub1():
    while True:
        yield {
            'X': random.randint(1, MAX),
            'L': 1,
        }


def sub2():
    while True:
        yield {
            'X': 1,
            'L': random.randint(1, MAX),
        }


def sub3():
    while True:
        yield {
            'X': random.randint(1, MAX),
            'L': random.randint(1, MAX),
        }


def sub4():
    for i in range(2):
        for j in range(2):
            yield {
                'X': i + 1,
                'L': j + 1,
            }
            yield {
                'X': MAX-i,
                'L': MAX-j,
            }
            yield {
                'X': i + 1,
                'L': MAX-j,
            }
            yield {
                'X': MAX-i,
                'L': j + 1,
            }
            yield {
                'X': MAX//2 + i,
                'L': MAX//2 + j,
            }

    yield {'X': MAX - 3, 'L': 5}
    yield {'X': 3, 'L': MAX - 1}
    yield {'X': 550, 'L': 774}
    yield {'X': 540, 'L': 550}
    yield {'X': 550, 'L': 1}

    for i in range(10, MAX, 10):
        yield {
            'X': i,
            'L': 1,
        }

    while True:
        yield {
            'X': random.randint(1, MAX),
            'L': random.randint(1, MAX),
        }


caseGenerators = [sub1(), sub2(), sub3(), sub4()]
casesPerSub = [10, 10, 10, 150]
pointsPerSub = [12, 12, 26, 50]

random.seed(4897921)

with open('testplan', 'w') as f:
    f.write('sub3.sample 0' + "\n")

for sub in range(1, 5):
    casesInSub = casesPerSub[sub - 1]
    for caseNumber in range(casesInSub):
        # Generate case
        case = next(caseGenerators[sub - 1])
        # Generate case file
        caseName = f'sub{sub}.{caseNumber}'
        caseString = baseString.format(**case)
        casePath = os.path.join('cases', caseName)
        with open(f'{casePath}.in', 'w') as f:
            f.write(f'{caseString}\n')
        # Append to testplan
        with open('testplan', 'a') as f:
            if caseNumber == 0:
                f.write(f'{caseName} {pointsPerSub[sub - 1]}\n')
            else:
                f.write(f'{caseName} 0\n')
