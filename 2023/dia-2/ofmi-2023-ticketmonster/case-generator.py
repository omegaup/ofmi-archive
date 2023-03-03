import os
import random
import math

baseString = """
{N} {B} {R} {L}
{arr}
""".strip(" \t\n\r")


def greaterL(arr):
    return random.randint(max(arr) + 1, 1000)


def sub1(caseNumber):
    B = random.randint(0, 1000)
    arr = [random.randint(0, 999)]
    suma = sum(arr)
    R = random.randint(0, B)
    if caseNumber > 2:
        if B - R >= suma:
            R = B - suma + 1
    return {
        'N': 1,
        'B': B,
        'R': R,
        'L': greaterL(arr),
        'arr': arr,
    }


def sub2(caseNumber):
    N = random.randint(1, 1e5 if caseNumber < 5 else 1e3)
    B = random.randint(0, 1e5)
    arr = [random.randint(0, 999) for _ in range(N)]
    suma = sum(arr)
    R = random.randint(0, int(math.sqrt(B)))
    if B - R >= suma:
        R = B - suma + 1
    return {
        'N': N,
        'B': B,
        'R': R,
        'L': greaterL(arr),
        'arr': arr,
    }


def sub3(caseNumber):
    N = random.randint(1, 1e5 if caseNumber < 5 else 1e3)
    B = random.randint(0, 1e5)
    R = random.randint(0, int(math.sqrt(B)))
    arr = [random.randint(0, 1000) for _ in range(N)]
    s = sum(arr)
    while B - R <= s:
        i = random.randint(0, N - 1)
        s -= arr[i]
        arr[i] = random.randint(0, arr[i])
        s += arr[i]
    return {
        'N': N,
        'B': B,
        'R': R,
        'L': random.randint(0, 1000),
        'arr': arr,
    }


def sub4(caseNumber):
    N = random.randint(1, 1e5 if caseNumber < 5 else 1e3)
    B = random.randint(0, 1e5)
    return {
        'N': N,
        'B': B,
        'R': random.randint(0, int(math.sqrt(B))),
        'L': random.randint(0, 1000),
        'arr': [random.randint(1, 1000) for _ in range(N)],
    }


caseGenerators = [sub1, sub2, sub3, sub4]
pointsPerSub = [10, 15, 15, 59]


def main():
    random.seed(4897921)

    with open('testplan', 'w') as f:
        f.write('sample.sub4 1' + "\n")

    casesPerSub = 10
    for sub in range(1, 5):
        for i in range(casesPerSub):
            caseNumber = (sub - 1) * 10 + i
            # Generate case
            case = caseGenerators[sub - 1](i)
            case['arr'] = ' '.join([str(x) for x in case['arr']])
            # Generate case file
            caseName = f'sub{sub}_{caseNumber}'
            caseString = baseString.format(**case)
            casePath = os.path.join('cases', caseName)
            with open(f'{casePath}.in', 'w') as f:
                f.write(f'{caseString}\n')
            # Append to testplan
            with open('testplan', 'a') as f:
                points = pointsPerSub[sub - 1] // casesPerSub
                points += 1 if pointsPerSub[sub - 1] % casesPerSub > i else 0
                f.write(f'{caseName} {points}' + "\n")


if __name__ == '__main__':
    main()
