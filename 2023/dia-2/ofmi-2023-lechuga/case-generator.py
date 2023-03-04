import os
import random
import math

baseString = """
{N} {M}
{matriz}
""".strip(" \t\n\r")


def getRandomCase(sub, caseNumber):
    # Get dimensions
    MAXN = 1000 // random.randint(1, caseNumber + 1)
    N = random.randint(1, MAXN)
    M = random.randint(1, MAXN)
    if caseNumber == 0:
        N = 1000
        M = 1000
    matriz = [[0 for _ in range(M)] for _ in range(N)]

    # Get lettuce
    Lx = random.randint(0, N-1)
    Ly = random.randint(0, M-1)
    matriz[Lx][Ly] = -1  # Keep this cell

    # Fill matrix with cobayas
    MAXC = random.choice([int(math.sqrt(N*M)), N*M])
    cobayas = 0
    for _ in range(random.randint(1, MAXC)):
        i = random.randint(0, N-1)
        j = random.randint(0, M-1)
        if matriz[i][j] == 0:
            matriz[i][j] = 1
            cobayas += 1

    # Fill matrix with blocks
    MAXB = random.choice([int(math.sqrt(N*M)), N*M // 2,
                          N*M // 4, N*M // 8, N*M]) if sub != 1 else 0
    for _ in range(random.randint(0, MAXB)):
        i = random.randint(0, N-1)
        j = random.randint(0, M-1)
        if matriz[i][j] == 0:
            matriz[i][j] = -1

    # Fill lettuce
    matriz[Lx][Ly] = random.randint(2, min((N + M) * cobayas, 10**6))

    return {
        'N': N,
        'M': M,
        'matriz': '\n'.join(' '.join(map(str, row)) for row in matriz)
    }


subtasks = 2
pointsPerSub = [25, 75]
casesPerSub = [10, 20]


def main():
    random.seed(4123921)

    with open('testplan', 'w') as f:
        f.write("sub2.sample 0\n")
        f.write("sub2.sample1 0\n")
        f.write("sub2.sample2 0\n")

    for sub in range(1, subtasks + 1):
        casesInSub = casesPerSub[sub - 1]
        for caseNumber in range(casesInSub):
            # Generate case
            case = getRandomCase(sub, caseNumber)
            # Generate case file
            caseName = f'sub{sub}.{caseNumber}'
            caseString = baseString.format(**case)
            casePath = os.path.join('cases', caseName)
            with open(f'{casePath}.in', 'w') as f:
                f.write(f'{caseString}\n')
            # Append to testplan
            with open('testplan', 'a') as f:
                points = pointsPerSub[sub - 1] if caseNumber == 0 else 0
                f.write(f'{caseName} {points}\n')


if __name__ == '__main__':
    main()
